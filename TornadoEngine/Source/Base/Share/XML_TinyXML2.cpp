/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "XML_TinyXML2.h"

using namespace std;
using namespace tinyxml2;

TXML_TinyXML2::TXML_TinyXML2()
{
  mCurrentElement = NULL;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::Load(const char* sPath)
{
  mPathDoc = sPath;

  XMLError error = mDoc.LoadFile(sPath);
  if(error!=XML_SUCCESS)
    return false;
  mCurrentElement = mDoc.RootElement();
  return true;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::IsOpen()
{
  return (mCurrentElement!=NULL);
}
//------------------------------------------------------------------
// операции с секциями
int TXML_TinyXML2::GetCountSection(const char* name)
{
  int cntElem = 0;
  XMLElement* pElement = mCurrentElement;
  while(pElement)
  {
    if(name==NULL)
      cntElem++;
    else
    {
      const char* sName = pElement->Value();
      if(strcmp(name,sName)==0)
        cntElem++;
    }
    pElement = pElement->NextSiblingElement();
  }
  return cntElem;
}
//------------------------------------------------------------------
// навигация
bool TXML_TinyXML2::EnterSection(const char* name, int num)
{
  if(mCurrentElement==NULL)
    return false;
  if(name==NULL) return false;
  int cntElem = 0;
  XMLElement* pElement = mCurrentElement;
  while(pElement)
  { 
    const char* sName = pElement->Value();
    if(strcmp(name,sName)==0)
    {
      if(num==cntElem)
      {
        mCurrentElement = pElement->FirstChildElement();
        return true;
      }
      cntElem++;
    }
    pElement = pElement->NextSiblingElement();
  }
  return false;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::LeaveSection()
{
  if(mCurrentElement==NULL)
    return false;
  XMLElement* pPrevElement = mCurrentElement->Parent()->ToElement();
  if(pPrevElement==NULL)
    return false;
  mCurrentElement = pPrevElement;
  return true;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::AddSectionAndEnter(const char* name)
{
  XMLElement* pNewElement = mDoc.NewElement(name);
  if(pNewElement)
  {
    pNewElement->SetText("");
    XMLNode* pNode = NULL;
    if(mCurrentElement->Parent()==NULL)
      pNode = mDoc.InsertEndChild(pNewElement);
    else
      pNode = mCurrentElement->Parent()->InsertEndChild(pNewElement);
    
    //mCurrentElement = pNode->ToElement()->FirstChildElement();
    return true;
  }
  return false;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::AddSectionAndEnter(const char *,// name 
                                       int ,//numAttr 
                                       TAttrInfo *)//pAttribs
{
  //mMarkup.SavePos();

  //bool res = mMarkup.AddElem(name, " ");
  //for(int iAttr = 0; iAttr < numAttr; iAttr++)
  //{
  //  res &= mMarkup.SetAttrib(pAttribs[iAttr].Name.data(), pAttribs[iAttr].Value.data());
  //  if (!res) 
  //    break;
  //}

  ////вызов mMarkup.RestorePos(); не делать что бы остаться тут же
  //return res;
  return false;
}
//------------------------------------------------------------------
// изменение кол-ва
bool TXML_TinyXML2::AddSection(const char* name)
{
  XMLElement* pNewElement = mDoc.NewElement(name);
  if(pNewElement)
  {
    pNewElement->SetText("");
    if(mCurrentElement==NULL || mCurrentElement->Parent()==NULL)
      mDoc.InsertEndChild(pNewElement);
    else
      mCurrentElement->Parent()->InsertEndChild(pNewElement);
    if(mCurrentElement==NULL)
      mCurrentElement = mDoc.FirstChildElement();
    return true;
  }
  return false;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::AddSection(const char *name, int numAttr, TAttrInfo *pAttribs)
{
  XMLElement* pNewElement = mDoc.NewElement(name);
  if(pNewElement)
  {
    pNewElement->SetText("");
    for(int iAttr = 0; iAttr < numAttr; iAttr++)
      pNewElement->SetAttribute(pAttribs[iAttr].Name.data(), 
                                pAttribs[iAttr].Value.data());

    if(mCurrentElement->Parent()==NULL)
      mDoc.InsertEndChild(pNewElement);
    else
      mCurrentElement->Parent()->InsertEndChild(pNewElement);
    return true;
  }
  return false;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::RemoveSection(const char* /*name*/, int /*num*/)
{
  /*bool res = false;
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
  return res;*/
  return false;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::WriteSection(const char* name, int num, string buffer)
{
  XMLElement* pElement = mCurrentElement;
  int cntElem = 0;
  while(pElement)
  {
    const char* sValue = pElement->Value();
    if(strcmp(sValue,name)==0)
    {
      if(num==cntElem)
      {
        pElement->SetText(buffer.data());
        return true;
      }
      cntElem++;
    }
    pElement = pElement->NextSiblingElement();
  }
  return false;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::WriteSection(int index, string buffer)
{
  XMLElement* pElement = mCurrentElement;
  int cntElem = 0;
  while(pElement)
  {
    if(index==cntElem)
    {
      pElement->SetText(buffer.data());
      return true;
    }
    cntElem++;
    pElement = pElement->NextSiblingElement();
  }
  return false;
}
//------------------------------------------------------------------
// чтение
string TXML_TinyXML2::ReadSection(const char* name, int num)
{
  string content;
  XMLElement* pElement = mCurrentElement;
  int cntElem = 0;
  while(pElement)
  {
    const char* sValue = pElement->Value();
    if(strcmp(sValue,name)==0)
    {
      if(num==cntElem)
      {
        const char* pContent = pElement->GetText();
        if(pContent)
          content = pContent;
        break;
      }
      cntElem++;
    }
    pElement = pElement->NextSiblingElement();
  }
  return content;
}
//------------------------------------------------------------------
string TXML_TinyXML2::ReadSection(int index)
{
  string content;
  XMLElement* pElement = mCurrentElement;
  int cntElem = 0;
  while(pElement)
  {
    if(index==cntElem)
    {
      const char* pContent = pElement->GetText();
      if(pContent)
        content = pContent;
      break;
    }
    cntElem++;
    pElement = pElement->NextSiblingElement();
  }
  return content;
}
//------------------------------------------------------------------
string TXML_TinyXML2::GetNameSection(int index)
{
  string name;
  int cntElem = 0;
  XMLElement* pElement = mCurrentElement;
  while(pElement)
  {
    if(index==cntElem)
    {
      name = pElement->Value();
      break;
    }
    cntElem++;
    pElement = pElement->NextSiblingElement();
  }
  return name;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::Save(const char* sPath)
{
  if(sPath==NULL)
    sPath = mPathDoc.data();
  XMLError error = mDoc.SaveFile(sPath);
  return (error==XML_SUCCESS);
}
//------------------------------------------------------------------
void TXML_TinyXML2::ResetPos()
{
  mCurrentElement = mDoc.RootElement();
}
//------------------------------------------------------------------
bool TXML_TinyXML2::WriteSectionAttr(const char* /*name*/, int /*num*/, const char* /*nameAttr*/, string /*buffer*/)
{
  /*mMarkup.SavePos();
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
  return res;*/
  return false;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::WriteSectionAttr(int /*index*/, const char* /*nameAttr*/, string /*buffer*/)
{
  /*mMarkup.SavePos();
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
  return res;*/
  return false;
}
//------------------------------------------------------------------
// чтение
string TXML_TinyXML2::ReadSectionAttr(const char* /*name*/, int /*num*/, const char* /*nameAttr*/)
{
  string content;
  /*mMarkup.SavePos();

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

  mMarkup.RestorePos();*/
  return content;
}
//------------------------------------------------------------------
string TXML_TinyXML2::ReadSectionAttr(int /*index*/, const char* /*nameAttr*/)
{
  string content;
  /*mMarkup.SavePos();

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

  mMarkup.RestorePos();*/
  return content;
}
//------------------------------------------------------------------
bool TXML_TinyXML2::AddXMLDeclaration( const char* /*strDecl*/ )
{
  //return mMarkup.AddNode(CMarkup::MNT_PROCESSING_INSTRUCTION, strDecl);
  return false;
}
//------------------------------------------------------------------
