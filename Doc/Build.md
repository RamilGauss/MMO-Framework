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
wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key | sudo gpg --dearmor -o /usr/share/keyrings/llvm-archive-keyring.gpg
echo "deb [signed-by=/usr/share/keyrings/llvm-archive-keyring.gpg] http://apt.llvm.org/jammy/ llvm-toolchain-jammy-19 main" | sudo tee /etc/apt/sources.list.d/llvm.list
sudo apt update
sudo apt install -y clang-19 lld-19 libc++-19-dev libc++abi-19-dev clang-tools-19
sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-19 100
sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-19 100
sudo update-alternatives --install /usr/bin/ld.lld ld.lld /usr/bin/ld.lld-19 100
sudo update-alternatives --config clang
sudo update-alternatives --config clang++
sudo apt install -y clang-format-19 clang-tidy-19 clangd-19

sudo apt update
sudo apt install -y build-essential

sudo apt install python3-pip
pip3 install cmake
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
sudo apt-get -y install cmake pkg-config curl zip unzip tar git linux-libc-dev gpg autoconf automake autoconf-archive libtool
sudo apt install clang

git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh

export CC=/usr/bin/clang-19
export CXX=/usr/bin/clang++-19
cmake -D CMAKE_C_COMPILER="/usr/bin/clang-19" -D CMAKE_CXX_COMPILER="/usr/bin/clang++-19" -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_TOOLCHAIN_FILE="../vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=8
```
