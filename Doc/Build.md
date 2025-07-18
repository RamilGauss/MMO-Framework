# vcpkg
```
git clone https://github.com/Microsoft/vcpkg.git
```
# Prepare for build
Linux
```
./vcpkg/bootstrap-vcpkg.sh
cmake -DCMAKE_TOOLCHAIN_FILE="/vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=8
```
Windows
```
./vcpkg/bootstrap-vcpkg.bat
cmake -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=8
```
Debug version
```
cmake --build .\build\ --config Debug -j8
```
Release version
```
cmake --build .\build\ --config Relase -j8
```
