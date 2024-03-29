TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/NetTransport

INCLUDEPATH = \
. \
./Boost_Implementation \
../../Modules \
../../Base/include

DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

LIBS += -lMMOEngine
LIBS += -lBase

COMPILER_FLAGS = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3
QMAKE_LFLAGS = -rdynamic

OBJECTS_DIR = ../../../Temp/Debug/NetTransport

SOURCES = \
dllmain.cpp \
HistoryPacketTCP.cpp \
MakerNetTransport.cpp \
./Boost_Implementation/INetControl.cpp \
./Boost_Implementation/NetControlAcceptor.cpp \
./Boost_Implementation/NetControlTCP.cpp \
./Boost_Implementation/NetControlUDP.cpp \
./Boost_Implementation/NetDeviceAcceptor.cpp \
./Boost_Implementation/NetDeviceTCP.cpp \
./Boost_Implementation/NetDeviceUDP.cpp \
./Boost_Implementation/NetTransport_Boost.cpp \
./Boost_Implementation/NetWorkThread.cpp

HEADERS = \
HeaderTCP.h \
HistoryPacketTCP.h \
MakerNetTransport.h \
./Boost_Implementation/INetControl.h \
./Boost_Implementation/INetDevice.h \
./Boost_Implementation/NetControlAcceptor.h \
./Boost_Implementation/NetControlTCP.h \
./Boost_Implementation/NetControlUDP.h \
./Boost_Implementation/NetDeviceAcceptor.h \
./Boost_Implementation/NetDeviceTCP.h \
./Boost_Implementation/NetDeviceUDP.h \
./Boost_Implementation/NetTransport_Boost.h \
./Boost_Implementation/NetWorkThread.h
