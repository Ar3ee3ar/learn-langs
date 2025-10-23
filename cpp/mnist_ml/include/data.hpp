// this is prototype

// header guard - sed to stop the compiler including the same code multiple times
// [in case of many function include this header]
// eg. function A , B is call C| function A is call B
//      (now in A call C 2 time and in C++ all file will convert to single program that will have C 2 time that can lead to error: redefinition of <code in C>)
#ifndef __DATA_H // check if DATA_H is not defined
#define __DATA_H // if not defined, define it now
// --------------

#include <vector>
#include "stdint.h"
#include "stdio.h"

// using namespace std;

class data
{
    std::vector<uint8_t> * feature_vector; // pointer to vector obj (address of vector) | feature_vector is a pointer to a vector that contain uint8_t (don't confuse with vector<uint8_t*> that is vector of address)
    uint8_t label;
    int enum_label; // map char to num e.g. A -> 1, B->2
    // eg.
    // enum type
    // {
    //     ONE = 0,
    //     TWO = 1,
    //     THREE = 2,
    //     ERROR = -99
    // };
    double distance;

public:
    data();
    ~data();
    void set_feature_vector(std::vector<uint8_t> *);
    void append_to_feature_vector(uint8_t);
    void set_label(uint8_t);
    void set_enumerated_label(int);

    int get_feature_vector_size();
    uint8_t get_label();
    uint8_t get_enumerated_label();

    void set_distance(double);
    double get_distance();


    std::vector<uint8_t> *get_feature_vector();
};

#endif