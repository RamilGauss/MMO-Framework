/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

//-------------------------------------------------------------
// For example:
// Register(&object, &TClass::Method);
// Register(&object, [this](){this->Foo();});
// Unregister(&object);
//-------------------------------------------------------------

#include <map>
#include <list>
#include <functional>
#include <memory.h>

template <typename ... Args>
class TCallbackPool
{
    template <typename ... Args>
    class TDescFunc
    {
        static const size_t POINTER_SIZE = sizeof(int*);
        char mFunc[POINTER_SIZE] = { 0 };
        char mObject[POINTER_SIZE] = { 0 };
    public:
        template<typename F, class A1>
        void Set(F pFunc, A1 pObject)
        {
            memcpy(&mFunc[0], &pFunc, sizeof(F));
            memcpy(&mObject[0], &pObject, sizeof(A1));
        }
        void Call(Args ... args)
        {
            if (mLambda != nullptr) {
                mLambda(args...);
                return;
            }

            class TF {};
            typedef void (TF::* TFunc)(Args ...);
            TF* pT = nullptr;
            TFunc tf;
            memcpy(&tf, &mFunc, sizeof(TFunc));
            memcpy(&pT, &mObject, sizeof(TF*));

            (pT->*tf)(args ...);
        }

        std::function<void(Args...)> mLambda;
    };

    using TDescFuncList = std::list<TDescFunc<Args ...>>;
    using TPtrDescListMap = std::unordered_map<void*, TDescFuncList>;

    TPtrDescListMap mObjFuncMap;
public:
    void Register(void* pObject, std::function<void(Args...)> func)
    {
        auto& descList = SureFind(pObject);
        TDescFunc<Args ...> desc;
        desc.mLambda = func;
        descList.push_back(desc);
    }
    template<class T>
    void Register(T* pObject, void (T::* pFunc)(Args ...))
    {
        auto& descList = SureFind(pObject);
        TDescFunc<Args ...> desc;
        desc.Set(pFunc, pObject);
        descList.push_back(desc);
    }
    void Unregister(void* pObject)
    {
        mObjFuncMap.erase(pObject);
    }
    void Notify(Args ... args)
    {
        for (auto& pair : mObjFuncMap) {
            for (auto& desc : pair.second) {
                desc.Call(args ...);
            }
        }
    }
    int RegisteredCount()
    {
        return (int)mObjFuncMap.size();
    }
    void Clear()
    {
        mObjFuncMap.clear();
    }
    bool IsRegistered(void* pObject)
    {
        return mObjFuncMap.find(pObject) != mObjFuncMap.end();
    }
private:
    TDescFuncList& SureFind(void* pObject)
    {
        auto fit = mObjFuncMap.find(pObject);
        if (fit == mObjFuncMap.end()) {
            mObjFuncMap.insert({ pObject, TDescFuncList() });
            fit = mObjFuncMap.find(pObject);
        }
        return fit->second;
    }
};

