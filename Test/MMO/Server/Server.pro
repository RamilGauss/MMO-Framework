TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../../Exe/Server

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

OBJECTS_DIR = ../../../Temp/Server

LIBS += -lboost_system
LIBS += -lBase
LIBS += -lMMOEngine
LIBS += -lNetTransport
LIBS += -lClusterMonitorProtocol

SOURCES = \
mainServer.cpp \
ClusterMonitorServerHandler.cpp \
HandlerMMO_Master.cpp \
HandlerMMO_Slave.cpp \
HandlerMMO_SuperServer.cpp \
InputCmdTestMMO_Server.cpp \
../Share/CommonParam.cpp \
../Share/HandlerMMO.cpp

HEADERS = \
ClusterMonitorServerHandler.h \
HandlerMMO_Master.h \
HandlerMMO_Slave.h \
HandlerMMO_SuperServer.h \
InputCmdTestMMO_Server.h \
../Share/CommonParam.h \
../Share/HandlerMMO.h
