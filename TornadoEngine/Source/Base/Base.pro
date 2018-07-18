TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/Base

INCLUDEPATH = \
. \
./Headers \
./Sources \
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
./Sources/AllocatorPool.cpp \
./Sources/ArrContainer.cpp \
./Sources/BL_Debug.cpp \
./Sources/BreakPacket.cpp \
./Sources/CmdParam.cpp \
./Sources/ContainerRise.cpp \
./Sources/ConverterLocale.cpp \
./Sources/CRC8.cpp \
./Sources/CryptoAES_Impl.cpp \
./Sources/CryptoRSA_Impl.cpp \
./Sources/DataExchange2ThreadElement.cpp \
./Sources/DescCallBack.cpp \
./Sources/DstEvent.cpp \
./Sources/FileOperation.cpp \
./Sources/FormManager.cpp \
./Sources/HiTimer.cpp \
./Sources/InfoFile.cpp \
./Sources/IXML.cpp \
./Sources/LoaderDLL_Unix.cpp \
./Sources/LoaderDLL_Win32.cpp \
./Sources/LoadFromFile.cpp \
./Sources/Logger.cpp \
./Sources/lz4.c \
./Sources/MakerLoaderDLL.cpp \
./Sources/MakerXML.cpp \
./Sources/MapCallBack.cpp \
./Sources/MapXML_Field.cpp \
./Sources/Markup.cpp \
./Sources/MathTools.cpp \
./Sources/MD5.cpp \
./Sources/Mutex.cpp \
./Sources/Only_N_Object.cpp \
./Sources/PopMaster.cpp \
./Sources/PushMaster.cpp \
./Sources/ResolverSelf_IP_v4.cpp \
./Sources/ReversedContainerRise.cpp \
./Sources/SaveToFile.cpp \
./Sources/SetOrderElement.cpp \
./Sources/SHA256.cpp \
./Sources/ShareLibWin.cpp \
./Sources/ShareMisc.cpp \
./Sources/SrcEvent.cpp \
./Sources/StateMachineManager.cpp \
./Sources/StorePathResources.cpp \
./Sources/SynchroAbonent.cpp \
./Sources/SynchroPoint.cpp \
./Sources/TimeManager.cpp \
./Sources/ThreadBoost.cpp \
./Sources/XML_Markup.cpp


HEADERS = \
./Headers/AllocatorPool.h \
./Headers/ArrContainer.h \
./Headers/BinarySerializer.h \
./Headers/BL_Debug.h \
./Headers/BreakPacket.h \
./Headers/CallBackRegistrator.h \
./Headers/CmdParam.h \
./Headers/ContainerArrObj.h \
./Headers/ContainerPtrArrObj.h \
./Headers/ContainerRise.h \
./Headers/ContainerTypes.h \
./Headers/ConverterLocale.h \
./Headers/CRC8.h \
./Headers/CryptoAES_Impl.h \
./Headers/CryptoRSA_Impl.h \
./Headers/DataExchange2Thread.h \
./Headers/DataExchange2ThreadElement.h \
./Headers/DescCallBack.h \
./Headers/DescEvent.h \
./Headers/DstEvent.h \
./Headers/ECS_Allocator.h \
./Headers/FastUpperBound.h \
./Headers/FileOperation.h \
./Headers/FormManager.h \
./Headers/HiTimer.h \
./Headers/IContainer.h \
./Headers/ILoaderDLL.h \
./Headers/InfoFile.h \
./Headers/IXML.h \
./Headers/License.h \
./Headers/ListPtr.h \
./Headers/LoaderDLL_Unix.h \
./Headers/LoaderDLL_Win32.h \
./Headers/LoadFromFile.h \
./Headers/LockFreeDef.h \
./Headers/Logger.h \
./Headers/lz4.h \
./Headers/MacroMaker.h \
./Headers/MacroMaker_Prepare.h \
./Headers/MakerLoaderDLL.h \
./Headers/MakerXML.h \
./Headers/MapCallBack.h \
./Headers/MapXML_Field.h \
./Headers/Markup.h \
./Headers/MathTools.h \
./Headers/MD5.h \
./Headers/MemoryPool.h \
./Headers/MemoryPoolAllocator.h \
./Headers/MessagePackSerializer.h \
./Headers/Mutex.h \
./Headers/Only_N_Object.h \
./Headers/PopMaster.h \
./Headers/PushMaster.h \
./Headers/ResolverSelf_IP_v4.h \
./Headers/ReversedContainerRise.h \
./Headers/SaveToFile.h \
./Headers/SetOrderElement.h \
./Headers/SHA256.h \
./Headers/ShareMisc.h \
./Headers/SrcEvent.h \
./Headers/SrcEvent_ex.h \
./Headers/StateMachine.h \
./Headers/StateMachineManager.h \
./Headers/StatisticValue.h \
./Headers/StorePathResources.h \
./Headers/ThreadBoost.h \
./Headers/TimeManager.h \
./Headers/TypeDef.h \
./Headers/VectorRise.h \
./Headers/XML_Markup.h
