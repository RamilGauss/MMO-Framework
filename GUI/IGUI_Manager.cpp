/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IGUI_Manager.h"

using namespace std;

IGUI_ManagerForm::IGUI_ManagerForm()
{
}
//-------------------------------------------------------------------
IGUI_ManagerForm::~IGUI_ManagerForm()
{
  Clear();
}
//-------------------------------------------------------------------
void IGUI_ManagerForm::Add(std::string& name, void* pForm)
{
  mMapNameForm.insert( bmStrPtr::value_type(name, pForm) );
}
//-------------------------------------------------------------------
void* IGUI_ManagerForm::GetFormByName(string& name)
{
  void* p = NULL;
  const bmStrPtr::left_iterator fit = mMapNameForm.left.find(name);
  if(fit!=mMapNameForm.left.end())
    p = fit->second;
  return p;
}
//-------------------------------------------------------------------
string IGUI_ManagerForm::GetNameForm(void* pForm)
{
  string str;
  const bmStrPtr::right_iterator fit = mMapNameForm.right.find(pForm);
  if(fit!=mMapNameForm.right.end())
    str = fit->second;
  return str;
}
//-------------------------------------------------------------------
void IGUI_ManagerForm::RemoveFormByName(string name)
{
  mMapNameForm.left.erase(name);
}
//-------------------------------------------------------------------
void IGUI_ManagerForm::RemoveForm(void* pForm)
{
  mMapNameForm.right.erase(pForm);
}
//-------------------------------------------------------------------
void IGUI_ManagerForm::Clear()
{
  mMapNameForm.clear();
}
//-------------------------------------------------------------------
