/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef XML_TinyXML2H
#define XML_TinyXML2H

#include "IXML.h"
#include "tinyxml2.h"

/*
  реализация XML-парсера на tinyxml2.
*/

class TXML_TinyXML2 : public IXML
{
protected:
  tinyxml2::XMLDocument mDoc;
  tinyxml2::XMLElement* mCurrentElement;

  std::string mPathDoc;
public:
  TXML_TinyXML2();
  virtual ~TXML_TinyXML2(){};

  virtual bool Load(const char* sPath);
  virtual bool IsOpen();
  // операции с секциями
  
  // навигация
  virtual void ResetPos();
  virtual int  GetCountSection(const char* name = NULL);
  virtual std::string GetNameSection(int index);
  virtual bool EnterSection(const char* name, int num);
  virtual bool LeaveSection();
  // изменение кол-ва
  virtual bool AddSectionAndEnter(const char* name);
  virtual bool AddSectionAndEnter(const char *name, int numAttr, TAttrInfo *pAttribs);
  virtual bool AddSection(const char* name);
  virtual bool AddSection(const char *name, int numAttr, TAttrInfo *pAttribs);
  virtual bool RemoveSection(const char* name, int num);

  // изменение содержимого
  virtual bool AddXMLDeclaration(const char* strDecl);

  virtual bool WriteSectionAttr(const char* name, int num, const char* nameAttr, std::string buffer);
  virtual bool WriteSection(const char* name, int num, std::string buffer);
  
  virtual bool WriteSectionAttr(int index, const char* nameAttr, std::string buffer);
  virtual bool WriteSection(int index, std::string buffer);
  // чтение
  virtual std::string ReadSectionAttr(const char* name, int num, const char* nameAttr );
  virtual std::string ReadSection(const char* name, int num);
  
  virtual std::string ReadSectionAttr(int index, const char* nameAttr );
  virtual std::string ReadSection(int index);

  virtual bool Save(const char* sPath = NULL);
};

#endif