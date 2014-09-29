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

COMPILER_FLAS = -fPIC

OBJECTS_DIR = ../../../Temp/Debug/Share

LIBS += -lssl
LIBS += -lcrypto
LIBS += -ldl
LIBS += -lboost_filesystem
LIBS += -lboost_system
LIBS += -lboost_thread
LIBS += -lboost_chrono


SOURCES = ArrContainer.cpp \
BasePacket.cpp \
BL_Debug.cpp \
BreakPacket.cpp \
CmdParam.cpp \
cnvCoderText.cpp \
ContainerRise.cpp \
CRC8.cpp \
CryptoAES_Impl.cpp \
CryptoRSA_Impl.cpp \
DescCallBack.cpp \
DstEvent.cpp \
file_operation.cpp \
GCS.cpp \
HiTimer.cpp \
InfoFile.cpp \
IXML.cpp \
LoaderDLL_Unix.cpp \
LoaderDLL_Win32.cpp \
LoaderListPathID.cpp \
LoaderTree.cpp \
LoadFromFile.cpp \
Logger.cpp \
MakerLoaderDLL.cpp \
MakerXML.cpp \
ManagerForm.cpp \
ManagerStateMachine.cpp \
ManagerTime.cpp \
MapCallBack.cpp \
MapXML_Field.cpp \
MarkUpContainer.cpp \
Markup.cpp \
MathTools.cpp \
MD5.cpp \
memory_operation.cpp \
NetSystem.cpp \
Only_N_Object.cpp \
Queue2Thread.cpp \
SaveToFile.cpp \
SetOrderElement.cpp \
SHA256.cpp \
ShaderStack.cpp \
ShareLibWin.cpp \
ShareMisc.cpp \
SortByAlphabetic.cpp \
SphericalDecart.cpp \
SrcEvent.cpp \
StorePathResources.cpp \
tinyxml2.cpp \
TreeJoint.cpp \
XML_Markup.cpp \
XML_TinyXML2.cpp


HEADERS = ArrContainer.h\
AutoCreateVar.h \
BasePacket.h \
BL_Debug.h \
BreakPacket.h \
CallBackRegistrator.h \
classTools.h \
CmdParam.h \
cnvCoderText.h \
common_defs.h \
ContainerArrObj.h \
ContainerPtrArrObj.h \
ContainerRise.h \
ContainerTypes.h \
ContextMachine.h \
CRC8.h \
CryptoAES_Impl.h \
CryptoRSA_Impl.h \
DateChanges.h \
DescCallBack.h \
DescEvent.h \
DstEvent.h \
file_operation.h \
GCS.h \
HiTimer.h \
IContainer.h \
ILoaderDLL.h \
InfoFile.h \
IXML.h \
License.h \
ListMultiThread.h \
ListObj.h \
ListPtr.h \
LoaderDLL_Unix.h \
LoaderDLL_Win32.h \
LoaderListPathID.h \
LoaderTree.h \
LoadFromFile.h \
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
MarkUpContainer.h \
Markup.h \
MathTools.h \
MD5.h \
memory_operation.h \
NetSystem.h \
Only_N_Object.h \
Paradigma.h \
Queue2Thread.h \
SaveToFile.h \
SetOrderElement.h \
SHA256.h \
ShaderStack.h \
ShareMisc.h \
SortByAlphabetic.h \
SphericalDecart.h \
SrcEvent_ex.h \
SrcEvent.h \
StateMachine.h \
StatisticValue.h \
StorePathResources.h \
tinyxml2.h \
TreeJoint.h \
TypeDef.h \
XML_Markup.h \
XML_TinyXML2.h
