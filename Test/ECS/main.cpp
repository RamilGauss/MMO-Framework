/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <conio.h>

#include "EntityManager.h"
#include "VectorRise.h"
#include "HiTimer.h"
#include "ExecuteSystem.h"
#include "SingletonManager.h"

#ifdef _DEBUG
#define COUNT 10000
#else
#define COUNT 4000000
#endif

using namespace nsECSFramework;

class TDataComponent : public IComponent
{
};

class THasComponent : public IComponent
{
};

class TUniqueComponent : public IComponent
{
public:
    int mID;
    TUniqueComponent()
    {
    }
    TUniqueComponent(int id)
    {
        mID = id;
    }

    virtual bool IsLess(const IComponent* pOther) const override
    {
        auto p = (TUniqueComponent*) pOther;
        return mID < p->mID;
    }
    virtual bool IsEqual(const IComponent* pOther) const override
    {
        auto p = (TUniqueComponent*) pOther;
        return mID == p->mID;
    }
};

class TValueComponent : public IComponent
{
public:
    int mID;
    TValueComponent()
    {
    }
    TValueComponent(int id)
    {
        mID = id;
    }

    virtual bool IsLess(const IComponent* pOther) const override
    {
        auto p = (TValueComponent*) pOther;
        return mID < p->mID;
    }
    virtual bool IsEqual(const IComponent* pOther) const override
    {
        auto p = (TValueComponent*) pOther;
        return mID == p->mID;
    }

    bool operator < (const TValueComponent& other) const
    {
        return mID < other.mID;
    }
};

//class TASystem// : public TExecuteSystem
//{
//public:
//  void Handle( TEntityID id, A* pA )
//  {
//    printf( "" );
//  }
//};

TEntityManager g_EntMng;
std::list<TEntityID> g_Entities;
const int g_EntityCount = COUNT;
std::map<TValueComponent, int> m;
std::map<TValueComponent*, void*, ptr_less<TValueComponent*>> g_VMap;
std::map<TComplexType*, void*, ptr_less<TComplexType*>> g_CMap;


void CreateEntities()
{
    for ( int i = 0; i < g_EntityCount; i++ ) {
        auto eid = g_EntMng.CreateEntity();
        g_Entities.push_back(eid);
    }
}

void DestroyEntities()
{
    for ( auto eid : g_Entities ) {
        g_EntMng.DestroyEntity(eid);
    }
    g_Entities.clear();
}

template<typename Component>
void AddComponentToEntities()
{
    Component c;
    for ( auto eid : g_Entities ) {
        g_EntMng.SetComponent(eid, c);
    }
}

void AddUniqueComponentToEntities()
{
    TUniqueComponent c;
    for ( auto eid : g_Entities ) {
        c.mID++;
        g_EntMng.SetComponent(eid, c);
    }
}

void AddValueComponentToEntities()
{
    TValueComponent c;
    for ( auto eid : g_Entities ) {
        c.mID++;
        g_EntMng.SetComponent(eid, c);
    }
}

template<typename Component>
void RemoveComponentFromEntities()
{
    for ( auto eid : g_Entities ) {
        g_EntMng.RemoveComponent<Component>(eid);
    }
}

void AddInMap()
{
    TValueComponent key;
    for ( int i = 0; i < g_EntityCount; i++ ) {
        key.mID = i;
        m.insert({ key, i });
    }
}

void FindInMap()
{
    TValueComponent key;
    for ( int i = 0; i < g_EntityCount; i++ ) {
        key.mID = i;
        auto fit = m.find(key);
    }
}

void AddInComplexMap()
{
    for ( int i = 0; i < g_EntityCount; i++ ) {
        auto pValue = SingletonManager()->Get<TMemoryObjectPool<TValueComponent>>()->Pop();
        pValue->mID = i;
        auto pCT = SingletonManager()->Get<TMemoryObjectPool<TComplexType>>()->Pop();
        pCT->parts[0] = pValue;
        pCT->mComponentTypeIdentifierList.push_back(0);
        g_CMap.insert({ pCT, nullptr });
    }
}

void FindInComplexMap()
{
    for ( int i = 0; i < g_EntityCount; i++ ) {
        auto pValue = SingletonManager()->Get<TMemoryObjectPool<TValueComponent>>()->Pop();
        pValue->mID = i;
        auto pCT = SingletonManager()->Get<TMemoryObjectPool<TComplexType>>()->Pop();
        pCT->parts[0] = pValue;
        pCT->mComponentTypeIdentifierList.push_back(0);
        auto fit = g_CMap.find(pCT);
        // full emulation
        pCT->Done();
        SingletonManager()->Get<TMemoryObjectPool<TComplexType>>()->Push(pCT);
        SingletonManager()->Get<TMemoryObjectPool<TValueComponent>>()->Push((TValueComponent*) pValue);
    }
}

