/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AccessDB_PostgreSQLH
#define AccessDB_PostgreSQLH

#include "IAccessDB.h"
// прототип работы с базой данных, ( возможно требует корректировки )

class TAccessDB_PostgreSQL
{
public:
	TAccessDB_PostgreSQL();
	virtual ~TAccessDB_PostgreSQL();
	
	// какой вариант Open лучше подходит?
	virtual bool Open(char* nameDB, int sizeName);
	virtual bool Open(char* ip, int sizeIP, unsigned short port);// например, ip="11.12.13.14" (IPv4) или ip="1.2.3.4.5.6" (IPv6)
	virtual void Close();
	
	virtual bool Login(char* login, int sizeLogin, char* password, int sizePassword);// login="root" password="12345678"
	virtual void Logoff();

	// отправить запрос в БД
	virtual bool Write(char* p, int size);// bool или void ?
	// проверка наличия ответа на запрос
	virtual int GetReadSize();// узнать размер ответа
	virtual bool Read(char* p, int size);// должно быть size=GetReadSize()
	
	virtual void Work();// дать квант процессора для внутренних нужд базы данных
	
	// есть ли ошибки
	enum{eNoError=0,}
	virtual int GetError();// если нет ошибок, то вернёт 0
	virtual std::string GetError();
	
	virtual void ClearError();
};

#endif
