/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Complex.hpp"

using namespace nsSimple;
using namespace nsComplex;

bool Y::operator == (const Y& other) const
{
    auto isEqualObjects = IsObjectsEquals(other);
    auto isEqualLists = IsEqualLists(other);
    auto isEqualVectors = IsEqualVectors(other);
    auto isEqualMaps = IsObjectsEqualsMaps(other);

    return isEqualObjects && isEqualLists && isEqualVectors && isEqualMaps;
}

void Y::Fill()
{
    x.Fill();
    px = new X();
    px->Fill();
    shx.reset(new X());
    shx->Fill();

    x_l = {x};
    px_l = {px};
    shx_l = {shx};

    x_ll = {{x}};
    px_ll = {{px}};
    shx_ll = {{shx}};

    x_v = {x};
    px_v = {px};
    shx_v = {shx};

    ix_m = {{42, x}};
    ipx_m = {{42, px}};
    ishx_m = {{42, shx}};

    strx_m = {{"str", x}};
    strpx_m = {{"str", px}};
    strshx_m = {{"str", shx}};
}

Y::~Y()
{
    delete px;
}

template<typename T>
bool IsEqualContainers(const T& t0, const T& t1)
{
    return std::equal(t0.begin(), t0.end(),
        t1.begin(), t1.end(),
        [](const auto& lhs, const auto& rhs) { return *lhs == *rhs; });
}

template<typename T>
bool IsEqualMaps(const T& t0, const T& t1)
{
    return std::equal(t0.begin(), t0.end(),
        t1.begin(), t1.end(),
        [](const auto& lhs, const auto& rhs) { return *(lhs.second) == *(rhs.second); });
}

template<typename T>
bool IsEqualContainersContainers(const T& t0, const T& t1)
{
    bool is_equals = t0.size() == t1.size();
    if (is_equals) {
        auto bit = t1.begin();
        for (auto& e : t0) {
            is_equals &= IsEqualContainers(e, *bit);
            bit++;
        }
    }
    return is_equals;
}

template<typename T>
bool IsPointersEqual(T& t0, T& t1)
{
    if (t0 == nullptr || t1 == nullptr) {
        if (t0 != nullptr || t1 != nullptr) {
            return false;
        }
    } else {
        return *t0 == *t1;
    }
    return true;
}


bool Y::IsObjectsEquals(const Y& other) const
{
    bool isPointersEqual = IsPointersEqual(px, other.px);
    bool isSmartPointersEqual = IsPointersEqual(shx, other.shx);

    return
        x == other.x &&
        isPointersEqual &&
        isSmartPointersEqual;
}

bool Y::IsEqualLists(const Y& other) const
{
    bool px_l_equals = IsEqualContainers(px_l, other.px_l);
    bool shx_l_equals = IsEqualContainers(shx_l, other.shx_l);

    bool px_ll_equals = IsEqualContainersContainers(px_ll, other.px_ll);
    bool shx_ll_equals = IsEqualContainersContainers(shx_ll, other.shx_ll);

    return
        x_l == other.x_l &&
        px_l_equals &&
        shx_l_equals &&

        x_ll == other.x_ll &&
        px_ll_equals &&
        shx_ll_equals;
}

bool Y::IsEqualVectors(const Y& other) const
{
    bool px_v_equals = IsEqualContainers(px_v, other.px_v);
    bool shx_v_equals = IsEqualContainers(shx_v, other.shx_v);

    return
        x_v == other.x_v &&
        px_v_equals &&
        shx_v_equals;
}

bool Y::IsObjectsEqualsMaps(const Y& other) const
{
    bool ipx_m_equals = IsEqualMaps(ipx_m, other.ipx_m);
    bool ishx_m_equals = IsEqualMaps(ishx_m, other.ishx_m);

    bool strpx_m_equals = IsEqualMaps(strpx_m, other.strpx_m);
    bool strshx_m_equals = IsEqualMaps(strshx_m, other.strshx_m);

    return
        ix_m == other.ix_m &&
        ipx_m_equals &&
        ishx_m_equals &&

        strx_m == other.strx_m &&
        strpx_m_equals &&
        strshx_m_equals;
}

