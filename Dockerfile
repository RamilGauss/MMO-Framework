FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
ARG PROXY_PASS

RUN apt-get update && apt-get -y install cmake g++ pkg-config curl zip unzip tar git linux-libc-dev gpg wget iproute2 iputils-ping autoconf automake autoconf-archive mc
RUN apt-get -y install build-essential libx11-dev libxft-dev libxext-dev libwayland-dev libxkbcommon-dev libegl1-mesa-dev libibus-1.0-dev libtool net-tools
RUN apt-get -y install libcurl4-openssl-dev libssl-dev python3-jinja2

RUN export CC=/usr/bin/gcc
RUN export CXX=/usr/bin/g++

WORKDIR /
RUN git clone https://github.com/Microsoft/vcpkg.git
RUN ./vcpkg/bootstrap-vcpkg.sh

WORKDIR /root
RUN touch .curlrc
RUN echo "hsts = /root/hsts.txt" > .curlrc

COPY . /MMOFramework
WORKDIR /MMOFramework

RUN curl -O https://ftp.gnu.org/pub/gnu/gperf/gperf-3.1.tar.gz
RUN cmake -D CMAKE_C_COMPILER="/usr/bin/gcc" -D CMAKE_CXX_COMPILER="/usr/bin/g++" -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_TOOLCHAIN_FILE="../vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=10
RUN cmake --build ./build/ --config Debug -j10

CMD ["tail", "-f", "/dev/null"]
