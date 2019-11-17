TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/fmt

INCLUDEPATH = \
. \
./include \
./src


DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += _CRT_NONSTDC_NO_DEPRECATE
DEFINES += _GNU_SOURCE

COMPILER_FLAGS         = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3

QMAKE_LFLAGS = -rdynamic

OBJECTS_DIR = ../../../Temp/fmt

SOURCES += \
./src/format.cc \
./src/posix.cc

HEADERS = \
./include/fmt/color.h \
./include/fmt/core.h \
./include/fmt/format.h \
./include/fmt/format-inl.h \
./include/fmt/ostream.h \
./include/fmt/posix.h \
./include/fmt/printf.h \
./include/fmt/ranges.h \
./include/fmt/time.h


