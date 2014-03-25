/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef LoaderObjectGeneralH
#define LoaderObjectGeneralH


#include "IMakerObjectGeneral.h"
#include <map>
#include <vector>

class IBaseObjectGeneral;

class TLoaderObjectGeneral
{
protected:

  IMakerObjectGeneral* mMakerObjectGeneral;// создает объект заданного типа поведения

  typedef std::map<unsigned int,std::string> TMapIDName;
  TMapIDName mMapID;

  typedef std::vector<IBaseObjectGeneral*> TVectorBaseObjectGeneral;
  TVectorBaseObjectGeneral mVectorObject;

public:

  TLoaderObjectGeneral();
  virtual ~TLoaderObjectGeneral();

  void SetMakerObjectGeneral(IMakerObjectGeneral* pMakerObjectGeneral);
  
  int GetCountObject();
  IBaseObjectGeneral* Get(int i);

  
  void Delete(IBaseObjectGeneral* pObject);

  IBaseObjectGeneral* LoadObject(unsigned int id_model);
  void LoadMap(unsigned int id_map);

  void LoadListMap();

protected:
  void Done();
  
  void PrepareMapPath();

};

#endif

