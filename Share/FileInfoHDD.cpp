/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "FileInfoHDD.h"

TFileInfoHDD::TFileInfoHDD()
{
	pFile = NULL;
}
//------------------------------------------------------------------
TFileInfoHDD::~TFileInfoHDD()
{
	Close();
}
//------------------------------------------------------------------
bool TFileInfoHDD::IsOpen()
{
  return (pFile!=NULL);
}
//------------------------------------------------------------------
void TFileInfoHDD::Close()
{
	if(pFile==NULL) return;
	fclose(pFile);
	pFile = NULL;
}
//------------------------------------------------------------------
void TFileInfoHDD::GetName(std::string& path_name)
{
	if(IsOpen()==false)
		return;
	// первый тип разделителя
	int index = sPath.rfind('\\');
	if(index==-1)
	{
		// второй тип разделителя
		index = sPath.rfind('/');
	}
	path_name = sPath.data() + index + 1;
}
//------------------------------------------------------------------
void TFileInfoHDD::GetPath(std::string& path_name)
{
	if(IsOpen()==false)
		return;
	path_name = sPath;
}
//------------------------------------------------------------------
void TFileInfoHDD::GetFullPathName(std::string& path_name)
{
	path_name = "";

	if(IsOpen()==false)
		return;
	char full[MAX_PATH];
	if( _fullpath( full, sPath.data(), MAX_PATH ) != NULL )
		path_name = full;
}
//------------------------------------------------------------------

