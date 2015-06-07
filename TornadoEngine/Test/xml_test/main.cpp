/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IXML.h"
#include "MakerXML.h"

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


IXML* pXML = NULL;
int countTab = -1;
//-------------------------------------------------------------------------------------
void Tab()
{
  for( int i = 0 ; i < countTab ; i++)
    printf("\t");
}
//-------------------------------------------------------------------------------------
void PrintContentSection()
{
  countTab++;
  int countSection = pXML->GetCountSection();
  for( int i = 0 ; i < countSection ; i++)
  {
    std::string nameSection = pXML->GetNameSection(i);
    Tab();
    printf("<%s", nameSection.data());
    // атрибуты
    for( int j = 0 ; ; j++)
    {
      TAttrInfo attrInfo;
      if(pXML->ReadSectionAttrByIndex(i, j, attrInfo)==false)
        break;
      char sNameSectionAttrAnsi[200];
#ifdef WIN32
      //convert_utf8_to_windows1251(attrInfo.Value.data(), sNameSectionAttrAnsi, sizeof(sNameSectionAttrAnsi));
      strcpy(sNameSectionAttrAnsi, attrInfo.Value.data());
#else
      strcpy(sNameSectionAttrAnsi, attrInfo.Value.data());
#endif
      printf(" %s=\"%s\"", attrInfo.Name.data(), sNameSectionAttrAnsi);
    }
    std::string contentSection = pXML->ReadSection(i);
    if(pXML->EnterSection(i))
    {
      if(pXML->GetCountSection())
      {
        printf(">\n");
        PrintContentSection();
        pXML->LeaveSection();
        Tab();
        printf("</%s>\n", nameSection.data());
      }
      else
      {
        pXML->LeaveSection();
        if(contentSection.length())
          printf(">%s</%s>\n", contentSection.data(), nameSection.data());
        else
          printf("/>\n");
      }
    }
    else
      printf("/>\n");
  }
  countTab--;
}
//-------------------------------------------------------------------------------------
void MakeRandomXML()
{
  if(pXML->EnterSection(0)==false)
    return;
  int countSection = pXML->GetCountSection();
  for( int i = 0 ; i < countSection ; i++)
    pXML->RemoveSection("city", 0);

  countSection = 5 + rand()%25;
  for( int i = 0 ; i < countSection ; i++)
  {
    char s[100];
    sprintf(s, "%d", i);
    TAttrInfo attrInfo[2];
    attrInfo[0].Name  = "id";
    attrInfo[0].Value = s;

    int populity = rand()%10000;
    sprintf(s, "%d", populity);
    attrInfo[1].Name  = "populity";
    attrInfo[1].Value = s;
    pXML->AddSection("city", sizeof(attrInfo)/sizeof(TAttrInfo), &attrInfo[0]);
  }
  pXML->Save();
  pXML->LeaveSection();
}
//-------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
  srand(time(NULL));
  TMakerXML maker;
  pXML = maker.New();

  if(pXML->Load("make.xml"))
    MakeRandomXML();

  if(pXML->Load("make.xml"))
    PrintContentSection();

  maker.Delete(pXML);
  return 0;
}
//-------------------------------------------------------------------------------------
