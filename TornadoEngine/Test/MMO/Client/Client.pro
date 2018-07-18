TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../../Exe/Client

INCLUDEPATH = \
. \
../Share \
../../../Source/Modules/MMOEngine/Include \
../../../Source/Modules/NetTransport \
../../../Source/Base/Headers

DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC

OBJECTS_DIR = ../../../Temp/Client

LIBS += -lboost_system
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
