TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../../Exe/Server

INCLUDEPATH = \
. \
../Share \
../../../Source/Modules/MMOEngine/Include \
../../../Source/Modules/NetTransport \
../../../Source/Base/Headers

DEFINES += _DEBUG
DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC

OBJECTS_DIR = ../../../Temp/Debug/Server

LIBS += -lboost_system
LIBS += -lBase_d
LIBS += -lMMOEngine_d
LIBS += -lNetTransport_d

SOURCES = \
mainServer.cpp \
HandlerMMO_Master.cpp \
HandlerMMO_Slave.cpp \
HandlerMMO_SuperServer.cpp \
../Share/HandlerMMO.cpp \
../Share/MakerTransport.cpp

HEADERS = \
HandlerMMO_Master.h \
HandlerMMO_Slave.h \
HandlerMMO_SuperServer.h \
../Share/CommonParam.h \
../Share/HandlerMMO.h \
../Share/MakerTransport.h
