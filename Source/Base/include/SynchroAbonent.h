/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <map>
#include <vector>

#include "IContainer.h"
#include "SynchroPoint.h"

class DllExport TSynchroAbonent
{
    int mSelfID;

    TSynchroPoint* mSynchroPoint;

    // кэш данных от точки синхронизации
    typedef std::map<int, IContainer*> TMapIntPtr;
    typedef TMapIntPtr::iterator TMapIntPtrIt;
    typedef TMapIntPtr::value_type TMapIntPtrVT;

    TMapIntPtr mMapID_LastEvent;

public:
    TSynchroAbonent();
    virtual ~TSynchroAbonent();

    // 1. Первое что нужно сделать при работе абонента - задать точку синхронизации
    void SetSynchroPoint(TSynchroPoint* p);
    // 2. Задать свой собственный идентификатор
    void SetSelfID(int id);

    // Добавить событие с/без копирования
    void AddEventCopy(int id_recv, void* data, int size);
    template<typename T>
    void AddEventWithoutCopy(int id_recv, T* pObject);
    void AddEventWithoutCopy(int id_recv, IContainer* pC);

    // забрать событие от определенного абонента, удалять нельзя
    IContainer* GetEvent(int& id_sender);
protected:
    void AddCache(IContainer* pC, int id_sender);
};
//------------------------------------------------------------------------------
template<typename T>
void TSynchroAbonent::AddEventWithoutCopy(int id_recv, T* pObject)
{
    mSynchroPoint->AddEventWithoutCopy<T>(mSelfID, id_recv, pObject);
}
