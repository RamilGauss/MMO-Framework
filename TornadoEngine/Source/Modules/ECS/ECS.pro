TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/ECS

INCLUDEPATH = \
. \
./include \
./src \
../../Base/include

LIBS += -lBase

DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS

COMPILER_FLAGS         = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3

OBJECTS_DIR = ../../Temp/ECS

SOURCES = \
./src/BaseReactiveSystem.cpp \
./src/ConveyerPartMaster.cpp \
./src/Entity.cpp \
./src/EntityManager.cpp \
./src/ExecuteSystem.cpp \
./src/ReactiveForManyEventsSystem.cpp \
./src/ReactiveForOneEventSystem.cpp \
./src/World.cpp

HEADERS = \
./include/BaseReactiveSystem.h \
./include/ComplexType.h \
./include/ComponentInfo.h \
./include/Config.h \
./include/ConnectTypeManager.h \
./include/ContainerForReactive.h \
./include/ConveyerPartMaster.h \
./include/ConveyerPartWithGlobalAccess.h \
./include/Entity.h \
./include/EntityManager.h \
./include/ExecuteSystem.h \
./include/Feature.h \
./include/GlobalAccess.h \
./include/GlobalSystemInitializer.h \
./include/GlobalSystemUpdater.h \
./include/Helper.h \
./include/HelpStructs.h \
./include/IConveyerPart.h \
./include/InitSystem.h \
./include/LinkToList.h \
./include/LoopList.h \
./include/ReactiveForManyEventsSystem.h \
./include/ReactiveForOneEventSystem.h \
./include/ReactiveOnAddSystem.h \
./include/ReactiveOnRemoveSystem.h \
./include/ReactiveOnUpdateSystem.h \
./include/System.h \
./include/World.h
