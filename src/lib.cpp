#include <pybind11/buffer_info.h>
#include <pybind11/detail/common.h>
#include <pybind11/pybind11.h>
#include <pybind11/pytypes.h>
#include <pyerrors.h>

#include <cstddef>
#include <cstdint>

using namespace std;
namespace py = pybind11;

PYBIND11_MODULE(imglib, m) {
    m.doc() = "Zero out bottom bits for a cool effect.";
    m.def("change_image", [](py::object im) {
        try {
            py::buffer buf(im.attr("tobytes")());
            py::buffer_info info = buf.request();
            auto *bufptr = static_cast<uint8_t *>(info.ptr);
            for (size_t i = 0; i < info.size; ++i) {
                // Zero out bottom bits
                bufptr[i] &= 0x80;
            }
            im.attr("frombytes")(buf);
        } catch (py::error_already_set &e) {
            if (e.matches(PyExc_AttributeError)) {
                throw py::value_error("invalid argument: not a PIL Image");
            } else
                throw;
        }
        return;
    });
}
