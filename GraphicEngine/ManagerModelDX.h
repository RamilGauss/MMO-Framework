/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerModelH
#define ManagerModelH

#include <map>

#include "DXUT.h"

class TModelDX;
class TManagerResourceDX;

class TManagerModelDX
{

protected:
  IDirect3DDevice9* mD3dDevice;

  TManagerResourceDX* mManagerResourceDX;// отдать модели для получения ресурсов

public:
  TManagerModelDX();
  ~TManagerModelDX();

  void SetManagerResourceDX(TManagerResourceDX* managerResourceDX){mManagerResourceDX=managerResourceDX;}

  bool LoadListPath();

  void Setup(IDirect3DDevice9* pd3dDevice){mD3dDevice = pd3dDevice;};

  TModelDX* Find(unsigned int id);
  // список примитивов (оригиналы, которые используются в ObjectDX)
  TModelDX* Load(unsigned int id);

  void DestroyModel();
  void LostDevice();
  void ResetDevice();


/*
// при создании модели вызывать:
void ResetDevice();


порядок вызова при окончании использования
void OnLostDevice();
void OnDestroyDevice();

*/

protected:

  typedef std::map<unsigned int, std::string> TMapUintStr;
  typedef std::map<unsigned int, TModelDX*>   TMapUintPtr;

  TMapUintStr mMapPathModel;
  TMapUintPtr mMapLoadedModel;

  void Done();

  void PrepareForDX();

};

#endif