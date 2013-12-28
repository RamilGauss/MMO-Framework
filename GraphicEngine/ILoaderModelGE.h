/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ILoaderObjectDXH
#define ILoaderObjectDXH

#include "Struct3D.h"
#include <vector>
#include "IXML.h"

class ILoaderModelGE
{
public:
  struct TDefGroup
  {
		bool         flgUseCubeMap;
    std::string  strPathShader;// относительный путь
    std::string  strTechnique;
    std::wstring strTexture;
    std::string  strName;
    int          mNumUse;

    void* pMesh;

    nsStruct3D::TVector3 vAmbient;
    nsStruct3D::TVector3 vDiffuse;
    nsStruct3D::TVector3 vSpecular;

    int  nShininess;

    bool bSpecular;

    unsigned char mTypeLOD;
    bool          mflgNormal;

    TDefGroup()
    {
      pMesh     = NULL;

      nShininess = 0;
      bSpecular  = false;

      mTypeLOD   = 0;
      mflgNormal = true;
			flgUseCubeMap = false;
    }
  };

protected:
  float mLOD;
  
  std::vector<TDefGroup*> mVectorGroup;

public:
  enum{
    eUndefID = -1,
  };

  ILoaderModelGE();
  virtual ~ILoaderModelGE();

  TDefGroup* GetGroup(int i){return mVectorGroup[i];}
  // после загрузки становятся доступными
  float GetLOD();
  int GetCountGroup();

public:

  virtual bool Load(wchar_t* strFilenameData);

protected:
  
  void Done();

  void UpPath(char* sPath);

protected:

  char pStrPathShader[MAX_PATH];
  char pStrPathTexture[MAX_PATH];
  char pStrFilenameData[MAX_PATH];
  char pStrPathPrimitive[MAX_PATH];
  char pStrFilenameDataMain[MAX_PATH];

  IXML*     mXML;

protected:
  bool LoadMainFile();
  bool LoadFileResource();
  bool LoadPart(int i);
  bool LoadVector(const char* key,nsStruct3D::TVector3& vector);
  bool LoadVector4(const char* key,nsStruct3D::TVector4& vector4);

  virtual bool SetupMesh(TDefGroup *mArrDefGroup);
  
  virtual void* LoadMesh(const char* strPathPrimitives) = 0;
};


#endif