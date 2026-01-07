#include <torch/torch.h>
#include <iostream>

int main()
{
    // cpu
    torch::Tensor tensor = torch::rand({2, 3});
    // cuda
    // torch::Tensor tensor = torch::randn({2,3}, torch::kCUDA);
    std::cout << tensor << std::endl;
}