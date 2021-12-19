/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <ECS/include/EntityManager.h>

namespace nsTornadoEngine
{
	class TPrefabObjectConstructor
	{
	public:
		void ClearAll();

		nsECSFramework::TEntityID Instance(const std::string& prefabGuid);
		bool Attach(nsECSFramework::TEntityID eid,
			const std::string& objectGuid, const std::string& prefabGuid);
	};
}