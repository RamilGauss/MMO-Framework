/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IAccessDBH
#define IAccessDBH

#include <string>

// прототип работы с базой данных, ( возможно требует корректировки )

class IAccessDB
{
public:
	IAccessDB(){};
	virtual ~IAccessDB() = 0;
	
	// какой вариант Open лучше подходит?
	virtual bool Open(char* nameDB, int sizeName) = 0;
	virtual bool Open(char* ip, int sizeIP, unsigned short port) = 0;// например, ip="11.12.13.14" (IPv4) или ip="1.2.3.4.5.6" (IPv6)
	virtual void Close() = 0;
	
	virtual bool Login(char* login, int sizeLogin, char* password, int sizePassword) = 0;// login="root" password="12345678"
	virtual void Logoff() = 0;

	// отправить запрос в БД
	virtual bool Write(char* p, int size) = 0;// bool или void ?
	// проверка наличия ответа на запрос
	virtual int GetReadSize() = 0;// узнать размер ответа
	virtual bool Read(char* p, int size) = 0;// должно быть size=GetReadSize()
	
	virtual void Work() = 0;// дать квант процессора для внутренних нужд базы данных
	
	// есть ли ошибки
	enum{eNoError=0,}
	virtual int GetError() = 0;// если нет ошибок, то вернёт 0
	virtual std::string GetError() = 0;
	
	virtual void ClearError() = 0;
};

#endif
