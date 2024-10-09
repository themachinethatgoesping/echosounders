// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pytensor.hpp>                 // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp>
#include <themachinethatgoesping/echosounders/kongsbergall/filedatatypes/calibration/kongsbergallwatercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_calibration {

namespace py = pybind11;

#define DOC_MultiSectorWaterColumnCalibration(ARG)                                                 \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datatypes,                                                                                 \
        calibration,                                                                               \
        MultiSectorWaterColumnCalibration,                                                         \
        ARG)

template<typename t_calibration, typename t_float, typename t_pyclass>
void add_apply_calibration_functions(t_pyclass& c)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    c.def("apply_beam_sample_correction_av",
          &MultiSectorWaterColumnCalibration<
              t_calibration>::template apply_beam_sample_correction_av<xt::pytensor<t_float, 2>,
                                                                       xt::pytensor<t_float, 1>>,
          DOC_MultiSectorWaterColumnCalibration(apply_beam_sample_correction_av),
          py::arg("wci"),
          py::arg("beam_angles"),
          py::arg("ranges"),
          py::arg("beam_numbers_per_tx_sector"));

    c.def("apply_beam_sample_correction_av2",
          &MultiSectorWaterColumnCalibration<
              t_calibration>::template apply_beam_sample_correction_av2<xt::pytensor<t_float, 2>,
                                                                        xt::pytensor<t_float, 1>>,
          DOC_MultiSectorWaterColumnCalibration(apply_beam_sample_correction_av2),
          py::arg("wci"),
          py::arg("beam_angles"),
          py::arg("ranges"),
          py::arg("beam_numbers_per_tx_sector"));
    c.def("apply_beam_sample_correction_av3",
          &MultiSectorWaterColumnCalibration<
              t_calibration>::template apply_beam_sample_correction_av3<xt::pytensor<t_float, 2>,
                                                                        xt::pytensor<t_float, 1>>,
          DOC_MultiSectorWaterColumnCalibration(apply_beam_sample_correction_av3),
          py::arg("wci"),
          py::arg("beam_angles"),
          py::arg("ranges"),
          py::arg("beam_numbers_per_tx_sector"));
}

template<typename t_calibration>
void init_multisectorwatercolumncalibration(pybind11::module& m, const std::string& name)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    // add class
    auto c = py::class_<MultiSectorWaterColumnCalibration<t_calibration>,
                        std::shared_ptr<MultiSectorWaterColumnCalibration<t_calibration>>>(
                 m,
                 name.c_str(),
                 DOC(themachinethatgoesping,
                     echosounders,
                     filetemplates,
                     datatypes,
                     calibration,
                     MultiSectorWaterColumnCalibration))
                 .def(py::init<>(),
                      DOC_MultiSectorWaterColumnCalibration(MultiSectorWaterColumnCalibration))
                 .def(py::init<std::vector<t_calibration>>(),
                      DOC_MultiSectorWaterColumnCalibration(MultiSectorWaterColumnCalibration),
                      py::arg("calibration_per_sector"))

                 // --- getters / setters ---

                 .def("get_number_of_sectors",
                      &MultiSectorWaterColumnCalibration<t_calibration>::get_number_of_sectors,
                      DOC_MultiSectorWaterColumnCalibration(get_number_of_sectors))
                 .def("size",
                      &MultiSectorWaterColumnCalibration<t_calibration>::size,
                      DOC_MultiSectorWaterColumnCalibration(size))
                 .def("empty",
                      &MultiSectorWaterColumnCalibration<t_calibration>::empty,
                      DOC_MultiSectorWaterColumnCalibration(empty))
                 .def("__len__",
                      &MultiSectorWaterColumnCalibration<t_calibration>::size,
                      DOC_MultiSectorWaterColumnCalibration(size))

                 .def("get_calibrations",
                      &MultiSectorWaterColumnCalibration<t_calibration>::get_calibrations,
                      DOC_MultiSectorWaterColumnCalibration(get_calibrations))

                 // ----- operators -----
                 .def("__eq__",
                      &MultiSectorWaterColumnCalibration<t_calibration>::operator==,
                      DOC_MultiSectorWaterColumnCalibration(operator_eq),
                      py::arg("other"))
             // ----- pybind macros -----
             // default copy functions
             __PYCLASS_DEFAULT_COPY__(MultiSectorWaterColumnCalibration<t_calibration>)
             // default binary functions
             __PYCLASS_DEFAULT_BINARY__(MultiSectorWaterColumnCalibration<t_calibration>)
             // default printing functions
             __PYCLASS_DEFAULT_PRINTING__(MultiSectorWaterColumnCalibration<t_calibration>)
        // end MultiSectorWaterColumnCalibration
        ;

    // add apply calibration functions
    add_apply_calibration_functions<t_calibration, float>(c);
    add_apply_calibration_functions<t_calibration, double>(c);

    c.def("cached_hash",
          &MultiSectorWaterColumnCalibration<t_calibration>::cached_hash,
          DOC_MultiSectorWaterColumnCalibration(cached_hash));
    c.def("hash",
          &MultiSectorWaterColumnCalibration<t_calibration>::cached_hash,
          DOC_MultiSectorWaterColumnCalibration(cached_hash));
    c.def("__hash__",
          &MultiSectorWaterColumnCalibration<t_calibration>::cached_hash,
          DOC_MultiSectorWaterColumnCalibration(cached_hash));
}

void init_c_multisectorwatercolumncalibration(pybind11::module& m)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
    using namespace themachinethatgoesping::echosounders::kongsbergall::filedatatypes::calibration;

    init_multisectorwatercolumncalibration<WaterColumnCalibration>(
        m, "MultiSectorWaterColumnCalibration");
    init_multisectorwatercolumncalibration<KongsbergAllWaterColumnCalibration>(
        m, "KongsbergAllMultiSectorWaterColumnCalibration");
}

}
}
}
}
}
}