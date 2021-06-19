/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Simple.hpp"

using namespace nsSimple;

bool X::operator == (const X& other) const
{
    auto builtIn = IsEqualBuiltIn(other);
    auto lists = IsEqualLists(other);
    auto vectors = IsEqualVectors(other);
    auto sets = IsEqualSets(other);
    auto maps = IsEqualMaps(other);

    return builtIn && lists && vectors && sets && maps;
}

void X::Fill()
{
    // Built-in
    b = true;
    c = 42;
    uc = 42;
    s = 42;
    us = 42;
    i = 42;
    ui = 42;
    l = 42;
    ul = 42;
    ll = 42;
    ull = 42;
    f = 42;
    d = 42;
    i8 = 42;
    ui8 = 42;
    i16 = 42;
    ui16 = 42;
    i32 = 42;
    ui32 = 42;
    i64 = 42;
    ui64 = 42;
    str = "tornado";

    // List
    b_l = {true, false};
    i_l = {0, 42};
    d_l = {0, 42};
    str_l = {"hello", "world"};

    // List of vectors
    b_vl = {{false}, {true}};
    i_vl = {{0}, {42}};
    d_vl = {{0}, {42}};
    str_vl = {{"hello"}, {"world"}};

    // List of lists
    b_ll = {{false}, {true}};
    i_ll = {{0}, {42}};
    d_ll = {{0}, {42}};
    str_ll = {{"hello"}, {"world"}};

    // Vector
    b_v = {true, false};
    i_v = {0, 42};
    d_v = {0, 42};
    str_v = {"hello", "world"};

    // Vector of vectors
    b_vv = {{false}, {true}};
    i_vv = {{0}, {42}};
    d_vv = {{0}, {42}};
    str_vv = {{"hello"}, {"world"}};

    // Vector of lists
    b_lv = {{false}, {true}};
    i_lv = {{0}, {42}};
    d_lv = {{0}, {42}};
    str_lv = {{"hello"}, {"world"}};

    // Set
    i_s = {0, 42};
    str_s = {"hello", "world"};

    // Map of int as key
    ib_m = {{0, true}, {42, false}};
    ii_m = {{0, 0}, {42, 42}};
    id_m = {{0, 0}, {42, 42}};
    istr_m = {{0, "hello"}, {42, "world"}};

    // ... list as value
    i_bl_m = {{0,{true, false}}, {42, {false, true}}};
    i_il_m = {{0,{0, 0}}, {42, {42, 42}}};
    i_dl_m = {{0,{0, 0}}, {42, {42, 42}}};
    i_strl_m = {{0,{"h", "w"}}, {42, {"w", "w"}}};

    // ... vector as value
    i_bv_m = {{0,{true, false}}, {42, {false, true}}};
    i_iv_m = {{0,{0, 0}}, {42, {42, 42}}};
    i_dv_m = {{0,{0, 0}}, {42, {42, 42}}};
    i_strv_m = {{0,{"h", "w"}}, {42, {"w", "w"}}};

    // ... set as value
    i_is_m = {{0, {0}}, {42, {42}}};
    i_strs_m = {{0, {"h"}}, {42, {"w"}}};

    // ... map as value
    i_ibm_m = {{0, {{0, true}, {42, false}}}};
    i_iim_m = {{0, {{0, 42}, {42, 0}}}};
    i_idm_m = {{0, {{0, 42}, {42, 0}}}};
    i_istrm_m = {{0, {{0, "h"}, {42, "w"}}}};

    // ... map as value
    i_strbm_m = {{0, {{"h", true}, {"w", false}}}};
    i_strim_m = {{0, {{"h", 42}, {"w", 0}}}};
    i_strdm_m = {{0, {{"h", 42}, {"w", 0}}}};
    i_strstrm_m = {{0, {{"h", "h"}, {"w", "w"}}}};

    // Map of string as key
    strb_m = {{"h", true}, {"w", false}};
    stri_m = {{"h", 0}, {"w", 42}};
    strd_m = {{"h", 0}, {"w", 42}};
    strstr_m = {{"h", "h"}, {"w", "w"}};

    // ... vector as value
    str_bv_m = {{"h", {true}}, {"w",{false}}};
    str_iv_m = {{"h", {0}}, {"w",{42}}};
    str_dv_m = {{"h", {0}}, {"w",{42}}};
    str_strv_m = {{"h", {"h"}}, {"w",{"w"}}};

    // ... list as value
    str_bl_m = {{"h", {true}}, {"w",{false}}};
    str_il_m = {{"h", {0}}, {"w",{42}}};
    str_dl_m = {{"h", {0}}, {"w",{42}}};
    str_strl_m = {{"h", {"h"}}, {"w",{"w"}}};

    // ... set as value
    str_is_m = {{"h", {0}}, {"w",{42}}};
    str_strs_m = {{"h", {"h"}}, {"w",{"w"}}};

    // ... map as value
    str_ibm_m = {{"h", {{0, true}}}, {"w", {{42, false}}}};
    str_iim_m = {{"h", {{0, 0}}}, {"w", {{42, 42}}}};
    str_idm_m = {{"h", {{0, 0}}}, {"w", {{42, 42}}}};
    str_istrm_m = {{"h", {{0, "h"}}}, {"w", {{42, "w"}}}};

    // ... map as value
    str_strbm_m = {{"h", {{"h", true}}}, {"w", {{"w", false}}}};
    str_strim_m = {{"h", {{"h", 0}}}, {"w", {{"w", 42}}}};
    str_strdm_m = {{"h", {{"h", 0}}}, {"w", {{"w", 42}}}};
    str_strstrm_m = {{"h", {{"h", "h"}}}, {"w", {{"w", "w"}}}};
}

