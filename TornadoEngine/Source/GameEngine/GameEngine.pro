TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/GameEngine_d

INCLUDEPATH = .


DEFINES += _DEBUG
DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC

OBJECTS_DIR = ../../Temp/Debug/GameEngine

LIBS += -ldl
LIBS += -lShare_d
LIBS += -lCommon_d
LIBS += -lPlatforms_d


SOURCES = EventGameEngine.cpp \
GameEngine.cpp \
ParserXMLConveyer.cpp \
ThreadModules.cpp


HEADERS = DeveloperTool_DLL.h \
EventGameEngine.h \
GameEngine.h \
IDevTool.h \
IModule.h \
ParserXMLConveyer.h \
ThreadModules.h
