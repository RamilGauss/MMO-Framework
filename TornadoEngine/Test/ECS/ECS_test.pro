TEMPLATE = app
LANGUAGE = C++

CONFIG += qt warn_on

TARGET = ../../Bin/ECS_test

INCLUDEPATH = \
. \
./Components \
./Conveyer \
../../Packages/ECS \
../../Packages/ECS/entt \
../../Packages/ECS/Conveyer


DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS

COMPILER_FLAGS         = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3

OBJECTS_DIR = ../../Temp/Tests/ECS

LIBS += -lECS


SOURCES = \
./main.cpp \
./SpeedCalculationSystem.cpp

HEADERS = \
./SpeedCalculationSystem.h \
./Components/FreshPacket.h \
./Components/PacketData.h \
./Components/ShuffledComponents.h \
./Conveyer/ConsumerSystem.h \
./Conveyer/GroupedPacketSystem.h \
./Conveyer/InitSettingsSystem.h \
./Conveyer/MakeShuffleEntitiesSystem.h \
./Conveyer/PacketObserverSystem.h \
./Conveyer/ProducerFeature.h \
./Conveyer/ProducerSystem.h \
./Conveyer/ViewShuffleEntitiesSystem.h

