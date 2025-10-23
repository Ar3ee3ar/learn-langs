#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef __DATA_HANDLER_H
#define __DATA_HANDLER_H

#include <fstream> // to read file
#include <cstdio> // required for FILE and fopen_s
#include "stdint.h"
#include "data.hpp"
#include <vector>
#include <string>
#include <map>
#include <unordered_set> // unordered stored, fast access, can't updating element
#include <errno.h> // for error report
#include <algorithm> // algorithm for random
#include <random>

class data_handler
{
    std::vector<data *> * data_array; // pointer (*data_array) point to the vector containing pointers(std::vector<data*>)
    std::vector<data *> * training_data;
    std::vector<data *> * test_data;
    std::vector<data *> * validation_data;

    int num_classes;
    int feature_vector_size;
    std::map<uint8_t, int> class_map; // map<key_type, value_type>

    const double TRAIN_SET_PERCENT = 0.75;
    const double TEST_SET_PERCENT = 0.20;
    const double VALIDATION_SET_PERCENT = 0.05;

    public:
        data_handler(); // constructor: assign value on call class
        ~data_handler(); // deconstructor: destroy value on finish work of class (up to user implement)

        void read_feature_vector(std::string path);
        void read_feature_labels(std::string path);
        void split_data();
        void count_classes();

        uint32_t convert_to_little_endian(const unsigned char* bytes);

        std::vector<data *> *get_training_data();
        std::vector<data *> *get_test_data();
        std::vector<data *> *get_validation_data();
};

#endif