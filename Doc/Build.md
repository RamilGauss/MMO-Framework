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
sudo apt-get update && sudo apt-get -y install cmake pkg-config curl zip unzip tar git linux-libc-dev iproute2 gpg autoconf automake autoconf-archive
echo "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-19 main" | sudo tee /etc/apt/sources.list.d/llvm.list
curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/llvm.gpg > /dev/null
sudo apt-get update && sudo apt-get -y install clang-19 lld-19 libc++-19-dev clang-format-19

sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-19 100
sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-19 100
sudo update-alternatives --install /usr/bin/lld lld /usr/bin/lld-19 100
sudo update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-19 100
sudo update-alternatives --install /usr/bin/clang-format-diff clang-format-diff /usr/bin/clang-format-diff-19 100

printf '#!/bin/bash\nexec /usr/bin/clang -stdlib=libc++ "$@"\n' | sudo tee /usr/bin/clang-libc++ > /dev/null && sudo chmod +x /usr/bin/clang-libc++
printf '#!/bin/bash\nexec /usr/bin/clang++ -stdlib=libc++ "$@"\n' | sudo tee /usr/bin/clang++-libc++ > /dev/null && sudo chmod +x /usr/bin/clang++-libc++

sudo update-alternatives --install /usr/bin/cc cc /usr/bin/clang-libc++ 100
sudo update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-libc++ 100
sudo update-alternatives --install /usr/bin/ld ld /usr/bin/lld 100

sudo apt install build-essential ninja-build
sudo apt install libx11-dev libxft-dev libxext-dev

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh

cmake -D CMAKE_C_COMPILER="/usr/bin/clang" -D CMAKE_CXX_COMPILER="/usr/bin/clang++" -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_TOOLCHAIN_FILE="../vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=8
```
