/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerForm.h"

using namespace std;

TManagerForm::TManagerForm()
{
}
//-------------------------------------------------------------------
TManagerForm::~TManagerForm()
{
  Clear();
}
//-------------------------------------------------------------------
void TManagerForm::Add(std::string& name, void* pForm)
{
  mMapNameForm.insert( bmStrPtr::value_type(name, pForm) );
}
//-------------------------------------------------------------------
void* TManagerForm::GetFormByName(string& name)
{
  void* p = NULL;
  const bmStrPtr::left_iterator fit = mMapNameForm.left.find(name);
  if(fit!=mMapNameForm.left.end())
    p = fit->second;
  return p;
}
//-------------------------------------------------------------------
string TManagerForm::GetNameForm(void* pForm)
{
  string str;
  const bmStrPtr::right_iterator fit = mMapNameForm.right.find(pForm);
  if(fit!=mMapNameForm.right.end())
    str = fit->second;
  return str;
}
//-------------------------------------------------------------------
void TManagerForm::RemoveFormByName(string name)
{
  mMapNameForm.left.erase(name);
}
//-------------------------------------------------------------------
void TManagerForm::RemoveForm(void* pForm)
{
  mMapNameForm.right.erase(pForm);
}
//-------------------------------------------------------------------
void TManagerForm::Clear()
{
  mMapNameForm.clear();
}
//-------------------------------------------------------------------
