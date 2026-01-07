# C++ Machine learning
> Neural network
*Requirements*:
- libtorch from pytorch : download from https://pytorch.org/get-started/locally/ extract file and stored in lib/
- Visual studio: Installing C++ extension
- CMake
*Step*:
1. created CMakeLists.txt
2. created build folder
3. in windows: using MSVC from Visual studio by
    3.1 Opening x64 Native Tools Command Prompt for VS
    3.2 cmake -S . -B build -G "Visual Studio 18 2026" -A x64
    3.3 cmake --build build --config Release
4. Executed file is in build/Release/