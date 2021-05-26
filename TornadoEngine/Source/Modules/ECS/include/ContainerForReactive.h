/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "Entity.h"
#include <list>
#include <vector>
#include <type_traits>

#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/dll/smart_library.hpp>
#include <boost/dll/import_class.hpp>
#include <boost/dll/shared_library.hpp>

#include "TypeDef.h"
#include "RunTimeTypeIndex.h"
#include "SingletonManager.h"

#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"
#include "CallBackRegistrator.h"
#include "ColanderVector.h"
#include "ComplexType.h"

namespace nsECSFramework
{
    struct TSubscriberInfo
    {
        TEntityIdVectorRise eidVec;
    };

    struct TComponentEventsCollector
    {
        std::vector<TSubscriberInfo*> subscriberList;
    };

    class TContainerForReactive
    {
        TColanderVector<TComponentEventsCollector*> mComponentInfoVector;

        std::vector<TSubscriberInfo*> mSubscribers;
    public:
        int Register(int componentIndex)
        {
            auto pSubscriber = new TSubscriberInfo();
            mSubscribers.push_back(pSubscriber);
            auto registerId = mSubscribers.size() - 1;

            auto pCollector = mComponentInfoVector[componentIndex];
            if ( pCollector == nullptr ) {
                pCollector = new TComponentEventsCollector();
                mComponentInfoVector[componentIndex] = pCollector;
            }
            pCollector->subscriberList.push_back(pSubscriber);
            return (int) registerId;
        }
        void Set(int componentIndex, TEntityID data)
        {
            auto pCollector = mComponentInfoVector[componentIndex];
            if ( pCollector == nullptr ) {
                return;
            }
            for ( auto& pSubscriber : pCollector->subscriberList )
                pSubscriber->eidVec.Append(data);
        }

        typedef std::function<void(TEntityIdVectorRise&)> TFunc;
        void Get(int registerId, TFunc func)
        {
            auto& vec = mSubscribers[registerId]->eidVec;
            func(vec);
            vec.Clear();
        }

        virtual ~TContainerForReactive()
        {
            for ( auto p : mSubscribers ) {
                delete p;
            }
            mSubscribers.clear();

            int size = mComponentInfoVector.Size();
            for ( int i = 0; i < size; i++ ) {
                auto pCollector = mComponentInfoVector[i];
                delete pCollector;
            }
        }
    };
}