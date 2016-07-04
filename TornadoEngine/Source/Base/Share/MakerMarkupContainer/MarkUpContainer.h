/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MarkUpContainerH
#define MarkUpContainerH

#include "IMarkUpContainer.h"

#include <map>
#include <string>
#include <vector>
#include "ContainerTypes.h"
#include "BreakPacket.h"

class TMarkUpContainer : public IMarkUpContainer
{
  // Элемент - это набор описаний (доступ по индексу)
  // Описание - именованная структура (в соответствии с разметкой), набор элементов (доступ по имени)
  // DescPrivate("Root") ->[ Elem[0](DescPrivate("A"), DescPrivate("B")), 
  //                         Elem[1](DescPrivate("A"), DescPrivate("B")) ]

  struct TDescPrivate;
  struct TElem;
  
  typedef std::vector<TDescPrivate*>           TVectorPtrDescPrivate;
  typedef std::vector<TElem*>                  TVectorPtrElem;

  typedef std::map<std::string, TDescPrivate*> TMapStrDescPrivate;
  typedef TMapStrDescPrivate::iterator         TMapStrDescPrivateIt;
  typedef TMapStrDescPrivate::value_type       TMapStrDescPrivateVT;

  struct TElem
  {
    TDescPrivate*         pMasterDesc;
    TVectorPtrDescPrivate vecSlaveDesc;
    TMapStrDescPrivate    mapNameDesc;

    TElem();
    ~TElem();

    void AddData(TBreakPacket* pBP);
    int  Set(char* p, int size);
  };
  struct TDescPrivate
  {
    IMarkUpContainer::TDesc* pDesc;// описание группы нужно для помещения элементов внутрь группы

    TElem*         pMasterElem;
    TVectorPtrElem vecSlaveElem;// индексация

    TContainer data;// данные этого элемента - если const - просто кусок памяти, массив - счетчик
    std::string typeConst;// если константа, то тип данных

    TDescPrivate();
    ~TDescPrivate();

    void AddData(TBreakPacket* pBP);
    IMarkUpContainer::eType GetTypeDescByIndex(int indexDesc);
    IMarkUpContainer::eType GetSelfType();
    void DeleteAllElem();
    void AddElem();
    int  Set(char* p, int size);
  };
  TElem* mRootElem;
  TElem* mCurElem;

  TBreakPacket mBP;
public:
  TMarkUpContainer();
  virtual ~TMarkUpContainer();

  virtual void SetMarkUp(TDesc* pDesc);

  virtual void  EnterRoot();
  virtual bool  Enter(const char* name, int indexElem);
  virtual void  Leave();

  virtual int   GetCountDesc();
  virtual std::string GetNameDesc(int indexDesc);
  virtual eType GetTypeDesc(int indexDesc);

  virtual void  SetCount(int indexDesc, int cnt);
  virtual int   GetCount(int indexDesc);
  virtual void  SetCount(const char* name, int cnt);
  virtual int   GetCount(const char* name);
  virtual void* GetPtrConst(int indexDesc);
  virtual void* GetPtrConst(const char* name);
  virtual int   GetSizeConst(int indexDesc);
  virtual int   GetSizeConst(const char* name);
  virtual std::string GetTypeConst(int indexDesc);
  virtual std::string GetTypeConst(const char* name);

  virtual void  Collect();
  virtual void* GetPtr();
  virtual int   GetSize();

  virtual int   Set(void* p, int size);
protected:
  typedef std::vector<TDescPrivate> TVectorDesc;
  TVectorDesc mVectorSection;

private:

};

#endif

