TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/ECS

INCLUDEPATH = \
. \
./Conveyer \
./entt


DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS

COMPILER_FLAGS         = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3

OBJECTS_DIR = ../../Temp/ECS

SOURCES = \
./Conveyer/ConveyerPartMaster.cpp \
./Conveyer/ExecuteSystem.cpp \
./Conveyer/ReactiveForManyEventsSystem.cpp \
./Conveyer/ReactiveForOneEventSystem.cpp \
./Conveyer/World.cpp

HEADERS = \
./TypeDef.h \
./Conveyer/BaseReactiveSystem.h\
./Conveyer/ConveyerPartMaster.h \
./Conveyer/ConveyerPartWithGlobalAccess.h \
./Conveyer/DataMemoryPoolComponent.h \
./Conveyer/ECSconfig.h \
./Conveyer/ExecuteSystem.h \
./Conveyer/FastUpperBound.h \
./Conveyer/Feature.h \
./Conveyer/GlobalAccess.h \
./Conveyer/IConveyerPart.h \
./Conveyer/InitSystem.h \
./Conveyer/MemoryPool.h \
./Conveyer/ReactiveForManyEventsSystem.h \
./Conveyer/ReactiveForOneEventSystem.h \
./Conveyer/System.h \
./Conveyer/VectorRise.h \
./Conveyer/World.h
