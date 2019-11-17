TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/ShareDev_d

INCLUDEPATH = \
. \
./Modules \
./Share \
../../Base/Share \
../../MMOEngine/Include \
../../NetTransport \
../../GraphicEngine \
../../QtEngine

LIBS += -lShare_d
LIBS += -lMMOEngine_d
LIBS += -lQtEngine_d
LIBS += -lNetTransport_d
LIBS += -lGraphicEngine_d

DEFINES += _DEBUG
DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC
QMAKE_LFLAGS = -rdynamic

OBJECTS_DIR = ../../../Temp/Debug/ShareDev

SOURCES = \
./Modules/BaseLogicPacket.cpp \
./Modules/ModuleAloneGUI.cpp \
./Modules/ModuleClientLogic.cpp \
./Modules/ModuleComponent.cpp \
./Modules/ModuleDataBase.cpp \
./Modules/ModuleGraphicEngine.cpp \
./Modules/ModuleLogic.cpp \
./Modules/ModulePhysicEngine.cpp \
./Modules/ModuleServerLogic.cpp \
./Modules/ModuleSoundEngine.cpp \
./Modules/ModuleTimer.cpp \
./Share/Components.cpp \
./Share/InputCmdDevTool.cpp \
./Share/ModuleDev.cpp \
./Share/ParserXMLResource.cpp \
./Share/Resources.cpp \
./Share/ResourcesGraphicEngine.cpp \
./Share/WrapperMakerTransport.cpp


HEADERS = \
./Modules/BaseLogicPacket.h \
./Modules/LogicEventCallBack.h \
./Modules/ModuleAloneGUI.h \
./Modules/ModuleClientLogic.h \
./Modules/ModuleComponent.h \
./Modules/ModuleDataBase.h \
./Modules/ModuleGraphicEngine.h \
./Modules/ModuleLogic.h \
./Modules/ModuleMMOEngine.h \
./Modules/ModuleMMOEngineClient.h \
./Modules/ModuleMMOEngineMaster.h \
./Modules/ModuleMMOEngineSlave.h \
./Modules/ModuleMMOEngineSuperServer.h \
./Modules/ModulePhysicEngine.h \
./Modules/ModuleServerLogic.h \
./Modules/ModuleSoundEngine.h \
./Modules/ModuleTimer.h \
./Share/Components.h \
./Share/InputCmdDevTool.h \
./Share/ModuleDev.h \
./Share/ParserXMLResource.h \
./Share/Resources.h \
./Share/ResourcesGraphicEngine.h \
./Share/WrapperMakerTransport.h
