TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../Exe/Tornado_d

INCLUDEPATH = .

DEFINES += _DEBUG
DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC

OBJECTS_DIR = ../../Temp/Debug/Game

LIBS += -ldl
LIBS += -lShare_d
LIBS += -lGameEngine_d


SOURCES = InputCmdTornado.cpp \
main.cpp


HEADERS = InputCmdTornado.h
