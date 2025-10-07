// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/stl/string.h>
#include <nanobind/stl/optional.h>

// xtensor python includes
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp>
#include <themachinethatgoesping/echosounders/kongsbergall/filedatatypes/calibration/kongsbergallwatercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_calibration {

namespace nb = nanobind;

#define DOC_I_MultiSectorCalibration(ARG)                                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datatypes,                                                                                 \
        calibration,                                                                               \
        I_MultiSectorCalibration,                                                                  \
        ARG)

#define DOC_T_MultiSectorCalibration(ARG)                                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datatypes,                                                                                 \
        calibration,                                                                               \
        T_MultiSectorCalibration,                                                                  \
        ARG)

template<typename t_calibration, typename t_float, typename t_pyclass>
void add_apply_calibration_functions(t_pyclass& c)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    c.def("apply_beam_sample_correction_power",
          &T_MultiSectorCalibration<t_calibration>::template apply_beam_sample_correction<
              t_calibration::t_calibration_type::power,
              xt::nanobind::pytensor<t_float, 2>,
              xt::nanobind::pytensor<t_float, 1>>,
          DOC_I_MultiSectorCalibration(apply_beam_sample_correction),
          nb::arg("wci"),
          nb::arg("beam_angles"),
          nb::arg("ranges"),
          nb::arg("beam_numbers_per_tx_sector"),
          nb::arg("mp_cores") = 1);
    c.def("apply_beam_sample_correction_pp",
          &T_MultiSectorCalibration<t_calibration>::template apply_beam_sample_correction<
              t_calibration::t_calibration_type::pp,
              xt::nanobind::pytensor<t_float, 2>,
              xt::nanobind::pytensor<t_float, 1>>,
          DOC_I_MultiSectorCalibration(apply_beam_sample_correction),
          nb::arg("wci"),
          nb::arg("beam_angles"),
          nb::arg("ranges"),
          nb::arg("beam_numbers_per_tx_sector"),
          nb::arg("mp_cores") = 1);
    c.def("apply_beam_sample_correction_pv",
          &T_MultiSectorCalibration<t_calibration>::template apply_beam_sample_correction<
              t_calibration::t_calibration_type::pv,
              xt::nanobind::pytensor<t_float, 2>,
              xt::nanobind::pytensor<t_float, 1>>,
          DOC_I_MultiSectorCalibration(apply_beam_sample_correction),
          nb::arg("wci"),
          nb::arg("beam_angles"),
          nb::arg("ranges"),
          nb::arg("beam_numbers_per_tx_sector"),
          nb::arg("mp_cores") = 1);
    c.def("apply_beam_sample_correction_ap",
          &T_MultiSectorCalibration<t_calibration>::template apply_beam_sample_correction<
              t_calibration::t_calibration_type::ap,
              xt::nanobind::pytensor<t_float, 2>,
              xt::nanobind::pytensor<t_float, 1>>,
          DOC_I_MultiSectorCalibration(apply_beam_sample_correction),
          nb::arg("wci"),
          nb::arg("beam_angles"),
          nb::arg("ranges"),
          nb::arg("beam_numbers_per_tx_sector"),
          nb::arg("mp_cores") = 1);
    c.def("apply_beam_sample_correction_av",
          &T_MultiSectorCalibration<t_calibration>::template apply_beam_sample_correction<
              t_calibration::t_calibration_type::av,
              xt::nanobind::pytensor<t_float, 2>,
              xt::nanobind::pytensor<t_float, 1>>,
          DOC_I_MultiSectorCalibration(apply_beam_sample_correction),
          nb::arg("wci"),
          nb::arg("beam_angles"),
          nb::arg("ranges"),
          nb::arg("beam_numbers_per_tx_sector"),
          nb::arg("mp_cores") = 1);
    c.def("apply_beam_sample_correction_sp",
          &T_MultiSectorCalibration<t_calibration>::template apply_beam_sample_correction<
              t_calibration::t_calibration_type::sp,
              xt::nanobind::pytensor<t_float, 2>,
              xt::nanobind::pytensor<t_float, 1>>,
          DOC_I_MultiSectorCalibration(apply_beam_sample_correction),
          nb::arg("wci"),
          nb::arg("beam_angles"),
          nb::arg("ranges"),
          nb::arg("beam_numbers_per_tx_sector"),
          nb::arg("mp_cores") = 1);
    c.def("apply_beam_sample_correction_sv",
          &T_MultiSectorCalibration<t_calibration>::template apply_beam_sample_correction<
              t_calibration::t_calibration_type::sv,
              xt::nanobind::pytensor<t_float, 2>,
              xt::nanobind::pytensor<t_float, 1>>,
          DOC_I_MultiSectorCalibration(apply_beam_sample_correction),
          nb::arg("wci"),
          nb::arg("beam_angles"),
          nb::arg("ranges"),
          nb::arg("beam_numbers_per_tx_sector"),
          nb::arg("mp_cores") = 1);

    c.def("inplace_beam_sample_correction_av",
          &T_MultiSectorCalibration<t_calibration>::template inplace_beam_sample_correction<
              t_calibration::t_calibration_type::av,
              xt::nanobind::pytensor<t_float, 2>,
              xt::nanobind::pytensor<t_float, 1>>,
          DOC_I_MultiSectorCalibration(inplace_beam_sample_correction),
          nb::arg("wci"),
          nb::arg("beam_angles"),
          nb::arg("ranges"),
          nb::arg("beam_numbers_per_tx_sector"),
          nb::arg("mp_cores") = 1);
}