bool X::IsEqualBuiltIn(const X& other) const
{
    return
        b == other.b &&
        c == other.c &&
        uc == other.uc &&
        s == other.s &&
        us == other.us &&
        i == other.i &&
        ui == other.ui &&
        l == other.l &&
        ul == other.ul &&
        ll == other.ll &&
        ull == other.ull &&
        f == other.f &&
        d == other.d &&
        i8 == other.i8 &&
        ui8 == other.ui8 &&
        i16 == other.i16 &&
        ui16 == other.ui16 &&
        i32 == other.i32 &&
        ui32 == other.ui32 &&
        i64 == other.i64 &&
        ui64 == other.ui64 &&
        str == other.str;
}

bool X::IsEqualLists(const X& other) const
{
    return
        // List
        b_l == other.b_l &&
        i_l == other.i_l &&
        d_l == other.d_l &&
        str_l == other.str_l &&

        // List of vectors
        b_vl == other.b_vl &&
        i_vl == other.i_vl &&
        d_vl == other.d_vl &&
        str_vl == other.str_vl &&

        // List of lists
        b_ll == other.b_ll &&
        i_ll == other.i_ll &&
        d_ll == other.d_ll &&
        str_ll == other.str_ll;
}

bool X::IsEqualVectors(const X& other) const
{
    return
        // Vector
        b_v == other.b_v &&
        i_v == other.i_v &&
        d_v == other.d_v &&
        str_v == other.str_v &&
        // Vector of vectors
        b_vv == other.b_vv &&
        i_vv == other.i_vv &&
        d_vv == other.d_vv &&
        str_vv == other.str_vv &&
        // Vector of lists
        b_lv == other.b_lv &&
        i_lv == other.i_lv &&
        d_lv == other.d_lv &&
        str_lv == other.str_lv;
}

bool X::IsEqualSets(const X& other) const
{
    return
        i_s == other.i_s &&
        str_s == other.str_s;
}

bool X::IsEqualMaps(const X& other) const
{
    return
        // Map of int as key
        ib_m == other.ib_m &&
        ii_m == other.ii_m &&
        id_m == other.id_m &&
        istr_m == other.istr_m &&

        // ... list as value
        i_bl_m == other.i_bl_m &&
        i_il_m == other.i_il_m &&
        i_dl_m == other.i_dl_m &&
        i_strl_m == other.i_strl_m &&

        // ... vector as value
        i_bv_m == other.i_bv_m &&
        i_iv_m == other.i_iv_m &&
        i_dv_m == other.i_dv_m &&
        i_strv_m == other.i_strv_m &&

        // ... set as value
        i_is_m == other.i_is_m &&
        i_strs_m == other.i_strs_m &&

        // ... map as value
        i_ibm_m == other.i_ibm_m &&
        i_iim_m == other.i_iim_m &&
        i_idm_m == other.i_idm_m &&
        i_istrm_m == other.i_istrm_m &&

        // ... map as value
        i_strbm_m == other.i_strbm_m &&
        i_strim_m == other.i_strim_m &&
        i_strdm_m == other.i_strdm_m &&
        i_strstrm_m == other.i_strstrm_m &&

        // Map of string as key
        strb_m == other.strb_m &&
        stri_m == other.stri_m &&
        strd_m == other.strd_m &&
        strstr_m == other.strstr_m &&

        // ... vector as value
        str_bv_m == other.str_bv_m &&
        str_iv_m == other.str_iv_m &&
        str_dv_m == other.str_dv_m &&
        str_strv_m == other.str_strv_m &&

        // ... list as value
        str_bl_m == other.str_bl_m &&
        str_il_m == other.str_il_m &&
        str_dl_m == other.str_dl_m &&
        str_strl_m == other.str_strl_m &&

        // ... set as value
        str_is_m == other.str_is_m &&
        str_strs_m == other.str_strs_m &&
        // ... map as value
        str_ibm_m == other.str_ibm_m &&
        str_iim_m == other.str_iim_m &&
        str_idm_m == other.str_idm_m &&
        str_istrm_m == other.str_istrm_m &&
        // ... map as value
        str_strbm_m == other.str_strbm_m &&
        str_strim_m == other.str_strim_m &&
        str_strdm_m == other.str_strdm_m &&
        str_strstrm_m == other.str_strstrm_m;
}
