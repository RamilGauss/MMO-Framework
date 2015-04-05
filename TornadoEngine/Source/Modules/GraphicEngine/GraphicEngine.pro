TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/GraphicEngine_d

INCLUDEPATH = \
. \
../../Base/Share

LIBS += -lGraphicEngine_d
LIBS += -lMyGUI
LIBS += -lOGRE


DEFINES += _DEBUG
DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC

OBJECTS_DIR = ../../../Temp/Debug/GraphicEngine

SOURCES = \
BaseGUI.cpp \
GE_Impl.cpp \
GraphicEngine_OGRE_MyGUI.cpp \
InputManagerOIS.cpp

HEADERS = \
BaseGUI.h \
Events.h \
GE_Impl.h \
GraphicEngine_OGRE_MyGUI.h \
InputManagerOIS.h