template<typename t_calibration>
void init_multisectorcalibration(nanobind::module_& m, const std::string& name)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    // add class
    auto c = nb::class_<T_MultiSectorCalibration<t_calibration>>(m,
                                                                 name.c_str(),
                                                                 DOC(themachinethatgoesping,
                                                                     echosounders,
                                                                     filetemplates,
                                                                     datatypes,
                                                                     calibration,
                                                                     T_MultiSectorCalibration))
                 .def(nb::init<>(), DOC_T_MultiSectorCalibration(T_MultiSectorCalibration))
                 .def(nb::init<std::vector<t_calibration>>(),
                      DOC_T_MultiSectorCalibration(T_MultiSectorCalibration),
                      nb::arg("calibration_per_sector"))
                 .def(nb::init<const T_MultiSectorCalibration<t_calibration>&>(),
                      DOC_T_MultiSectorCalibration(T_MultiSectorCalibration),
                      nb::arg("other"))

                 // --- getters / setters ---
                 .def("has_power_calibration",
                      &T_MultiSectorCalibration<t_calibration>::has_power_calibration,
                      DOC_I_MultiSectorCalibration(has_power_calibration))
                 .def("has_ap_calibration",
                      &T_MultiSectorCalibration<t_calibration>::has_ap_calibration,
                      DOC_I_MultiSectorCalibration(has_ap_calibration))
                 .def("has_av_calibration",
                      &T_MultiSectorCalibration<t_calibration>::has_av_calibration,
                      DOC_I_MultiSectorCalibration(has_av_calibration))
                 .def("has_sp_calibration",
                      &T_MultiSectorCalibration<t_calibration>::has_sp_calibration,
                      DOC_I_MultiSectorCalibration(has_sp_calibration))
                 .def("has_sv_calibration",
                      &T_MultiSectorCalibration<t_calibration>::has_sv_calibration,
                      DOC_I_MultiSectorCalibration(has_sv_calibration))
                 .def("has_valid_absorption_db_m",
                      &T_MultiSectorCalibration<t_calibration>::has_valid_absorption_db_m,
                      DOC_I_MultiSectorCalibration(has_valid_absorption_db_m))

                 .def("get_number_of_sectors",
                      &T_MultiSectorCalibration<t_calibration>::get_number_of_sectors,
                      DOC_I_MultiSectorCalibration(get_number_of_sectors))
                 .def("__len__",
                      &T_MultiSectorCalibration<t_calibration>::get_number_of_sectors,
                      DOC_I_MultiSectorCalibration(get_number_of_sectors))

                 .def("get_calibrations",
                      &T_MultiSectorCalibration<t_calibration>::get_calibrations,
                      DOC_T_MultiSectorCalibration(get_calibrations))

                 // ----- operators -----
                 .def("__eq__",
                      &T_MultiSectorCalibration<t_calibration>::operator==,
                      DOC_I_MultiSectorCalibration(operator_eq),
                      nb::arg("other"))
             // ----- pybind macros -----
             // default copy functions
             __PYCLASS_DEFAULT_COPY__(T_MultiSectorCalibration<t_calibration>)
             // default binary functions
             __PYCLASS_DEFAULT_BINARY__(T_MultiSectorCalibration<t_calibration>)
             // default printing functions
             __PYCLASS_DEFAULT_PRINTING__(T_MultiSectorCalibration<t_calibration>)
        // end T_MultiSectorCalibration
        ;

    // add apply calibration functions
    add_apply_calibration_functions<t_calibration, float>(c);
    add_apply_calibration_functions<t_calibration, double>(c);
}

void init_c_multisectorwatercolumncalibration(nanobind::module_& m)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
    using namespace themachinethatgoesping::echosounders::kongsbergall::filedatatypes::calibration;

    init_multisectorcalibration<WaterColumnCalibration>(m, "MultiSectorWaterColumnCalibration");
    init_multisectorcalibration<KongsbergAllWaterColumnCalibration>(
        m, "KongsbergAllMultiSectorWaterColumnCalibration");
}

}
}
}
}
}
}