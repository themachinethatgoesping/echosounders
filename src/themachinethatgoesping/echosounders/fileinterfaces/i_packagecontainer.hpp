// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_Value>
using T_PackageContainer = std::vector<std::shared_ptr<t_Value>>;

template<typename t_Value>
class I_PackageContainer
{
  protected:
    std::string _name;

    T_PackageContainer<t_Value> _packages;
    tools::pyhelper::PyIndexer  _pyindexer;

  public:
    /**
     * @brief Construct a new empty Container object
     *
     */
    I_PackageContainer(std::string_view name = "Default")
        : _name(name)
        , _pyindexer(0)
    {
    }

    /**
     * @brief Construct a new Container object from a vector of packages
     *
     * @param packages: vector of t_Value
     */
    I_PackageContainer(T_PackageContainer<t_Value> packages, std::string_view name = "Default")
        : _name(name)
        , _packages(std::move(packages))
        , _pyindexer(_packages.size())
    {
    }

    virtual ~I_PackageContainer() = default;

  protected:
    void add_package(std::shared_ptr<t_Value> package)
    {
        this->_packages.push_back(std::move(package));
        this->_pyindexer.reset(this->_packages.size());
    }

    void add_packages(const T_PackageContainer<t_Value>& packages)
    {
        this->_packages.insert(this->_packages.end(), packages.begin(), packages.end());
        this->_pyindexer.reset(this->_packages.size());
    }

    void set_packages(T_PackageContainer<t_Value> packages)
    {
        _packages = std::move(packages);
        _pyindexer.reset(_packages.size());
    }

    const T_PackageContainer<t_Value>& get_packages() const { return _packages; }

    // ----- compute container information -----

    // ----- iterator interface -----

  public:
    I_PackageContainer<t_Value> reversed() const
    {
        return this->operator()(_pyindexer.reversed().to_slice());
    }

    I_PackageContainer<t_Value> operator()(const tools::pyhelper::PyIndexer::Slice& slice) const
    {
        I_PackageContainer<t_Value> sliced_container(*this);

        tools::pyhelper::PyIndexer pyindexer(_packages.size(), slice);

        T_PackageContainer<t_Value> packages;
        packages.reserve(pyindexer.size());

        for (size_t i : pyindexer)
        {
            packages.push_back(_packages[i]);
        }

        sliced_container.set_packages(std::move(packages));

        return sliced_container;
    }

    // -- functions that assume t_Value to have a get_timestamp() function
    std::vector<I_PackageContainer<t_Value>> break_by_time_diff(double max_time_diff_seconds) const
    {
        std::vector<I_PackageContainer<t_Value>> containers;

        T_PackageContainer<t_Value> packages;

        for (const auto& ping : _packages)
        {
            if (!packages.empty())
            {
                if (ping->get_timestamp() - packages.back()->get_timestamp() >
                    max_time_diff_seconds)
                {
                    containers.push_back(I_PackageContainer<t_Value>(packages));
                    packages = T_PackageContainer<t_Value>();
                }
            }
            packages.push_back(ping);
        }

        containers.push_back(I_PackageContainer<t_Value>(packages));

        return containers;
    }

    // sort _datagram_infos_all by timestamp in _datagram_timestamps
    I_PackageContainer<t_Value> get_sorted_by_time() const
    {
        I_PackageContainer<t_Value> sorted(*this);
        // Your function
        auto& packages = sorted._packages;
        // sort _datagram_infos_all by  time, then file_pos then file number
        // TODO: this is faster than std sort, but python sorting (timsort?) seems
        // to be 10x faster for this use case
        boost::sort::pdqsort(
            packages.begin(), packages.end(), [](const auto& lhs, const auto& rhs) {
                if (lhs->get_timestamp() < rhs->get_timestamp())
                    return true;
                return false;
            });

        return sorted;
    }

    size_t size() const { return _pyindexer.size(); }

    const t_Value& at(long index) const { return *_packages[_pyindexer(index)]; }

    // ----- common info functions -----

    /**
     * @brief Compute some time statistics for the packages in the container
     * The is_sorted variable is interpreted as follos:
     *  - 1: the packages are sorted by time (ascending)
     *  - 0: the packages are not sorted by time
     * - -1: the packages are sorted by time (descending)
     *
     * @return std::tuple<min_timestamp, max_timestamp, is_sorted()>
     */
    std::tuple<double, double, int> timeinfo() const
    {
        double min_time  = std::numeric_limits<double>::max();
        double max_time  = std::numeric_limits<double>::min();
        int    is_sorted = 1;

        for (size_t i : _pyindexer)
        {
            const auto& ping = _packages[i];
            min_time         = std::min(min_time, ping->get_timestamp());
            max_time         = std::max(max_time, ping->get_timestamp());

            if (i > 1)
            {
                if (is_sorted == 1)
                {
                    if (ping->get_timestamp() < _packages[i - 1]->get_timestamp())
                        is_sorted = 0;
                }
                else if (is_sorted == -1)
                {
                    if (ping->get_timestamp() > _packages[i - 1]->get_timestamp())
                        is_sorted = 0;
                }
            }
            else if (i == 1)
            {
                if (ping->get_timestamp() < _packages[i - 1]->get_timestamp())
                    is_sorted = -1;
            }
        }

        return std::make_tuple(min_time, max_time, is_sorted);
    }

    double get_max_timestamp() const
    {
        double max_time = std::numeric_limits<double>::lowest();
        for (size_t i : _pyindexer)
            max_time = std::max(max_time, _packages[i]->get_timestamp());

        return max_time;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         only_time_info = false) const
    {
        tools::classhelper::ObjectPrinter printer("I_PackageContainer", float_precision);

        printer.register_section("Time info");
        double min_time, max_time;
        int    is_sorted;
        std::tie(min_time, max_time, is_sorted) = timeinfo();
        std::string is_sorted_str               = is_sorted == 1    ? "ascending"
                                                  : is_sorted == -1 ? "descending"
                                                                    : "no";
        std::string time_str_min =
            tools::timeconv::unixtime_to_datestring(min_time, 2, "%d/%m/%Y %H:%M:%S");
        std::string time_str_max =
            tools::timeconv::unixtime_to_datestring(max_time, 2, "%d/%m/%Y %H:%M:%S");
        printer.register_value("Start time", time_str_min);
        printer.register_value("End time", time_str_max);
        printer.register_value("Sorted", is_sorted_str);

        if (only_time_info)
            return printer;

        printer.register_section("Contained packages");
        if (channel_ids.size() > 1)
            printer.register_value("Total", size());

        return printer;
    }

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping