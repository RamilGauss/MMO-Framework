/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <memory>

#include "Simple.hpp"

namespace nsComplex
{
    struct Y
    {
        nsSimple::X x;
        nsSimple::X* px = nullptr;
        std::shared_ptr<nsSimple::X> shx;

        std::list<nsSimple::X> x_l;
        std::list<nsSimple::X*> px_l;
        std::list<std::shared_ptr<nsSimple::X>> shx_l;

        std::list<std::list<nsSimple::X>> x_ll;
        std::list<std::list<nsSimple::X*>> px_ll;
        std::list<std::list<std::shared_ptr<nsSimple::X>>> shx_ll;

        std::vector<nsSimple::X> x_v;
        std::vector<nsSimple::X*> px_v;
        std::vector<std::shared_ptr<nsSimple::X>> shx_v;

        std::map<int, nsSimple::X> ix_m;
        std::map<int, nsSimple::X*> ipx_m;
        std::map<int, std::shared_ptr<nsSimple::X>> ishx_m;

        std::map<std::string, nsSimple::X> strx_m;
        std::map<std::string, nsSimple::X*> strpx_m;
        std::map<std::string, std::shared_ptr<nsSimple::X>> strshx_m;

        bool operator == (const Y& other) const;

        bool IsObjectsEquals(const Y& other) const;
        bool IsEqualLists(const Y& other) const;
        bool IsEqualVectors(const Y& other) const;
        bool IsObjectsEqualsMaps(const Y& other) const;

        void Fill();

        virtual ~Y();
    };
}
