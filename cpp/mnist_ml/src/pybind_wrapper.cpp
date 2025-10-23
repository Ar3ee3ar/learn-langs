#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // for std::vector
#include "data_handler.hpp"
// #include "knn.hpp"

namespace py = pybind11;

PYBIND11_MODULE(libdata, m)
{
    // data_handler class
    py::class_<data_handler>(m, "DataHandler")
        .def(py::init<>())
        .def("read_feature_vector", &data_handler::read_feature_vector)
        .def("read_feature_labels", &data_handler::read_feature_labels)
        .def("split_data", &data_handler::split_data)
        .def("count_classes", &data_handler::count_classes)
        .def("get_training_data", &data_handler::get_training_data)
        .def("get_test_data", &data_handler::get_test_data)
        .def("get_validation_data", &data_handler::get_validation_data);

    // knn class
    // py::class_<knn>(m, "KNN")
    //     .def(py::init<>())
    //     .def(py::init<int>())
    //     .def("set_training_data", &knn::set_training_data)
    //     .def("set_test_data", &knn::set_test_data)
    //     .def("set_validation_data", &knn::set_validation_data)
    //     .def("set_k", &knn::set_k)
    //     .def("predict", &knn::predict)
    //     .def("find_knearest", &knn::find_knearest)
    //     .def("calculate_distance", &knn::calculate_distance)
    //     .def("validation_performance", &knn::validation_performance)
    //     .def("test_performance", &knn::test_performance);
}
