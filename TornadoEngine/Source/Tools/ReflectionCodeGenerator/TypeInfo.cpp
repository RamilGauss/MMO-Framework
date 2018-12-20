/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TypeInfo.h"

std::string TTypeInfo::GetNameSpace()// all namespaces: A::B::...::Z
{
  std::string summa;
  auto size = mNamespaceVec.size();
  for ( auto i = 0; i < size; i++ )
  {
    summa += mNamespaceVec [i];
    if ( i != size - 1 )
      summa += "::";
  }
  return summa;
}
//-----------------------------------------------------------------------------------------
void TTypeInfo::AddMember( TMemberInfo& memberInfo )
{
  auto memberInfoPtr = TMemberInfoPtr( new TMemberInfo() );
  memberInfoPtr.get() [0] = memberInfo;
  mMemberMap.insert( TAccessLevelMemberInfoPtrMap::value_type( memberInfo.mAccessLevel, memberInfoPtr ) );
}
//-----------------------------------------------------------------------------------------
