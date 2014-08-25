/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TreeJointH
#define TreeJointH

#include <vector>
#include <map>
#include <string>
#include "MathTools.h"
#include "TypeDef.h"


/*
По иерархии
 M(n) = M(n)*M(n-1)*..*M(0) - с самого низа на верх
 причем M(0) = M(root)
             Mroot                 - по именам a
          /   |   \  
         M1   M1   M1              -  b c d
         |         |  \          
         M2        M2  M2          -  e f g
                   | 
                   M3              -   h
       Mh = Mh*Mf*Md*Ma;
       World = Mh*world;
       WorldViewProj = World*View*Proj;
*/


class DllExport TTreeJoint
{
  bool flgNeedSetup; // отладка
  bool flgWasSort;   // отладка
public:
  TTreeJoint();
  ~TTreeJoint();
  //--------------------------------------------------
  // заготовка для настройки дерева
  struct TChild
  {
    std::string   name;
    nsMathTools::TMatrix16 matrix;
  };
  struct TPart
  {
    std::string name;
    int numUse;// номер башни например
    std::vector<TChild*> vectorChild;
    ~TPart()
    {
      int cnt = vectorChild.size();
      for(int i = 0 ; i < cnt ; i++)
        delete vectorChild[i];
    }
    TPart& operator =(const TPart& p)
    {
      name = p.name;
      numUse = p.numUse;
      int cnt = p.vectorChild.size();
      for(int i = 0 ; i < cnt ; i++)
      {
        TChild* pChild = new TChild;
        *pChild = *p.vectorChild[i];
        vectorChild.push_back(pChild);
      }
      return *this;
    }
  };
  struct TLoadedJoint
  {
    // матрица root, относительно него все строится
    nsMathTools::TMatrix16 world;
    std::string root;   // название корня
    std::vector<TPart*> vectorPart;// части для соединения, одна из этих частей всегда root (по имени)
    ~TLoadedJoint()
    {
      int cnt = vectorPart.size();
      for(int i = 0 ; i < cnt ; i++)
        delete vectorPart[i];
    }
    TLoadedJoint& operator =(const TLoadedJoint& l)
    {
      world = l.world;
      root  = l.root;
      int cnt = l.vectorPart.size();
      for(int i = 0 ; i < cnt ; i++)
      {
        TPart* pPart = new TPart;
        *pPart = *l.vectorPart[i];
        vectorPart.push_back(pPart);
      }
      return *this;
    }
  };
  //--------------------------------------------------
  // INTERFACE
  // Начальная настройка
  // 1. Setup(..)
  // 2. SetOrderMatrixByName(..)
  // 3. GetMatrix(..)
  // ...
  // Изменение одной из матриц
  // N. ChangeMatrix(..)
  // N+1. GetMatrix(..)
  // ...
  // M. SetDefault()
  // M+1. GetMatrix(..)
  //----------------------
  typedef std::map<std::string, int> TNumUseMap;

  void Setup(TLoadedJoint* pLoadedTree,TNumUseMap* mapUse);// +

  int GetCountPart();// +
  void SetOrderMatrixByName(std::vector<std::string>* order);// вызвать до вызова ChangeMatrix и GetMatrix // +
  
  // умножить матрицу по-умолчанию на новую матрицу и произвести изменения по всем детям
  void ChangeMatrix(std::string& name, nsMathTools::TMatrix16* matrix, bool def = true);// +
  // заполнить матрицей
  void GetMatrix(std::vector<nsMathTools::TMatrix16*>* matrix);// +
  // сбросить все матрицы в дефолт
  void SetDefault(); // +

  void operator = (TTreeJoint& v);
protected:
  
  void Done();
protected:

  struct TNodeJoint
  {
    TNodeJoint* pParent;
    std::vector<TNodeJoint*> mVectorChild;
    std::string   name;
    nsMathTools::TMatrix16 matrixDef; // то что считали с файла настроек
    nsMathTools::TMatrix16 matrix;    // эта матрица получается умножением матрицы по-умолчанию на заданную матрицу через метод ChangeMatrix
    nsMathTools::TMatrix16 matrix_pro;// произведение по иерархии
    
    TNodeJoint()
    {
      SetMatrixIdentity(&matrixDef);
      pParent = NULL;
      SetMatrixDef();
    }
    void SetMatrixDef(){matrix = matrixDef;}
  };
  
  TNodeJoint* mRoot;// корень есть всегда

  std::vector<TNodeJoint*> mVectorNode;// общее кол-во

  TLoadedJoint* mLoadedTree;// временно при Setup-е
  TNumUseMap* mMapUse;
  //------------------------------------------------------
  void ProductAllMatrix();
  void ProductChild(TNodeJoint* pNode);
  void ProductUp(TNodeJoint* pNode);


  void FindBranch(TPart* pPart, TNodeJoint* pParent);
};

#endif
