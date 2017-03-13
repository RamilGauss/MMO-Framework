/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AccessDB_PostgreSQL.h"

TAccessDB_PostgreSQL::TAccessDB_PostgreSQL()
{

}
//---------------------------------------------------------------------------------------
TAccessDB_PostgreSQL::~TAccessDB_PostgreSQL()
{

}
//---------------------------------------------------------------------------------------
bool TAccessDB_PostgreSQL::Open(char* nameDB, int sizeName)
{
	return false;
}
//---------------------------------------------------------------------------------------
bool TAccessDB_PostgreSQL::Open(char* ip, int sizeIP, unsigned short port)
{
	return false;
}
//---------------------------------------------------------------------------------------
void TAccessDB_PostgreSQL::Close()
{

}
//---------------------------------------------------------------------------------------
bool TAccessDB_PostgreSQL::Login(char* login, int sizeLogin, char* password, int sizePassword)
{
	return false;
}
//---------------------------------------------------------------------------------------
void TAccessDB_PostgreSQL::Logoff()
{

}
//---------------------------------------------------------------------------------------
bool TAccessDB_PostgreSQL::Write(char* p, int size)
{
	return false;
}
//---------------------------------------------------------------------------------------
int TAccessDB_PostgreSQL::GetReadSize()
{
	return 0;
}
//---------------------------------------------------------------------------------------
bool TAccessDB_PostgreSQL::Read(char* p, int size)
{
	return false;
}
//---------------------------------------------------------------------------------------
void TAccessDB_PostgreSQL::Work()
{

}
//---------------------------------------------------------------------------------------
int TAccessDB_PostgreSQL::GetError()
{
	return eNoError;
}
//---------------------------------------------------------------------------------------
std::string TAccessDB_PostgreSQL::GetError()
{
	return "";
}
//---------------------------------------------------------------------------------------
void TAccessDB_PostgreSQL::ClearError()
{

}
//---------------------------------------------------------------------------------------
