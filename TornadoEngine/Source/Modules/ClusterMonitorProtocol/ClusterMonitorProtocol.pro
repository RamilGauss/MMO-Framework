TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/ClusterMonitorProtocol

INCLUDEPATH = \
. \
../../Modules \
../../Base/include

DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

LIBS += -lMMOEngine
LIBS += -lNetTransport
LIBS += -lBase

COMPILER_FLAGS = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3

OBJECTS_DIR = ../../../Temp/Debug/ClusterMonitorProtocol

SOURCES = \
BaseTransport.cpp \
ClientTransport.cpp \
Packets.cpp \
ServerTransport.cpp

HEADERS = \
BaseTransport.h \
ClientTransport.h \
MonitorEvents.h \
Packets.h \
ServerTransport.h