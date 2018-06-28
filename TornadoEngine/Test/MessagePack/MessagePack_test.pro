TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../Bin/MessagePack_test

INCLUDEPATH = \
. \
../../Packages/MessagePack/include \
../../Packages/MessagePack/src


DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS

COMPILER_FLAGS         = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3

OBJECTS_DIR = ../../Temp/Tests/MessagePack

LIBS += -lECS


SOURCES = \
./main.cpp \


