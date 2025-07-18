FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ARG PROXY_PASS

RUN apt-get update && apt-get -y install cmake pkg-config curl zip unzip tar git linux-libc-dev iproute2 gpg autoconf automake autoconf-archive

RUN echo "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-19 main" > /etc/apt/sources.list.d/llvm.list
RUN curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | gpg --dearmor | tee /etc/apt/trusted.gpg.d/llvm.gpg > /dev/null
RUN apt-get update && apt-get -y install clang-19 lld-19 libc++-19-dev clang-format-19

RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-19 100 && \
    update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-19 100  && \
    update-alternatives --install /usr/bin/lld lld /usr/bin/lld-19 100  && \
    update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-19 100  && \
    update-alternatives --install /usr/bin/clang-format-diff clang-format-diff /usr/bin/clang-format-diff-19 100

RUN printf '#!/bin/bash\nexec /usr/bin/clang -stdlib=libc++ "$@"\n' | tee /usr/bin/clang-libc++ > /dev/null && chmod +x /usr/bin/clang-libc++
RUN printf '#!/bin/bash\nexec /usr/bin/clang++ -stdlib=libc++ "$@"\n' | tee /usr/bin/clang++-libc++ > /dev/null && chmod +x /usr/bin/clang++-libc++

RUN update-alternatives --install /usr/bin/cc cc /usr/bin/clang-libc++ 100  && \
    update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-libc++ 100  && \
    update-alternatives --install /usr/bin/ld ld /usr/bin/lld 100

RUN git clone --depth 1 --progress https://github.com/Microsoft/vcpkg.git && /vcpkg/bootstrap-vcpkg.sh

COPY . /MMOFramework
WORKDIR /MMOFramework
# RUN cmake -DCMAKE_TOOLCHAIN_FILE="/vcpkg/scripts/buildsystems/vcpkg.cmake" -S . -B ./build/ -DBUILD_PROCESSES=8
# RUN cmake --build .\build\ --config Relase -j8

CMD ["tail", "-f", "/dev/null"]