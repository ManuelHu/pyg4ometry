#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

#include <Standard_Failure.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Version.hxx>

/*********************************************
PYBIND
*********************************************/
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true)

PYBIND11_MODULE(Standard, m) {
  static py::exception<Standard_Failure> exc(m, "Standard_Failure");
  py::register_exception_translator([](std::exception_ptr p) {
    try {
      if (p)
        std::rethrow_exception(p);
    } catch (const Standard_Failure &e) {
#if OCC_VERSION_HEX >= 0x080000
      // GetMessageString() is deprecated since OCCT 8.0
      const char *message = e.what();
#else
      const char *message = e.GetMessageString();
#endif
#if defined(PYBIND11_VERSION_HEX) && PYBIND11_VERSION_HEX >= 0x020C0000
      // calling the exception object is deprecated since pybind11 2.12
      py::set_error(exc, message);
#else
      exc(message);
#endif
    }
  });
}
