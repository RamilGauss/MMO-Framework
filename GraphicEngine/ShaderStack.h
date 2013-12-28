/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ShaderStackH
#define ShaderStackH

#include <string>
#include <vector>

#include "Container.h"

class TShaderStack
{
  struct TData
  {
    std::string name;
    TContainer c;
    void Set(char* p,int s)
    {
      c.SetData(p, s);
    }
  };
  
  std::vector<TData*> mVectorNameData;

public:
  TShaderStack();
  ~TShaderStack();

  int Count(){return mVectorNameData.size();}
  int Push(const char* nameValueIn, void* pDataIn, int sizeIn);

  int GetIndexByName(const char* name);

  void SetData(int index, void* pDataIn, int sizeIn);

  std::string GetName(int index);
  void* GetData(int index, int& size);

  void Done();

};

#endif