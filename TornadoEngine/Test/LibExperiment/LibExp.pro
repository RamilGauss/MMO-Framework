TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../Exe/LibExp

INCLUDEPATH = .

DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

QMAKE_CXXFLAGS = -fPIC
QMAKE_LFLAGS = -rdynamic

OBJECTS_DIR = ../../Temp/LibExp

LIBS += -ldl
LIBS += -lboost_filesystem
LIBS += -lboost_system
LIBS += -lboost_thread
LIBS += -lboost_chrono
LIBS += -lboost_locale

SOURCES = \
main.cpp