void RemoveFromComplexMap()
{
    for ( auto& key : g_CMap ) {
        auto pCT = key.first;
        auto pValue = pCT->parts[0];
        pCT->Done();

        SingletonManager()->Get<TMemoryObjectPool<TComplexType>>()->Push(pCT);
        SingletonManager()->Get<TMemoryObjectPool<TValueComponent>>()->Push((TValueComponent*) pValue);
    }

    g_CMap.clear();
}

void AddInValuePtrMap()
{
    for ( int i = 0; i < g_EntityCount; i++ ) {
        auto pValue = SingletonManager()->Get<TMemoryObjectPool<TValueComponent>>()->Pop();
        pValue->mID = i;
        g_VMap.insert({ pValue, nullptr });
    }
}

void FindInValuePtrMap()
{
    auto pValue = SingletonManager()->Get<TMemoryObjectPool<TValueComponent>>()->Pop();
    for ( int i = 0; i < g_EntityCount; i++ ) {
        pValue->mID = i;
        auto fit = g_VMap.find(pValue);
    }
    SingletonManager()->Get<TMemoryObjectPool<TValueComponent>>()->Push(pValue);
}

void RemoveFromValuePtrMap()
{
    for ( auto& key : g_VMap ) {
        auto pValue = key.first;
        SingletonManager()->Get<TMemoryObjectPool<TValueComponent>>()->Push(pValue);
    }

    g_CMap.clear();
}

float GetSpeedByTest(std::function<void()> testFunc, int count)
{
    auto start = ht_GetMSCount();

    testFunc();

    auto delta = ht_GetMSCount() - start;
    auto speed = (1000.0f * delta) / count;
    return speed;
}

