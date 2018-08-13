/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FormManager.h"

using namespace std;

TFormManager::TFormManager()
{
}
//-------------------------------------------------------------------
TFormManager::~TFormManager()
{
  Clear();
}
//-------------------------------------------------------------------
void TFormManager::Add(std::string& name, void* pForm)
{
  mMapNameForm.insert( bmStrPtr::value_type(name, pForm) );
}
//-------------------------------------------------------------------
void* TFormManager::GetFormByName(string& name)
{
  void* p = NULL;
  const bmStrPtr::left_iterator fit = mMapNameForm.left.find(name);
  if(fit!=mMapNameForm.left.end())
    p = fit->second;
  return p;
}
//-------------------------------------------------------------------
string TFormManager::GetNameForm(void* pForm)
{
  string str;
  const bmStrPtr::right_iterator fit = mMapNameForm.right.find(pForm);
  if(fit!=mMapNameForm.right.end())
    str = fit->second;
  return str;
}
//-------------------------------------------------------------------
void TFormManager::RemoveFormByName(string name)
{
  mMapNameForm.left.erase(name);
}
//-------------------------------------------------------------------
void TFormManager::RemoveForm(void* pForm)
{
  mMapNameForm.right.erase(pForm);
}
//-------------------------------------------------------------------
void TFormManager::Clear()
{
  mMapNameForm.clear();
}
//-------------------------------------------------------------------
