/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DEF_MACRO_MAKER_PREPARE_H
#define DEF_MACRO_MAKER_PREPARE_H

// подготовка ( то, что для использования, смотри ниже )
#define MACRO_MAKER_H_DECL(DECL, NameInterface, NameRealize, param_for_decl) \
class I##NameInterface; \
class DECL TMaker##NameRealize \
{ \
public: \
	I##NameInterface* New(param_for_decl); \
	void Delete(I##NameInterface*); \
};
//---------------------------------------------------------
#define MACRO_MAKER_H(NameInterface, NameRealize, param_for_decl) \
	MACRO_MAKER_H_DECL(,NameInterface, NameRealize, param_for_decl)
//---------------------------------------------------------
#ifdef WIN32
#define MACRO_MAKER_H_EXPORT(decl, NameInterface, NameRealize, param_for_decl) \
	MACRO_MAKER_H_DECL(decl, NameInterface, NameRealize, param_for_decl)
#else
#define MACRO_MAKER_H_EXPORT(decl, NameInterface, NameRealize, param_for_decl) \
	MACRO_MAKER_H_DECL(,NameInterface, NameRealize, param_for_decl)
#endif
//---------------------------------------------------------
//---------------------------------------------------------
#define MACRO_MAKER_CPP(NameInterface, NameRealize, ClassRealize, param_for_decl, param_for_def) \
I##NameInterface* TMaker##NameRealize::New(param_for_decl) \
{ \
	return new T##ClassRealize(param_for_def); \
} \
void TMaker##NameRealize::Delete(I##NameInterface* ptr) \
{ \
	delete ptr;\
}

#endif