/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Operation_Model.h"
#include <stddef.h>

TOperation_Model::TOperation_Model()
{
  mPatternModel = NULL;
}
//-----------------------------------------------------------------------------------
TOperation_Model::~TOperation_Model()
{

}
//-----------------------------------------------------------------------------------
void TOperation_Model::SetPattern(TBehaviourPattern* pPattern)
{
  mPatternModel = (TPattern_Model*)pPattern;
}
//-----------------------------------------------------------------------------------
