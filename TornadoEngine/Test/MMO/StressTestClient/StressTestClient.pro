TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../../Exe/StressTestClient

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

OBJECTS_DIR = ../../../Temp/Debug/Client

LIBS += -lboost_system
LIBS += -lShare_d
LIBS += -lMMOEngine_d
LIBS += -lNetTransport_d

SOURCES = \
BehaviourClient.cpp \
ScenarioStressTestClient.cpp \
HandlerMMO_Client.cpp \
InputCmdTestMMO_Client.cpp \
mainClient.cpp \
../Share/HandlerMMO.cpp \
../Share/MakerTransport.cpp

HEADERS = \
BehaviourClient.h \
ScenarioStressTestClient.h \
HandlerMMO_Client.h \
InputCmdTestMMO_Client.h \
../Share/CommonParam.h \
../Share/HandlerMMO.h \
../Share/MakerTransport.h
