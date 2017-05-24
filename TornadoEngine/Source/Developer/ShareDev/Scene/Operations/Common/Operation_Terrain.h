/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Operation_PatternH
#define Operation_PatternH

#include "BaseOperation_Pattern.h"

class TPattern_Terrain;

class DllExport TOperation_Terrain : public TBaseOperation_Pattern
{
protected:

	TPattern_Terrain* mPatternTerrain;
public:

	TOperation_Terrain();
	virtual ~TOperation_Terrain();

	virtual void SetPattern(TBehaviourPattern* pPattern);
	// концепция работы с Operation: 
	//       вызов метода операции (поэтому интерфейс должен быть сформирован), 
	//       операция берёт данные из паттерна, производит работу,
	//       результат помещает в паттерн.
};

#endif