int main()
{
    auto addInMap = GetSpeedByTest(AddInMap, g_EntityCount);
    auto findInMap = GetSpeedByTest(FindInMap, g_EntityCount);
    m.clear();
    printf("addInMap: %f, findInMap: %f\n", addInMap, findInMap);

    float addInComplexMap;
    float findInComplexMap;
    float removeFromComplexMap;

    float addInValuePtrMap;
    float findInValuePtrMap;
    float removeFromValuePtrMap;

    for ( int i = 0; i < 2; i++ ) {
        addInComplexMap = GetSpeedByTest(AddInComplexMap, g_EntityCount);
        findInComplexMap = GetSpeedByTest(FindInComplexMap, g_EntityCount);
        removeFromComplexMap = GetSpeedByTest(RemoveFromComplexMap, g_EntityCount);

        addInValuePtrMap = GetSpeedByTest(AddInValuePtrMap, g_EntityCount);
        findInValuePtrMap = GetSpeedByTest(FindInValuePtrMap, g_EntityCount);
        removeFromValuePtrMap = GetSpeedByTest(RemoveFromValuePtrMap, g_EntityCount);
    }

    printf("Complex map add: %f, find: %f, remove: %f\n", addInComplexMap, findInComplexMap, removeFromComplexMap);
    printf("Value ptr map add: %f, find: %f, remove: %f\n", addInValuePtrMap, findInValuePtrMap, removeFromValuePtrMap);

    g_EntMng.Setup();

    float createSpeed = 0;
    float destroySpeed = 0;

    float addDataSpeed = 0;
    float removeDataSpeed = 0;

    float addHasSpeed = 0;
    float removeHasSpeed = 0;

    float addUniqueSpeed = 0;
    float removeUniqueSpeed = 0;

    float addValueSpeed = 0;
    float removeValueSpeed = 0;

    for ( int i = 0; i < 2; i++ ) {
        createSpeed = GetSpeedByTest(CreateEntities, g_EntityCount);

        addDataSpeed = GetSpeedByTest(AddComponentToEntities<TDataComponent>, g_EntityCount);
        removeDataSpeed = GetSpeedByTest(RemoveComponentFromEntities<TDataComponent>, g_EntityCount);

        addHasSpeed = GetSpeedByTest(AddComponentToEntities<THasComponent>, g_EntityCount);
        removeHasSpeed = GetSpeedByTest(RemoveComponentFromEntities<THasComponent>, g_EntityCount);

        addUniqueSpeed = GetSpeedByTest(AddUniqueComponentToEntities, g_EntityCount);
        removeUniqueSpeed = GetSpeedByTest(RemoveComponentFromEntities<TUniqueComponent>, g_EntityCount);

        addValueSpeed = GetSpeedByTest(AddValueComponentToEntities, g_EntityCount);
        removeValueSpeed = GetSpeedByTest(RemoveComponentFromEntities<TValueComponent>, g_EntityCount);

        destroySpeed = GetSpeedByTest(DestroyEntities, g_EntityCount);
    }

    printf("Speed Entity us/entity:\n");

    printf("\t create = %f, destroy = %f \n",
        createSpeed, destroySpeed);

    printf("Data:\t\t add = %f, remove = %f \n",
        addDataSpeed, removeDataSpeed);

    printf("Has:\t\t add = %f, remove = %f \n",
        addHasSpeed, removeHasSpeed);

    printf("Unique:\t\t add = %f, remove = %f \n",
        addUniqueSpeed, removeUniqueSpeed);

    printf("Value:\t\t add = %f, remove = %f \n",
        addValueSpeed, removeValueSpeed);
    _getch();

    auto hasAList = g_EntMng.GetByHas<THasComponent>();
    TValueComponent valCom;
    auto valueAList = g_EntMng.GetByValue(valCom);
    TUniqueComponent uniCom;
    auto entByUnique = g_EntMng.GetByUnique(uniCom);

    //  auto pASystem = new TASystem();
    //
    //  entMng.OnAdd<A>( [pASystem]( TEntityManager::CallBackPtr<A>* pCB )
    //  {
    //    pCB->Register( &TASystem::Handle, pASystem );
    //  } );
    //
    //  entMng.OnAdd<A>( [pASystem]( TEntityManager::CallBackPtr<A>* pCB )
    //  {
    //    pCB->Unregister( pASystem );
    //  } );

    //auto world = new nsECSFramework::TWorld();
    //world->AddToConveyer<TProducerFeature>();
    ////world->AddToConveyer<TConsumerSystem>();// 1
    //     //world->AddToConveyer<TProducerFeature>();
    ////world->AddToConveyer<TConsumerSystem>();// 2
    //     //world->AddToConveyer<TPacketObserverSystem>();
    //world->AddToConveyer<TGroupedPacketSystem>();
    ////world->AddToConveyer<TInitSettingsSystem>();

    ////world->AddToConveyer<TMakeShuffleEntitiesSystem>();
    ////world->AddToConveyer<TViewShuffleEntitiesSystem>();

    //world->Init();
    //int testCount = 20;
    //while ( testCount-- > 0 )
    //{
    //  world->Update();
    //  printf( "----------------------------------------------------------------\n" );
    //}

    //printf( "Conveyer is stopped, press any key...\n" );

    //getchar();
    return 0;
}

/* Core i5:
addInMap: 0.230000, findInMap : 0.095000
  Complex map add : 0.920750, find : 0.606500, remove : 0.209000
  Value ptr map add : 0.209750, find : 0.120500, remove : 0.052250
  Speed Entity us / entity :
  create = 0.092750, destroy = 0.164000
  Data : add = 0.288250, remove = 0.241750
  Has : add = 0.422500, remove = 0.465250
  Unique : add = 0.702000, remove = 0.570250
  Value : add = 2.450000, remove = 1.332250
  */

  /*
  addInMap: 0.206750, findInMap: 0.087250
  Complex map add: 0.660500, find: 0.491000, remove: 0.194750
  Value ptr map add: 0.193000, find: 0.115750, remove: 0.048750
  Speed Entity us/entity:
           create = 0.079000, destroy = 0.143000
  Data:            add = 0.247000, remove = 0.211000
  Has:             add = 0.365750, remove = 0.390500
  Unique:          add = 0.606250, remove = 0.487750
  Value:           add = 1.892000, remove = 0.969750
  */

  /*
  addInMap: 0.200500, findInMap: 0.084750
  Complex map add: 0.503250, find: 0.361000, remove: 0.182250
  Value ptr map add: 0.183750, find: 0.109750, remove: 0.051000
  Speed Entity us/entity:
           create = 0.080000, destroy = 0.144500
  Data:            add = 0.252750, remove = 0.212000
  Has:             add = 0.364750, remove = 0.398250
  Unique:          add = 0.650250, remove = 0.499500
  Value:           add = 1.645500, remove = 0.959500
  */