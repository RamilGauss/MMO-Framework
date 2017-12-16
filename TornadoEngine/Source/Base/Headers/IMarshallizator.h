/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IMarshallizatorH
#define IMarshallizatorH

#include "CallBackRegistrator.h"
#include "PushMaster.h"
#include "PopMaster.h"
#include "TypeDef.h"

class DllExport IMarshallizator
{
protected:
  TPushMaster mPushMaster;
  TPopMaster mPopMaster;

  short mID;

  // минимальный размер сериализованного контейнера, при котором используется компрессия LZ4
  int mMinSizeUseLZ4;
public:
  TContainer Serialize( ISerializable* pSer );
  // newObject - возвращаемый объект создан new, не забудь вызвать delete!
  ISerializable* Deserialize( TContainer* pContainer, bool newObject );

  // При десериализации будет вызван соответсвующий callback
  // Warning! Если использовать этот метод, то другим программистам будет сложно отследить логику программы.
  // Использовать только если без этого никак.
  void DeserializeCallback( TContainer* pContainer, bool newObject );
protected:
  virtual ISerializable* PrivateDeserialize( TContainer* pContainer, bool newObject, bool useCallback ) = 0;
protected:
  template<typename T>
  ISerializable* CommonDeserialize( bool newObject, TCallBackRegistrator1<T*>* pCB, T* pObj, bool useCallback );
};
//--------------------------------------------------------------------
template<typename T>
ISerializable* IMarshallizator::CommonDeserialize( bool newObject, TCallBackRegistrator1<T*>* pCB, T* pObj, bool useCallback )
{
  if( useCallback && pCB->RegisteredCount()==0 )
    return pObj;// нет потребителя события

  if( newObject )
    pObj = new T();

  pObj->Deserialize( &mPopMaster );

  if( useCallback )
    pCB->Notify( pObj );
  return pObj;
}
//--------------------------------------------------------------------
#endif
