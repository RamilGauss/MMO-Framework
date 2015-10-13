#ifndef IMarkUpContainerH
#define IMarkUpContainerH

/*
    Гибкий контейнер.
  Например: Root( C, Arr( C )) - пакет состоит из константной части и массива констант
                 "A" "D" "E"
=========================================================================
  // разметка
  IMarkUpContainer::TDesc* pRoot = new IMarkUpContainer::TDesc;

  IMarkUpContainer::TDesc* pDA = new IMarkUpContainer::TDesc;
  pDA->name = "A";
  pDA->size = sizeof(int);
  pRoot->list.push_back(pDA);

  IMarkUpContainer::TDesc* pDD = new IMarkUpContainer::TDesc;
  pDD->name = "D";
  pDD->size = sizeof(int);
    IMarkUpContainer::TDesc* pDE = new IMarkUpContainer::TDesc;
    pDE->name = "E";
    pDE->size = sizeof(int);
  pDD->list.push_back(pDE);
  
  pRoot->list.push_back(pDD);
=========================================================================
  IMarkUpContainer* pMarkUp = new ...;
  pMarkUp->SetMarkUp(pRoot);
=========================================================================
  // навигация, доступ и изменение
  int* pA = (int*)pMarkUp->GetPtrConst("A");
  int сnt = pMarkUp->GetCount();
  for(int i = 0 ; i < сnt ; i++)
  {
    if(pMarkUp->Enter("B", i))
    {
      int* pElem = (int*)pMarkUp->GetPtrConst("E");
      *pElem = i;
      pMarkUp->Leave();
    }
  }
=========================================================================
  // после формирования 
  pMarkUp->Collect();// с учетом всех изменений
  void* pPacket  = pMarkUp->GetPtr();
  int sizePacket = pMarkUp->GetSize();
=========================================================================
  // получения пакета по сетке
  void* pPacketFromNet = ...;
  int sizePacketFromNet = ...;
  pMarkUp->Set(pPacketFromNet, sizePacketFromNet);
=========================================================================
*/

#include <string>
#include <list>

class IMarkUpContainer
{
public:
  typedef enum
  {
    eUndef,
    eArr,   // массив элементов
    eRoot,  // мнимый массив с 1 элементом size==0
    eConst, // область постоянной длины
  }eType;
  struct TDesc
  {
    std::string name;
    int size; // байт
    std::list<TDesc*> list;
    TDesc();
    ~TDesc();
    TDesc* CloneHierarhy();
  };
  //--------------------------------------------------------------------------------------
  IMarkUpContainer();
  virtual ~IMarkUpContainer();

  // разметка контейнера, копирует информацию из pDesc
  virtual void SetMarkUp(TDesc* pDesc) = 0;

  // навигация
  virtual void  EnterRoot()                            = 0;
  // войти в массив
  virtual bool  Enter(const char* name, int indexElem) = 0;
  virtual void  Leave()                                = 0;

  // когда находимся внутри массива
  virtual int   GetCountDesc()                   = 0;
  virtual std::string GetNameDesc(int indexDesc) = 0;
  virtual eType GetTypeDesc(int indexDesc)       = 0;
  
  virtual void  SetCount(int indexDesc, int cnt)    = 0;
  virtual int   GetCount(int indexDesc)             = 0;
  virtual void  SetCount(const char* name, int cnt) = 0;
  virtual int   GetCount(const char* name)          = 0;
  virtual void* GetPtrConst(int indexDesc)          = 0;
  virtual void* GetPtrConst(const char* name)       = 0;
  virtual int   GetSizeConst(int indexDesc)         = 0;
  virtual int   GetSizeConst(const char* name)      = 0;

  // результат - дать область памяти готового пакета
  virtual void  Collect() = 0;
  virtual void* GetPtr()  = 0;
  virtual int   GetSize() = 0;
  
  // занести в разметку размеры элементов
  virtual int   Set(void* p, int size) = 0;
protected:
  TDesc* mRoot;
};

#endif

