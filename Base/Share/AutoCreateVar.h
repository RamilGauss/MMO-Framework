/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AutoCreateVarH
#define AutoCreateVarH
//------------------------------------------------------------------------------
template <class TItem>
class TAutoCreateVarT
{
  TItem* p;
public:
  TAutoCreateVarT()   { p = 0; }
  ~TAutoCreateVarT()  { Destroy(); }

  TItem& Ref()        { return *Ptr(); }

  TItem* Ptr()        { return p ? p : (p = new TItem); }
  TItem* operator->() { return p ? p : (p = new TItem); }

  void Destroy()
  {
    delete p;
    p = 0;
  }
};
//------------------------------------------------------------------------------

#endif // AutoCreateVarH
