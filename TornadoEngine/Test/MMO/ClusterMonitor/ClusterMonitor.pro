TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../../Exe/ClusterMonitor

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

OBJECTS_DIR = ../../../Temp/ClusterMonitor

LIBS += -lboost_system
LIBS += -lBase
LIBS += -lMMOEngine
LIBS += -lNetTransport
LIBS += -lClusterMonitorProtocol

SOURCES = \
main.cpp \
ClusterMonitorClientHandler.cpp \
InputCmdTestMMO_ClusterMonitor.cpp \
../Share/CommonParam.cpp

HEADERS = \
ClusterMonitorClientHandler.h \
InputCmdTestMMO_ClusterMonitor.h \
../Share/CommonParam.h
