TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/MessagePack

INCLUDEPATH = \
. \
./include \
./src


DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS

COMPILER_FLAGS         = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3
QMAKE_LFLAGS = -rdynamic

OBJECTS_DIR = ../../../Temp/MessagePack

SOURCES = \
./src/objectc.c \
./src/unpack.c \
./src/version.c \
./src/vrefbuffer.c \
./src/zone.c

HEADERS = \
./include/msgpack.h \
./include/msgpack.hpp
