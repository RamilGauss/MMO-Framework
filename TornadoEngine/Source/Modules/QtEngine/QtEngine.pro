TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/QtEngine_d

INCLUDEPATH = \
. \
./GeneratedFiles \
./GeneratedFiles/Debug \
./GeneratedFiles/Release \
../../Base/Share

LIBS += -lQtEngine_d

DEFINES += _DEBUG
DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC

OBJECTS_DIR = ../../../Temp/Debug/QtEngine

SOURCES = \
Application.cpp \
QtEngine.cpp

HEADERS = \
Application.h \
QtEngine.h \
QtEventNotify.h