# vcpkg
``` shell
git clone https://github.com/Microsoft/vcpkg.git
```
# Prepare for build
Linux
``` bash
./vcpkg/bootstrap-vcpkg.sh
cmake -DCMAKE_TOOLCHAIN_FILE="/vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=8
```
Windows
``` shell
./vcpkg/bootstrap-vcpkg.bat
cmake -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=8
```
Debug version
``` shell
cmake --build ./build/ --config Debug -j8
```
Release version
``` shell
cmake --build ./build/ --config Relase -j8
```



``` bash
sudo apt update
sudo apt install -y build-essential

sudo apt install python3-pip
pip3 install cmake
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
# sudo apt-get install curl zip unzip tar
# sudo apt-get install pkg-config
# sudo apt-get install autoconf
# sudo apt-get install libtool
sudo apt-get -y install cmake pkg-config curl zip unzip tar git linux-libc-dev gpg autoconf automake autoconf-archive libtool

git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh

export CC=/usr/bin/gcc
export CXX=/usr/bin/g++
cmake -D CMAKE_C_COMPILER="/usr/bin/gcc" -D CMAKE_CXX_COMPILER="/usr/bin/g++" -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_TOOLCHAIN_FILE="../vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=8
```
