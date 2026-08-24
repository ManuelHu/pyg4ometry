#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>

/*********************************************
PYBIND
*********************************************/
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true)

PYBIND11_MODULE(TCollection, m) {
  py::class_<TCollection_AsciiString>(m, "TCollection_AsciiString")
      .def(py::init<>())
      .def(py::init<const char *>())
      .def(py::init<const char *, const int>())
      .def(py::init<const char>())
      .def(py::init<const int, const char>())
      .def(py::init<const int>())
      .def(py::init<const double>())
      .def(py::init<const TCollection_AsciiString &>())
      .def("ToCString", &TCollection_AsciiString::ToCString);

  py::class_<TCollection_ExtendedString>(m, "TCollection_ExtendedString")
      .def(py::init<>())
      .def(py::init<const char *, const bool>())
      .def(py::init<const char16_t *>())
      .def(py::init<const char>())
      .def(py::init<const char16_t>())
      .def(py::init<const int, const char16_t>())
      .def(py::init<const int>())
      .def(py::init<const double>())
      .def(py::init<const TCollection_ExtendedString>())
      .def(py::init<const TCollection_AsciiString &>())
      .def("Length", &TCollection_ExtendedString::Length)
      .def("Print",
           [](TCollection_ExtendedString &string) {
             py::scoped_ostream_redirect output;
             string.Print(std::cout);
           })
      .def("ToExtString", &TCollection_ExtendedString::ToExtString);
}
