# vcpkg
``` shell
git clone https://github.com/Microsoft/vcpkg.git
```
# Prepare for build
Linux
``` bash
./vcpkg/bootstrap-vcpkg.sh
cmake -DCMAKE_TOOLCHAIN_FILE="/vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=10
```
Windows
``` shell
./vcpkg/bootstrap-vcpkg.bat
cmake -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=10
```
Debug version
``` shell
cmake --build ./build/ --config Debug -j10
```
Release version
``` shell
cmake --build ./build/ --config Relase -j10
```

``` bash
sudo apt-get update && sudo apt-get -y install cmake g++ pkg-config curl zip unzip tar git linux-libc-dev gpg autoconf automake autoconf-archive
sudo apt install build-essential ninja-build
sudo apt install libx11-dev libxft-dev libxext-dev
sudo apt install libwayland-dev libxkbcommon-dev libegl1-mesa-dev
sudo apt install libibus-1.0-dev
sudo apt install libtool

export CC=/usr/bin/gcc
export CXX=/usr/bin/g++

git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh

cmake -D CMAKE_C_COMPILER="/usr/bin/gcc" -D CMAKE_CXX_COMPILER="/usr/bin/g++" -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_TOOLCHAIN_FILE="../vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=10
```
