/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <memory>

#include "BaseStruct.h"

namespace nsBS
{
    struct TTestStruct : public TBaseStruct
    {
        TBaseStruct baseStruct;
        TBaseStruct* pBaseStruct = nullptr;
        std::shared_ptr<TBaseStruct> spBaseStruct = std::shared_ptr<TBaseStruct>(new TBaseStruct());

        std::string password;
        unsigned short port = 0;
        bool flag = false;
        double floating = 112313.123;

        // array
        std::set<std::string> strSet;
        std::set<int> intSet;
        std::list<bool> boolList;
        std::list<int> numList;
        std::list<double> doubleList;
        std::vector<int> numVector;
        std::vector<double> doubleVector;
        std::vector<std::string> strVector;

        // ser array
        std::vector<TBaseStruct> baseVec;
        std::vector<TBaseStruct*> basePtrVec;
        std::vector<std::shared_ptr<TBaseStruct>> baseSPVec;

        // map
        std::map<int, int> intIntMap;
        std::map<int, bool> intBoolMap;
        std::map<int, double> intDoubleMap;
        std::map<int, std::string> intStrMap;

        std::map<int, std::map<int, std::string>> intIntStrMap;

        std::map<std::string, std::string> strStrMap;
        std::map<std::string, int> strIntMap;
        std::map<std::string, double> strDoubleMap;
        std::map<std::string, bool> strBoolMap;

        // map
        std::map<std::string, TBaseStruct> strBaseMap;
        std::map<std::string, TBaseStruct*> strBasePtrMap;
        std::map<std::string, std::shared_ptr<TBaseStruct>> strBaseSPMap;

        std::map<int, TBaseStruct> intBaseMap;
        std::map<int, TBaseStruct*> intBasePtrMap;
        std::map<int, std::shared_ptr<TBaseStruct>> intBaseSPMap;

        // complex types
        std::vector<std::vector<int>> intArrArr;
        std::vector<std::vector<std::string>> strArrArr;

        std::map<std::string, std::vector<std::string>> strArrMap;

        std::vector<std::map<std::string, std::string>> strMapArr;
        std::map<std::string, std::map<std::string, std::string>> strMapMap;

        std::vector<std::vector<TBaseStruct>> objArrArr;
        std::vector<std::vector<TBaseStruct*>> ptrObjArrArr;
        std::vector<std::vector<std::shared_ptr<TBaseStruct>>> spObjArrArr;

        std::vector<std::map<std::string, TBaseStruct>> objMapArr;
        std::vector<std::map<std::string, TBaseStruct*>> ptrObjMapArr;
        std::vector<std::map<std::string, std::shared_ptr<TBaseStruct>>> spObjMapArr;

        std::map<std::string, std::map<std::string, TBaseStruct>> objMapMap;
        std::map<std::string, std::map<std::string, TBaseStruct*>> ptrObjMapMap;
        std::map<std::string, std::map<std::string, std::shared_ptr<TBaseStruct>>> spObjMapMap;

        std::map<std::string, std::list<int>> intListMap;
        std::map<std::string, std::list<std::vector<int>>> intListVecMap;
        std::list<std::map<std::string, int>> intMapList;

        std::map<int, std::vector<int>> intVecMap;
        std::vector<std::map<int, int>> intMapVec;

        // super complex
        std::map<int, std::vector<std::map<int, std::vector<std::map<int, std::map<int, std::vector<std::vector<int>>>>>>>> colossalMember;
        std::map<int, std::map<int, std::map<int, std::map<int, int>>>> intSuperMap;
        std::vector<std::vector<std::vector<std::vector<int>>>> intSuperVec;
        std::list<std::list<std::list<std::list<bool>>>> boolSuperList;
    };
}
