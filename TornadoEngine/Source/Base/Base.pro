TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/Share_d

INCLUDEPATH = .

DEFINES += _DEBUG
DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += MARKUP_STL
DEFINES += USE_MATH_TOOLS

COMPILER_FLAGS = -fPIC

OBJECTS_DIR = ../../Temp/Debug/Share

LIBS += -lssl
LIBS += -lcrypto
LIBS += -ldl
LIBS += -lboost_filesystem
LIBS += -lboost_system
LIBS += -lboost_thread
LIBS += -lboost_chrono
LIBS += -lboost_locale


SOURCES = ArrContainer.cpp \
BL_Debug.cpp \
BreakPacket.cpp \
CmdParam.cpp \
ConverterLocale.cpp \
ContainerRise.cpp \
CRC8.cpp \
CryptoAES_Impl.cpp \
CryptoRSA_Impl.cpp \
DescCallBack.cpp \
DstEvent.cpp \
FileOperation.cpp \
HiTimer.cpp \
InfoFile.cpp \
IXML.cpp \
LoaderDLL_Unix.cpp \
LoaderDLL_Win32.cpp \
LoadFromFile.cpp \
Logger.cpp \
MakerLoaderDLL.cpp \
MakerXML.cpp \
ManagerForm.cpp \
ManagerStateMachine.cpp \
ManagerTime.cpp \
MapCallBack.cpp \
MapXML_Field.cpp \
Markup.cpp \
MathTools.cpp \
MD5.cpp \
Mutex.cpp \
Only_N_Object.cpp \
ResolverSelf_IP_v4.cpp \
SaveToFile.cpp \
SetOrderElement.cpp \
SHA256.cpp \
ShareLibWin.cpp \
ShareMisc.cpp \
SrcEvent.cpp \
StorePathResources.cpp \
ThreadBoost.cpp \
XML_Markup.cpp


HEADERS = ArrContainer.h\
BL_Debug.h \
BreakPacket.h \
CallBackRegistrator.h \
CmdParam.h \
ConverterLocale.h \
ContainerArrObj.h \
ContainerPtrArrObj.h \
ContainerRise.h \
ContainerTypes.h \
CRC8.h \
CryptoAES_Impl.h \
CryptoRSA_Impl.h \
DataExchange2Thread.h \
DescCallBack.h \
DescEvent.h \
DstEvent.h \
FileOperation.h \
HiTimer.h \
IContainer.h \
ILoaderDLL.h \
InfoFile.h \
IXML.h \
License.h \
ListPtr.h \
LoaderDLL_Unix.h \
LoaderDLL_Win32.h \
LoadFromFile.h \
LockFreeDef.h \
Logger.h \
MacroMaker.h \
MacroMaker_Prepare.h \
MakerLoaderDLL.h \
MakerXML.h \
ManagerForm.h \
ManagerStateMachine.h \
ManagerTime.h \
MapCallBack.h \
MapXML_Field.h \
Markup.h \
MathTools.h \
MD5.h \
Mutex.h \
Only_N_Object.h \
ResolverSelf_IP_v4.h \
SaveToFile.h \
SetOrderElement.h \
SHA256.h \
ShareMisc.h \
SrcEvent_ex.h \
SrcEvent.h \
StateMachine.h \
StatisticValue.h \
StorePathResources.h \
TypeDef.h \
ThreadBoost.h \
XML_Markup.h
