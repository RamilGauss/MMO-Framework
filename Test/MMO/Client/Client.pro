TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../../Exe/Client

INCLUDEPATH = \
. \
../Share \
../../../Source/Modules \
../../../Source/3rdParty/fmt/include \
../../../Source/Base/include

DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC
QMAKE_LFLAGS = -rdynamic

OBJECTS_DIR = ../../../Temp/Client

LIBS += -lboost_system
LIBS += -lfmt
LIBS += -lBase
LIBS += -lMMOEngine
LIBS += -lNetTransport

SOURCES = \
HandlerMMO_Client.cpp \
InputCmdTestMMO_Client.cpp \
mainClient.cpp \
../Share/CommonParam.cpp \
../Share/HandlerMMO.cpp

HEADERS = \
ClientDesc.h \
HandlerMMO_Client.h \
InputCmdTestMMO_Client.h \
../Share/CommonParam.h \
../Share/HandlerMMO.h
