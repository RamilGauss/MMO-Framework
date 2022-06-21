///*
//Author: Gudakov Ramil Sergeevich a.k.a. Gauss
//Гудаков Рамиль Сергеевич
//Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
//See for more information LICENSE.md.
//*/
//
//#pragma once
//
//#include "TypeDef.h"
//
//#include <string>
//#include <ECS/include/EntityManager.h>
//
//namespace nsTornadoEngine
//{
//    class DllExport THierarchyHelper
//    {
//        nsECSFramework::TEntityManager* mEntMng = nullptr;
//    public:
//        void SetEntMng(nsECSFramework::TEntityManager* entMng);
//
//        [[nodiscard]]
//        nsECSFramework::TEntityID GetParent(nsECSFramework::TEntityID eid);
//        [[nodiscard]]
//        nsECSFramework::TEntityList GetChilds(nsECSFramework::TEntityID eid);
//
//        void GetAllTree(nsECSFramework::TEntityID eid, nsECSFramework::TEntityList& eids);
//        void GetAllChilds(nsECSFramework::TEntityID eid, nsECSFramework::TEntityList& eids);
//
//        [[nodiscard]]
//        nsECSFramework::TEntityID GetBrotherByName(nsECSFramework::TEntityID eid,
//            const std::string& brotherName);
//        [[nodiscard]]
//        nsECSFramework::TEntityList GetBrothersByName(nsECSFramework::TEntityID eid,
//            const std::string& brotherName);
//
//        [[nodiscard]]
//        nsECSFramework::TEntityID GetChildByName(nsECSFramework::TEntityID eid,
//            const std::string& childName);
//        [[nodiscard]]
//        nsECSFramework::TEntityList GetChildsByName(nsECSFramework::TEntityID eid,
//            const std::string& childName);
//    };
//}