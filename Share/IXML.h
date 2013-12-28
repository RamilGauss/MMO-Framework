/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IXMLH
#define IXMLH

#include <stddef.h>
#include <string>
#include "TypeDef.h"
#include "ShareMisc.h"

struct SHARE_EI TAttrInfo
{
  std::string Name;
  std::string Value;
};

class SHARE_EI IXML
{
public:
  IXML(){};
  virtual ~IXML(){};

  virtual bool Load(const char* sPath) = 0;
  virtual bool IsOpen() = 0;
  // операции с секциями
  
  // навигация
  virtual void ResetPos() = 0;
  virtual int  GetCountSection(const char* name = NULL) = 0;
  virtual std::string GetNameSection(int index) = 0;
  virtual bool EnterSection(const char* name, int num) = 0;
  virtual bool LeaveSection() = 0;
  // изменение кол-ва
  virtual bool AddChildSection(const char* childName, int num, const char* name);
  virtual bool RemoveChildSection(const char* childName, int numChild, const char* name, int num);

  virtual bool AddSectionAndEnter(const char* name) = 0;
  virtual bool AddSectionAndEnter(const char *name, int numAttr, TAttrInfo *pAttribs) = 0;

  virtual bool AddSection(const char* name) = 0;
  virtual bool AddSection(const char *name, int attrCount, TAttrInfo *pAttribs) = 0;
  virtual bool RemoveSection(const char* name, int num) = 0;

  // изменение содержимого
  virtual bool AddXMLDeclaration(const char* strDecl) = 0;

  virtual bool WriteSectionAttr(const char* name, int num, const char* nameAttr, std::string buffer) = 0;
  virtual bool WriteSection(const char* name, int num, std::string buffer) = 0;

  virtual bool WriteSectionAttr(int index, const char* nameAttr, std::string buffer) = 0;
  virtual bool WriteSection(int index, std::string buffer) = 0;
  // чтение
  virtual std::string ReadSectionAttr(const char* name, int num, const char* nameAttr) = 0;
  virtual std::string ReadSection(const char* name, int num) = 0;

  virtual std::string ReadSectionAttr(int index, const char* nameAttr) = 0;
  virtual std::string ReadSection(int index) = 0;
  // сбросить содержимое изменений в файл
  virtual bool Save(const char* sPath = NULL) = 0;

  // инвариантное чтение
  bool ReadFloat(const char* name, int num, float& v);
  bool ReadInt(const char* name, int num, int& v);
  bool ReadUint(const char* name, int num, unsigned int& v);
  bool ReadFloat3(const char* name, int num, float* v3);// разделитель ";"
  bool ReadFloat4(const char* name, int num, float* v4);

  bool ReadFloat(int index, float& v);
  bool ReadInt(int index, int& v);
  bool ReadUint(int index, unsigned int& v);
  bool ReadFloat3(int index, float* v3);// разделитель ";"
  bool ReadFloat4(int index, float* v4);

  // инвариантная запись
  bool WriteFloat(const char* name, int num, float v);
  bool WriteInt(const char* name, int num, int v);
  bool WriteUint(const char* name, int num, unsigned int v);
  bool WriteFloat3(const char* name, int num, float* v3);// разделитель ";"
  bool WriteFloat4(const char* name, int num, float* v4);

  bool WriteFloat(int index, float v);
  bool WriteInt(int index, int v);
  bool WriteUint(int index, unsigned int v);
  bool WriteFloat3(int index, float* v3);// разделитель ";"
  bool WriteFloat4(int index, float* v4);

};

#endif