/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerGameObjectH
#define ManagerGameObjectH

#include "Singleton.h"
#include <string>
#include <map>
#include <boost/bimap/bimap.hpp>

class TGameObject;

class TManagerGameObject
{
  SINGLETON_H(TManagerGameObject)
  
  typedef boost::bimaps::bimap<unsigned int,std::string> bmUintStr;
  typedef bmUintStr::left_iterator bmUintStrLIt;
  typedef bmUintStr::right_iterator TBMapUintStrRIt;
  
  typedef std::map<unsigned int,std::string> TMapUintStr;
  
  bmUintStr   mMapID_NameXML;
  TMapUintStr mMapID_Type;
protected:  
  TManagerGameObject();
  ~TManagerGameObject();
public:
  bool SetPathList(std::string sPathXML);

  bool Load(std::string sNameXML, TGameObject* pObject);
  bool Load(unsigned int id, TGameObject* pObject);

  bool GetTypeByID(unsigned int id, std::string& sType);
  bool GetTypeByNameXML(std::string sNameXML, std::string& sType);
};

#endif

