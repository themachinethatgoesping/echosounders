// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallpingcommon.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper/defaultsharedpointermap.hpp>


#include "../../filetemplates/datatypes/datagraminfo.hpp"
#include "../../filetemplates/datatypes/i_pingcommon.hpp"
#include "../datagrams.hpp"

#include "kongsbergallpingfiledata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {

template<typename t_ifstream>
class KongsbergAllPingCommon
{
  protected:
    std::string class_name() const { return "KongsbergAllPingCommon"; }
    // raw data
    using t_rawdata                       = KongsbergAllPingFileData<t_ifstream>;
    std::shared_ptr<t_rawdata> _file_data = std::make_shared<t_rawdata>();

  public:
    KongsbergAllPingCommon()
    {
    }
    KongsbergAllPingCommon(std::shared_ptr<t_rawdata> file_data)
        : _file_data(std::move(file_data))
    {
    }
    virtual ~KongsbergAllPingCommon() = default;


    const t_rawdata& file_data() const { return *_file_data; }
    t_rawdata&       file_data() { return *_file_data; }
    void set_file_data(std::shared_ptr<t_rawdata> file_data) { _file_data = std::move(file_data); }

    // ----- objectprinter -----
    // tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    // {
    //     tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

    //     return printer;
    // }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping