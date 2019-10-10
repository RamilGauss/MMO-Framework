TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/Base

INCLUDEPATH = \
. \
./include \
./src \
../3rdParty/libuv/include

DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3

OBJECTS_DIR = ../../Temp/Base

LIBS += -lssl
LIBS += -lcrypto
LIBS += -ldl
LIBS += -lboost_filesystem
LIBS += -lboost_system
LIBS += -lboost_thread
LIBS += -lboost_chrono
LIBS += -lboost_locale
LIBS += -llibuv


SOURCES = \
./src/AllocatorPool.cpp \
./src/ArrContainer.cpp \
./src/BinaryPopMaster.cpp \
./src/BinaryPushMaster.cpp \
./src/BL_Debug.cpp \
./src/BreakPacket.cpp \
./src/CmdParam.cpp \
./src/ContainerRise.cpp \
./src/ConverterLocale.cpp \
./src/CRC8.cpp \
./src/CryptoAES_Impl.cpp \
./src/CryptoRSA_Impl.cpp \
./src/DataExchange2ThreadElement.cpp \
./src/DescCallBack.cpp \
./src/DstEvent.cpp \
./src/ExecuteInstructionEngine.cpp \
./src/FileOperation.cpp \
./src/FormManager.cpp \
./src/HiTimer.cpp \
./src/InfoFile.cpp \
./src/InputByCmd.cpp \
./src/IXML.cpp \
./src/json11.cpp \
./src/LoaderDLL_Unix.cpp \
./src/LoaderDLL_Win32.cpp \
./src/LoadFromFile.cpp \
./src/Logger.cpp \
./src/lz4.c \
./src/MakerLoaderDLL.cpp \
./src/MakerXML.cpp \
./src/MapCallBack.cpp \
./src/MapXML_Field.cpp \
./src/Markup.cpp \
./src/MathTools.cpp \
./src/MD5.cpp \
./src/Mutex.cpp \
./src/Only_N_Object.cpp \
./src/PopMaster.cpp \
./src/PushMaster.cpp \
./src/ResolverSelf_IP_v4.cpp \
./src/ReversedContainerRise.cpp \
./src/SaveToFile.cpp \
./src/SetOrderElement.cpp \
./src/Settings.cpp \
./src/SHA256.cpp \
./src/ShareLibWin.cpp \
./src/ShareMisc.cpp \
./src/SingletonManager.cpp \
./src/SrcEvent.cpp \
./src/StateMachineManager.cpp \
./src/StorePathResources.cpp \
./src/SynchroAbonent.cpp \
./src/SynchroPoint.cpp \
./src/TextFile.cpp \
./src/ThreadBoost.cpp \
./src/TimeManager.cpp \
./src/TypeIdentifier.cpp \
./src/XML_Markup.cpp


HEADERS = \
./include/AllocatorPool.h \
./include/ArrContainer.h \
./include/BinaryMaster.h \
./include/BinaryPopMaster.h \
./include/BinaryPushMaster.h \
./include/BinarySerializer.h \
./include/BL_Debug.h \
./include/BreakPacket.h \
./include/CallBackRegistrator.h \
./include/CmdParam.h \
./include/ColanderVector.h \
./include/ContainerArrObj.h \
./include/ContainerPtrArrObj.h \
./include/ContainerRise.h \
./include/ContainerTypes.h \
./include/ConverterLocale.h \
./include/CRC8.h \
./include/CryptoAES_Impl.h \
./include/CryptoRSA_Impl.h \
./include/DataExchange2Thread.h \
./include/DataExchange2ThreadElement.h \
./include/DescCallBack.h \
./include/DescEvent.h \
./include/DstEvent.h \
./include/ECS_Allocator.h \
./include/FastUpperBound.h \
./include/FileOperation.h \
./include/FormManager.h \
./include/HiTimer.h \
./include/IContainer.h \
./include/ILoaderDLL.h \
./include/InfoFile.h \
./include/InputByCmd.h \
./include/IXML.h \
./include/json11.h \
./include/JsonMaster.h \
./include/JsonPopMaster.h \
./include/JsonPushMaster.h \
./include/License.h \
./include/ListPtr.h \
./include/LoaderDLL_Unix.h \
./include/LoaderDLL_Win32.h \
./include/LoadFromFile.h \
./include/LockFreeDef.h \
./include/Logger.h \
./include/lz4.h \
./include/MacroMaker.h \
./include/MacroMaker_Prepare.h \
./include/MakerLoaderDLL.h \
./include/MakerXML.h \
./include/MapCallBack.h \
./include/MapXML_Field.h \
./include/Markup.h \
./include/Marshaller.h \
./include/MathTools.h \
./include/MD5.h \
./include/MemoryObjectPool.h \
./include/MemoryObjectPoolAllocator.h \
./include/MemoryPool.h \
./include/MessagePackSerializer.h \
./include/Mutex.h \
./include/Only_N_Object.h \
./include/ReflectionMacro.h \
./include/RemoveIthType.h \
./include/ResolverSelf_IP_v4.h \
./include/ReversedContainerRise.h \
./include/SaveToFile.h \
./include/SetOrderElement.h \
./include/Settings.h \
./include/SHA256.h \
./include/ShareMisc.h \
./include/SingletonManager.h \
./include/SortedThinningRestoreOrder.h \
./include/SortedVector.h \
./include/SortedVecWithKeyMap.h \
./include/SrcEvent.h \
./include/SrcEvent_ex.h \
./include/StateMachine.h \
./include/StatisticValue.h \
./include/StorePathResources.h \
./include/ThreadBoost.h \
./include/TimeManager.h \
./include/TypeDef.h \
./include/TypeIdentifier.h \
./include/VectorRise.h \
./include/XML_Markup.h
