# Prepare for build
## Linux

``` bash
sudo apt-get update && sudo apt-get -y install cmake g++ pkg-config curl zip unzip tar git linux-libc-dev gpg wget iproute2 iputils-ping autoconf automake autoconf-archive mc
sudo apt-get -y install build-essential libx11-dev libxft-dev libxext-dev libwayland-dev libxkbcommon-dev libegl1-mesa-dev libibus-1.0-dev libtool net-tools
sudo apt-get -y install libcurl4-openssl-dev libssl-dev python3-jinja2

export CC=/usr/bin/gcc
export CXX=/usr/bin/g++

git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
cmake -D CMAKE_C_COMPILER="/usr/bin/gcc" -D CMAKE_CXX_COMPILER="/usr/bin/g++" -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_TOOLCHAIN_FILE="../vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=10
```
## Windows
``` shell
git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.bat
cmake -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=10
```

# Build

``` shell
cmake --build ./build/ --config Debug -j10
cmake --build ./build/ --config Relase -j10
```