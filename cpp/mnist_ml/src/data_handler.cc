// #include <pybind11/pybind11.h>
#include "../include/data_handler.hpp"
#include <algorithm>

data_handler::data_handler()
{
    data_array = new std::vector<data *>; // vector of pointer with data dataType
    test_data = new std::vector<data *>;
    training_data = new std::vector<data *>;
    validation_data = new std::vector<data *>;
}
data_handler::~data_handler()
{
    // FREE Dynamically Allocation
}

void data_handler::read_feature_vector(std::string path) // read feature (detail of image)
{
    uint32_t header[4]; // |MAGIC |NUM IMAGES |ROWSIZE |COLSIZE 
    unsigned char bytes[4];
    FILE *f = fopen(path.c_str(), "rb"); // read file from provided path
    if(f) // if found content in file
    {
        for(int i=0; i<4; i++) // feature have 4 column
        {
            if(fread(bytes, sizeof(bytes), 1, f)) // check  size of each column and stored in bytes variable
            {
                header[i] = convert_to_little_endian(bytes); // convert to little endian type

            }
        }
        printf("Done getting Input File Header.\n");
        int image_size = header[2]*header[3]; // image_size is come from col[2] row image multiply with col[3] col image
        for(int i=0; i<header[1]; i++) // loop by count of image (all row is count as all image)
        {
            data *d = new data(); // create pointer point to class
            uint8_t element[1]; // create variable 
            for(int j=0; j<image_size; j++) // read all bit in image by image size
            {
                if(fread(element, sizeof(element), 1, f)) // read data in element variable
                {
                    d->append_to_feature_vector(element[0]); // use pointer d to read data (append to vector of int)
                }
                else
                {
                    printf("Error reading from File.\n");
                    exit(1);
                }
            }
            data_array->push_back(d); // push data into data array (vector that stored pointer to address of vector of int)
            // printf("feature size: %d.\n", d->get_feature_vector_size());
        }
        printf("Successfully read and stored %lu feature vector.\n", data_array->size());
    }else
    {
        printf("Could not find file.\n");
        exit(1);
    }
}
void data_handler::read_feature_labels(std::string path)
{
    uint32_t header[2]; // |MAGIC |NUM IMAGES
    unsigned char bytes[4]; // 
    FILE *f = fopen(path.c_str(), "rb");
    if (f)
    {
        for (int i = 0; i < 2; i++) // label have 2 column
        {
            if (fread(bytes, sizeof(bytes), 1, f))
            {
                header[i] = convert_to_little_endian(bytes);
            }
        }
        printf("Done getting Label File Header.\n");
        printf("%d\n", header[1]);
        printf("%d\n",data_array->size());
        for (int i = 0; i < header[1]; i++)
        {
            // data *d = new data();
            uint8_t element[1];
            // printf("data array: %d\n", data_array->at(i));
            if (fread(element, sizeof(element), 1, f))
            {
                data_array->at(i)->set_label(element[0]); // read label of data
            }
            else
            {
                printf("Error reading from File.\n");
                exit(1);
            }

        }
        printf("Successfully read and stored label.\n");
    }
    else
    {
        printf("Could not find file.\n");
        exit(1);
    }
}
void data_handler::split_data()
{
    printf("Start split data.\n");
    std::unordered_set<int> used_indexes;
    int train_size = data_array->size() * TRAIN_SET_PERCENT;
    int test_size = data_array->size() * TEST_SET_PERCENT;
    int valid_size = data_array->size() * VALIDATION_SET_PERCENT;
    std::vector<int> index_data; // vector use for stored all index of data
    for (int i = 0; i < data_array->size(); i++)
    {
        index_data.push_back(i); // use . because address to vector<int>
    }
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 g(rd());
    // shuffle the vector
    std::shuffle(index_data.begin(), index_data.end(), g);
    std::vector<int> train_index(index_data.begin(), index_data.begin() + train_size); // select from [0, train_size]
    std::vector<int> test_index(index_data.begin() + train_size, index_data.begin() + train_size + test_size); // select from [train_size, count to test_size]
    std::vector<int> valid_index(index_data.begin() + train_size + test_size, index_data.end()); // from [count to test_size, end]
    // Training data
    int count = 0;
    // printf("Train set: %d.\nTest set: %d.\n Val test: %d.\n",train_size, test_size, valid_size);
    for(int num:  train_index) // loop through index of train data
    {
        // int rand_index = rand() % data_array->size(); // 0 <= rand_index <= (data_array->size() - 1)
        // printf("%d.\n", rand_index);
        // if(used_indexes.find(rand_index) == used_indexes.end())
        // {
        training_data->push_back(data_array->at(num)); // use -> because pointer point to vector<data> | push index of data into training_data vector of pointer
        // used_indexes.insert(rand_index);
        // count++;
        // }
        // printf("%d.\n", count);
    }
    printf("Successfully split training data");

    // Validation data
    count = 0;
    // while (count < valid_size)
    for (int num : valid_index)
    {
        // int rand_index = rand() % data_array->size();
        // if (used_indexes.find(rand_index) == used_indexes.end())
        // {
        validation_data->push_back(data_array->at(num));
        //     used_indexes.insert(rand_index);
        //     count++;
        // }
    }
    printf("Successfully split validation data");

    // Testing data
    count = 0;
    // while (count < test_size)
    for (int num : test_index)
    {
        // int rand_index = rand() % data_array->size();
        // if (used_indexes.find(rand_index) == used_indexes.end())
        // {
        test_data->push_back(data_array->at(num));
        //     used_indexes.insert(rand_index);
        //     count++;
        // }
    }
    printf("Successfully split testing data");

    printf("Training Data size: %iu.\n", training_data->size());
    printf("Testing Data size: %iu.\n", test_data->size());
    printf("Validation Data size: %iu.\n", validation_data->size());
}
void data_handler::count_classes() // count all classes in dataset
{
    int count = 0;
    for(unsigned i = 0; i < data_array->size(); i++) // loop through data_array
    {
        if(class_map.find(data_array->at(i)->get_label()) == class_map.end()) //find if label (key) already in class_map (if ==.end() mean not found data till end of map) 
        {
            class_map[data_array->at(i)->get_label()] = count; // if not found in class_map insert key:label, value:count_class
            data_array->at(i)->set_enumerated_label(count); // set to enumerate value (in case )
            count++; // continue counting
        }
    }
    num_classes = count;
    printf("Successfully Extracted %d Unique Classes.\n", num_classes);
}


// shift bit to convert big endian (most significant bit is first e.g. YYYY-MM-DD, stored 125 as 125 ) to little_endian (least significant bit is first e.g. DD-MM-YYYY, stored 125 as 521)
uint32_t data_handler::convert_to_little_endian(const unsigned char *bytes)
{
    return (uint32_t)((bytes[0] << 24) |
                      (bytes[1] << 16) |
                      (bytes[2] << 8) |
                      (bytes[3]));
}

std::vector<data *> *data_handler::get_training_data()
{
    return training_data;
}
std::vector<data *> *data_handler::get_test_data()
{
    return test_data;
}
std::vector<data *> *data_handler::get_validation_data()
{
    return validation_data;
}


// int main()
// {
//     data_handler *dh = new data_handler();
//     dh->read_feature_vector("train-images.idx3-ubyte");
//     dh->read_feature_labels("train-labels.idx1-ubyte");
//     dh->split_data();
//     dh->count_classes();
// }