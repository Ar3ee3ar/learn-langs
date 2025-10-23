// #include "data.hpp" // can use this too, but vs code will show error message
#include "../include/data.hpp"

data::data()
{
    feature_vector = new std::vector<uint8_t>;
}

data::~data()
{
    
}

void data::set_feature_vector(std::vector<uint8_t> *vect)
{
    feature_vector = vect;
}
void data::append_to_feature_vector(uint8_t val)
{
    feature_vector->push_back(val);
}
void data::set_label(uint8_t val)
{
    label = val;
}
void data::set_enumerated_label(int val)
{
    // enum Level
    // {
    //     LOW,
    //     MEDIUM,
    //     HIGH
    // };
    enum_label = val; // in mnist label is int value. In other case can set value as group 
}

/*
static int toint(MyIdentifier::type val)
    {
        switch (val)
        {
            case ONE:
                return 0;
            case TWO:
                return 1;
            case THREE:
                return 2;
            default:
                return -99;
        }
    }
    static enum MyIdentifier::type fromint(int val)
    {
        switch (val)
        {
        case 0:
            return ONE;
        case 1:
            return TWO;
        case 2:
            return THREE;
        default:
            return ERROR;
        }
    }
*/

int data::get_feature_vector_size()
{
    return feature_vector->size();
}
uint8_t data::get_label()
{
    return label;
}
uint8_t data::get_enumerated_label()
{
    return enum_label;
}

void data::set_distance(double val)
{
    distance = val;
}
double data::get_distance()
{
    return distance;
}

std::vector<uint8_t> *data::get_feature_vector()
{
    return feature_vector;
}

/*
int in_value = 0;
    MyIdentifier *mi = new MyIdentifier();
    while(in_value != -1)
    {
        std::cout << "Type your number: ";
        std::cin >> in_value;
        // MyIdentifier::type int_val = mi->fromint(0);
        // switch (mi->fromint(std::stoi(in_value)))
        switch (mi->fromint(in_value))
        {
        case MyIdentifier::ONE:
            std::cout << 0 << std::endl;
            break;
        case MyIdentifier::TWO:
            std::cout << 1 << std::endl;
            break;
        case MyIdentifier::THREE:
            std::cout << 2 << std::endl;
            break;
        default:
            std::cout << -99 << std::endl;
        }
    }
*/