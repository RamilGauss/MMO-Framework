TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../../Exe/ClientTransport

INCLUDEPATH = \
. \
../Share \
../../../Source/Modules \
../../../Source/Base/include

DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC
QMAKE_LFLAGS = -rdynamic

OBJECTS_DIR = ../../../Temp/ClientTransport

LIBS += -lboost_system
LIBS += -lBase
LIBS += -lMMOEngine
LIBS += -lNetTransport

SOURCES = \
main.cpp \
InputCmdClientTransport.cpp

HEADERS = \
InputCmdClientTransport.h \
../Share/Handler.h \
../Share/Packets.h