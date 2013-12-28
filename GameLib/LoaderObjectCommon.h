/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef LoaderObjectCommonH
#define LoaderObjectCommonH


#include "IMakerObjectCommon.h"
#include <map>
#include <vector>

class IBaseObjectCommon;

class TLoaderMap
{
protected:

  IMakerObjectCommon* mMakerObjectCommon;// создает объект заданного типа поведения

  typedef std::map<unsigned int,std::string> TMapIDName;
  TMapIDName mMapID;

  typedef std::vector<IBaseObjectCommon*> TVectorBaseObjectCommon;
  TVectorBaseObjectCommon mVectorObject;

public:

  TLoaderMap();
  virtual ~TLoaderMap();

  void SetMakerObjectCommon(IMakerObjectCommon* pMakerObjectCommon);
  
  int GetCountObject();
  IBaseObjectCommon* Get(int i);

  
  void Delete(IBaseObjectCommon* pObject);

  IBaseObjectCommon* LoadObject(unsigned int id_model);
  void LoadMap(unsigned int id_map);

  void LoadListMap();

protected:
  void Done();
  
  void PrepareMapPath();

};

#endif

