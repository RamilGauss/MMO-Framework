/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef LoaderListPathIDH
#define LoaderListPathIDH

//#include "BL_ConfigFile.h"
#include <map>
#include <string>
#include "IXML.h"
#include "TypeDef.h"

/*
Формат файла
<root>
  <part>
    <id_model>0</id_model>
    <id_behavior>7</id_behavior>
    <path>KingTiger</path>
  </part>
</root>
*/

class SHARE_EI TLoaderListPathID
{
  char sCurrentPath[260];

  IXML *mXML;

public:
  TLoaderListPathID();
  ~TLoaderListPathID();

  bool Load(char* sAbsPath, std::map<unsigned int,std::string>* pMapID_model_path);
  
  bool LoadBehavior(char* sAbsPath, std::map<unsigned int,unsigned int>* pMapID_model_ID_Behavior);

protected:

  bool LoadPartPath(int i, std::map<unsigned int,std::string>* pMap);
  bool LoadPartID_Behavior(int i, std::map<unsigned int,unsigned int>* pMap);
  bool FindCurrentPath(char* sPath);
};
#endif