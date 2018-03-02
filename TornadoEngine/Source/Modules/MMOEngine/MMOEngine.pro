TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/MMOEngine_d

INCLUDEPATH = \
. \
./Include \
./Source \
./ContextScenario \
./Scenario \
./SubSystem \
../../Base/Headers

LIBS += -lBase_d

DEFINES += _DEBUG
DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC

OBJECTS_DIR = ../../../Temp/Debug/MMOEngine

SOURCES = \
./ContextScenario/ContextScDisconnectClient.cpp \
./ContextScenario/ContextScDisconnectSlave.cpp \
./ContextScenario/ContextScFlow.cpp \
./ContextScenario/ContextScLoginClient.cpp \
./ContextScenario/ContextScLoginMaster.cpp \
./ContextScenario/ContextScLoginSlave.cpp \
./ContextScenario/ContextScRecommutationClient.cpp \
./ContextScenario/ContextScSendToClient.cpp \
./ContextScenario/ContextScSynchroSlave.cpp \
./Scenario/BaseScLoginClient.cpp \
./Scenario/BaseScLoginClient_Struct.cpp \
./Scenario/BaseScRecommutationClient.cpp \
./Scenario/BaseScRecommutationClient_Struct.cpp \
./Scenario/DescRequestConnectForRecipient.cpp \
./Scenario/ScenarioDisconnectClient.cpp \
./Scenario/ScenarioFlow.cpp \
./Scenario/ScenarioLoginClient.cpp \
./Scenario/ScenarioLoginMaster.cpp \
./Scenario/ScenarioLoginSlave.cpp \
./Scenario/ScenarioRecommutationClient.cpp \
./Scenario/ScenarioSendToClient.cpp \
./Scenario/ScenarioSynchroSlave.cpp \
./Scenario/ScLoginClient_ClientImpl.cpp \
./Scenario/ScLoginClient_MasterImpl.cpp \
./Scenario/ScLoginClient_SlaveImpl.cpp \
./Scenario/ScLoginClient_SuperServerImpl.cpp \
./Scenario/ScRecommutationClient_ClientImpl.cpp \
./Scenario/ScRecommutationClient_MasterImpl.cpp \
./Scenario/ScRecommutationClient_SlaveImpl.cpp \
./Source/ActiveServer.cpp \
./Source/Base.cpp \
./Source/BaseServer.cpp \
./Source/Client.cpp \
./Source/Events.cpp \
./Source/IMakerTransport.cpp \
./Source/INetTransport.cpp \
./Source/Master.cpp \
./Source/Slave.cpp \
./Source/Structs.cpp \
./Source/SuperServer.cpp \
./SubSystem/ContainerContextSc.cpp \
./SubSystem/ContextCrypto.cpp \
./SubSystem/ControlScenario.cpp \
./SubSystem/CryptoContextManager.cpp \
./SubSystem/CryptMITM.cpp \
./SubSystem/DelegateManagerContextSc.cpp \
./SubSystem/IScenarioContext.cpp \
./SubSystem/IScenario.cpp \
./SubSystem/MakerScenario.cpp \
./SubSystem/ManagerContextClientLogining.cpp \
./SubSystem/ManagerContextClient_slave.cpp \
./SubSystem/ManagerContextDownConnection.cpp \
./SubSystem/ManagerContextDownConnection_Slave.cpp \
./SubSystem/ManagerContextMoreDownClientConnection.cpp \
./SubSystem/ManagerGroupClient.cpp \
./SubSystem/ManagerManagerContextSc.cpp \
./SubSystem/ManagerRecommutation.cpp \
./SubSystem/TransportManager.cpp \
./SubSystem/ReciverTransport.cpp \
./SubSystem/ScContextManager.cpp \
./SubSystem/Session.cpp \
./SubSystem/SessionManager.cpp \
./SubSystem/SessionNavigator.cpp \
./SubSystem/StatisticaClientInGroup.cpp \
./SubSystem/TransportManager.cpp

HEADERS = \
./ContextScenario/ContextScDisconnectClient.h \
./ContextScenario/ContextScDisconnectSlave.h \
./ContextScenario/ContextScFlow.h \
./ContextScenario/ContextScLoginClient.h \
./ContextScenario/ContextScLoginMaster.h \
./ContextScenario/ContextScLoginSlave.h \
./ContextScenario/ContextScRecommutationClient.h \
./ContextScenario/ContextScSendToClient.h \
./ContextScenario/ContextScSynchroSlave.h \
./Include/ActiveServer.h \
./Include/BaseEvent.h \
./Include/Base.h \
./Include/BaseServer.h \
./Include/Client.h \
./Include/EnumMMO.h \
./Include/Events.h \
./Include/IMakerTransport.h \
./Include/INetTransport.h \
./Include/Master.h \
./Include/Slave.h \
./Include/Structs.h \
./Include/SuperServer.h \
./Scenario/BaseScLoginClient.h \
./Scenario/BaseScLoginClient_Struct.h \
./Scenario/BaseScRecommutationClient.h \
./Scenario/BaseScRecommutationClient_Struct.h \
./Scenario/DescRequestConnectForRecipient.h \
./Scenario/ScenarioDisconnectClient.h \
./Scenario/ScenarioFlow.h \
./Scenario/ScenarioLoginClient.h \
./Scenario/ScenarioLoginMaster.h \
./Scenario/ScenarioLoginSlave.h \
./Scenario/ScenarioRecommutationClient.h \
./Scenario/ScenarioSendToClient.h \
./Scenario/ScenarioSynchroSlave.h \
./Scenario/ScLoginClient_ClientImpl.h \
./Scenario/ScLoginClient_MasterImpl.h \
./Scenario/ScLoginClient_SlaveImpl.h \
./Scenario/ScLoginClient_SuperServerImpl.h \
./Scenario/ScRecommutationClient_ClientImpl.h \
./Scenario/ScRecommutationClient_MasterImpl.h \
./Scenario/ScRecommutationClient_SlaveImpl.h \
./SubSystem/ContainerContextSc.h \
./SubSystem/ContextCrypto.h \
./SubSystem/ControlScenario.h \
./SubSystem/CryptMITM.h \
./SubSystem/CryptoContextManager.h \
./SubSystem/DelegateManagerContextSc.h \
./SubSystem/DescRecvSession.h \
./SubSystem/IScenarioContext.h \
./SubSystem/IScenario.h \
./SubSystem/MakerScenario.h \
./SubSystem/ManagerContextClientLogining.h \
./SubSystem/ManagerContextClient_slave.h \
./SubSystem/ManagerContextDownConnection.h \
./SubSystem/ManagerContextDownConnection_Slave.h \
./SubSystem/ManagerContextMoreDownClientConnection.h \
./SubSystem/ManagerGroupClient.h \
./SubSystem/ManagerManagerContextSc.h \
./SubSystem/ManagerRecommutation.h \
./SubSystem/ReciverTransport.h \
./SubSystem/ScContextManager.h \
./SubSystem/Session.h \
./SubSystem/SessionManager.h \
./SubSystem/SessionNavigator.h \
./SubSystem/ScenarioBaseHeader.h \
./SubSystem/StatisticaClientInGroup.h \
./SubSystem/TransportManager.h
