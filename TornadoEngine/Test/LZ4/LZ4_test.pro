TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../Bin/LZ4_test

INCLUDEPATH = \
. \
../../Packages/LZ4

DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS

COMPILER_FLAGS         = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3

OBJECTS_DIR = ../../Temp/Tests/LZ4

LIBS += -lLZ4


SOURCES = \
./main.cpp
