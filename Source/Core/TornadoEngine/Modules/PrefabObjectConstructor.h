/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <ECS/include/EntityManager.h>

#include "ParentGuidComponent.h"
#include "NameComponent.h"
#include "GuidComponent.h"
#include "TransformComponent.h"
#include "ResourceContentMap.h"
#include "ResourceContent.h"
#include "ObjectManager.h"
#include "HierarchyHelper.h"

namespace nsTornadoEngine
{
	class DllExport TPrefabObjectConstructor : public TObjectManager
	{
		nsECSFramework::TEntityManager mInnerEntityManager;
	public:
		TPrefabObjectConstructor();

		void Setup(const std::list<std::string>& libPathList);

		// Returns RootEid
		nsECSFramework::TEntityID InstantiateByGuid(const std::string& prefabGuid);
		nsECSFramework::TEntityID InstatiateByAbsPath(const std::string& absPath);

		bool AttachByGuid(nsECSFramework::TEntityID prefabChildEid, const std::string& prefabGuid);
		bool AttachByPath(nsECSFramework::TEntityID prefabChildEid, const std::string& absPath);
		bool Attach(nsECSFramework::TEntityID prefabChildEid, nsECSFramework::TEntityID prefabRootEid);

		// Bloody roots!
		nsECSFramework::TEntityList GetRoots();

		nsECSFramework::TEntityID GetParent(nsECSFramework::TEntityID eid);
		nsECSFramework::TEntityList GetChilds(nsECSFramework::TEntityID eid);
		
		// Get first or none
		nsECSFramework::TEntityID GetChildByName(nsECSFramework::TEntityID eid, const std::string& name);
		nsECSFramework::TEntityID GetBrotherByName(nsECSFramework::TEntityID eid, const std::string& name);

		// Get all with name
		nsECSFramework::TEntityList GetChildsByName(nsECSFramework::TEntityID eid, const std::string& name);
		nsECSFramework::TEntityList GetBrothersByName(nsECSFramework::TEntityID eid, const std::string& name);

		nsECSFramework::TEntityManager* EntMng();

	private:
		void SetEntityManager(nsECSFramework::TEntityManager* entMng) override;
	};
}