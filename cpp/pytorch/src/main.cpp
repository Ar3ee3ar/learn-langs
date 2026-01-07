#include "network.h"

#include <iostream>
#include <torch/torch.h>

using namespace torch;

int main(){
    Net network(50,1);
    std::cout << network << std::endl;
    Tensor x, output;
    x = torch::randn({2,50});
    output = network->forward(x);
    std::cout << output;
}