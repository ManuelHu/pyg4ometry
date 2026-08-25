#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

#include <BRepPrimAPI_MakeBox.hxx>

/*********************************************
PYBIND
*********************************************/
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true)

PYBIND11_MODULE(BRepPrimAPI, m) {
  py::class_<BRepPrimAPI_MakeBox, BRepBuilderAPI_MakeShape>(
      m, "BRepPrimAPI_MakeBox")
      .def(py::init<>())
      .def(py::init<const double, const double, const double>())
      .def(py::init<const gp_Pnt &, const double, const double, const double>())
      .def(py::init<const gp_Pnt &, const gp_Pnt &>());
  //.def(py::init<const gp_Ax2 &, const double, const double,
  // const double>); // TODO
}
