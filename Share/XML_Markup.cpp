/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "XML_Markup.h"

using namespace std;

bool TXML_Markup::Load(const char* sPath)
{
  mStrPath.insert(0, sPath );
  return mMarkup.Load(sPath);
}
//------------------------------------------------------------------
bool TXML_Markup::IsOpen()
{
  return mMarkup.IsWellFormed();
}
//------------------------------------------------------------------
// операции с секциями
int TXML_Markup::GetCountSection(const char* name)
{
  mMarkup.SavePos();

  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    if(name==NULL)
      cntElem++;
    else
    {
      string sName = mMarkup.GetTagName();
      if(strcmp(name,sName.data())==0)
        cntElem++;
    }
  }
  mMarkup.RestorePos();
  return cntElem;
}
//------------------------------------------------------------------
// навигация
bool TXML_Markup::EnterSection(const char* name, int num)
{
  if(name==NULL) return false;
  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    string sName = mMarkup.GetTagName();
    if(strcmp(name,sName.data())==0)
    {
      if(num==cntElem)
        return mMarkup.IntoElem();
      cntElem++;
    }
  }
  return false;
}
//------------------------------------------------------------------
bool TXML_Markup::LeaveSection()
{
  if(mMarkup.OutOfElem())
  {
    mMarkup.ResetMainPos();
    return true;
  }
  return false;
}
//------------------------------------------------------------------
bool TXML_Markup::AddSectionAndEnter(const char* name)
{
  mMarkup.SavePos();
  bool res = mMarkup.AddElem(name, " ");
  //вызов mMarkup.RestorePos(); не делать что бы остаться тут же
  return res;
}
//------------------------------------------------------------------
bool TXML_Markup::AddSectionAndEnter(const char *name, int numAttr, TAttrInfo *pAttribs)
{
  mMarkup.SavePos();

  bool res = mMarkup.AddElem(name, " ");
  for(int iAttr = 0; iAttr < numAttr; iAttr++)
  {
    res &= mMarkup.SetAttrib(pAttribs[iAttr].Name.data(), pAttribs[iAttr].Value.data());
    if (!res) 
      break;
  }

  //вызов mMarkup.RestorePos(); не делать что бы остаться тут же
  return res;
}
//------------------------------------------------------------------
// изменение кол-ва
bool TXML_Markup::AddSection(const char* name)
{
  mMarkup.SavePos();
  bool res = mMarkup.AddElem(name, " ");
  mMarkup.RestorePos();
  return res;
}
//------------------------------------------------------------------
bool TXML_Markup::AddSection(const char *name, int numAttr, TAttrInfo *pAttribs)
{
  mMarkup.SavePos();

    bool res = mMarkup.AddElem(name, " ");
    for(int iAttr = 0; iAttr < numAttr; iAttr++)
    {
      res &= mMarkup.SetAttrib(pAttribs[iAttr].Name.data(), pAttribs[iAttr].Value.data());
      if (!res) 
        break;
    }

  mMarkup.RestorePos();
  return res;
}
//------------------------------------------------------------------
bool TXML_Markup::RemoveSection(const char* name, int num)
{
  bool res = false;
  mMarkup.SavePos();
    
  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    string sName = mMarkup.GetTagName();
    if(strcmp(name,sName.data())==0)
    {
      if(num==cntElem)
      {
        res = mMarkup.RemoveElem();
        break;
      }
      cntElem++;
    }
  }

  mMarkup.RestorePos();
  return res;
}
//------------------------------------------------------------------
bool TXML_Markup::WriteSection(const char* name, int num, string buffer)
{
  mMarkup.SavePos();
  bool res = false;
  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    string sName = mMarkup.GetTagName();
    if(strcmp(name,sName.data())==0)
    {
      if(num==cntElem)
      {
        res = mMarkup.SetElemContent(buffer.data());
        break;
      }
      cntElem++;
    }
  }
  mMarkup.RestorePos();
  return res;
}
//------------------------------------------------------------------
bool TXML_Markup::WriteSection(int index, string buffer)
{
  mMarkup.SavePos();
  bool res = false;
  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    if(index==cntElem)
    {
      res = mMarkup.SetElemContent(buffer.data());
      break;
    }
    cntElem++;
  }
  mMarkup.RestorePos();
  return res;
}
//------------------------------------------------------------------
// чтение
string TXML_Markup::ReadSection(const char* name, int num)
{
  string content;
  mMarkup.SavePos();

  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    string sName = mMarkup.GetTagName();
    if(strcmp(name,sName.data())==0)
    {
      if(num==cntElem)
      {
        content = mMarkup.GetElemContent();
        break;
      }
      cntElem++;
    }
  }

  mMarkup.RestorePos();
  return content;
}
//------------------------------------------------------------------
string TXML_Markup::ReadSection(int index)
{
  string content;
  mMarkup.SavePos();

  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    if(index==cntElem)
    {
      content = mMarkup.GetElemContent();
      break;
    }
    cntElem++;
  }

  mMarkup.RestorePos();
  return content;
}
//------------------------------------------------------------------
string TXML_Markup::GetNameSection(int index)
{
  string name;
  mMarkup.SavePos();

  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    if(index==cntElem)
    {
      name = mMarkup.GetTagName();
      break;
    }
    cntElem++;
  }
  mMarkup.RestorePos();
  return name;
}
//------------------------------------------------------------------
bool TXML_Markup::Save(const char* sPath)
{
  if(sPath==NULL)
    sPath = mStrPath.data();
  return mMarkup.Save(sPath);
}
//------------------------------------------------------------------
void TXML_Markup::ResetPos()
{
  mMarkup.ResetPos();
}
//------------------------------------------------------------------
bool TXML_Markup::WriteSectionAttr(const char* name, int num, const char* nameAttr, string buffer)
{
  mMarkup.SavePos();
  bool res = false;
  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    string sName = mMarkup.GetTagName();
    if(strcmp(name,sName.data())==0)
    {
      if(num==cntElem)
      {
        res = mMarkup.SetAttrib(nameAttr,buffer.data());
        break;
      }
      cntElem++;
    }
  }
  mMarkup.RestorePos();
  return res;
}
//------------------------------------------------------------------
bool TXML_Markup::WriteSectionAttr(int index, const char* nameAttr, string buffer)
{
  mMarkup.SavePos();
  bool res = false;
  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    if(index==cntElem)
    {
      res = mMarkup.SetAttrib(nameAttr,buffer.data());
      break;
    }
    cntElem++;
  }
  mMarkup.RestorePos();
  return res;
}
//------------------------------------------------------------------
// чтение
string TXML_Markup::ReadSectionAttr(const char* name, int num, const char* nameAttr)
{
  string content;
  mMarkup.SavePos();

  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    string sName = mMarkup.GetTagName();
    if(strcmp(name,sName.data())==0)
    {
      if(num==cntElem)
      {
        content = mMarkup.GetAttrib(nameAttr);
        break;
      }
      cntElem++;
    }
  }

  mMarkup.RestorePos();
  return content;
}
//------------------------------------------------------------------
string TXML_Markup::ReadSectionAttr(int index, const char* nameAttr)
{
  string content;
  mMarkup.SavePos();

  int cntElem = 0;
  while(mMarkup.FindElem())
  { 
    if(index==cntElem)
    {
      content = mMarkup.GetAttrib(nameAttr);
      break;
    }
    cntElem++;
  }

  mMarkup.RestorePos();
  return content;
}
//------------------------------------------------------------------
bool TXML_Markup::AddXMLDeclaration( const char* strDecl )
{
  return mMarkup.AddNode(CMarkup::MNT_PROCESSING_INSTRUCTION, strDecl);
}
//------------------------------------------------------------------
