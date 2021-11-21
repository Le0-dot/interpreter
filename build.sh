rm -rf ./cmake
cmake CMakeLists.txt -B ./cmake -DCMAKE_BUILD_TYPE=Debug 
cd cmake 
make
cd ..
