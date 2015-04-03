TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../Exe/TestTransport

INCLUDEPATH = \
. \
../../Source/Modules/MMOEngine/Include \
../../Source/Modules/NetTransport \
../../Source/Base/Share

DEFINES += _DEBUG
DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC

OBJECTS_DIR = ../../Temp/Debug/Client

LIBS += -lboost_system
LIBS += -lShare_d
LIBS += -lMMOEngine_d
LIBS += -lNetTransport_d

SOURCES = \
InputCmdTestTransport.cpp \
mainTestTransport.cpp

HEADERS = \
InputCmdTestTransport.h

