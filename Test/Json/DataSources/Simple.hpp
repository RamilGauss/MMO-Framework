/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <cstdint>

#include <string>
#include <list>
#include <set>
#include <map>
#include <vector>

namespace nsSimple
{
    struct X
    {
        // Built-in
        bool b = false;
        char c = 0;
        unsigned char uc = 0;
        short s = 0;
        unsigned short us = 0;
        int i = 0;
        unsigned int ui = 0;
        long l = 0;
        unsigned long ul = 0;
        long long ll = 0;
        unsigned long long ull = 0;
        float f = 0;
        double d = 0;
        int8_t i8 = 0;
        uint8_t ui8 = 0;
        int16_t i16 = 0;
        uint16_t ui16 = 0;
        int32_t i32 = 0;
        uint32_t ui32 = 0;
        int64_t i64 = 0;
        uint64_t ui64 = 0;
        std::string str;

        // List
        std::list<bool> b_l;
        std::list<int> i_l;
        std::list<double> d_l;
        std::list<std::string> str_l;

        // List of vectors
        std::list<std::vector<bool>> b_vl;
        std::list<std::vector<int>> i_vl;
        std::list<std::vector<double>> d_vl;
        std::list<std::vector<std::string>> str_vl;

        // List of lists
        std::list<std::list<bool>> b_ll;
        std::list<std::list<int>> i_ll;
        std::list<std::list<double>> d_ll;
        std::list<std::list<std::string>> str_ll;

        // Vector
        std::vector<bool> b_v;
        std::vector<int> i_v;
        std::vector<double> d_v;
        std::vector<std::string> str_v;

        // Vector of vectors
        std::vector<std::vector<bool>> b_vv;
        std::vector<std::vector<int>> i_vv;
        std::vector<std::vector<double>> d_vv;
        std::vector<std::vector<std::string>> str_vv;

        // Vector of lists
        std::vector<std::list<bool>> b_lv;
        std::vector<std::list<int>> i_lv;
        std::vector<std::list<double>> d_lv;
        std::vector<std::list<std::string>> str_lv;

        // Set
        std::set<int> i_s;
        std::set<std::string> str_s;

        // Map of int as key
        std::map<int, bool> ib_m;
        std::map<int, int> ii_m;
        std::map<int, double> id_m;
        std::map<int, std::string> istr_m;

        // ... list as value
        std::map<int, std::list<bool>> i_bl_m;
        std::map<int, std::list<int>> i_il_m;
        std::map<int, std::list<double>> i_dl_m;
        std::map<int, std::list<std::string>> i_strl_m;

        // ... vector as value
        std::map<int, std::vector<bool>> i_bv_m;
        std::map<int, std::vector<int>> i_iv_m;
        std::map<int, std::vector<double>> i_dv_m;
        std::map<int, std::vector<std::string>> i_strv_m;

        // ... set as value
        std::map<int, std::set<int>> i_is_m;
        std::map<int, std::set<std::string>> i_strs_m;

        // ... map as value
        std::map<int, std::map<int, bool>> i_ibm_m;
        std::map<int, std::map<int, int>> i_iim_m;
        std::map<int, std::map<int, double>> i_idm_m;
        std::map<int, std::map<int, std::string>> i_istrm_m;

        // ... map as value
        std::map<int, std::map<std::string, bool>> i_strbm_m;
        std::map<int, std::map<std::string, int>> i_strim_m;
        std::map<int, std::map<std::string, double>> i_strdm_m;
        std::map<int, std::map<std::string, std::string>> i_strstrm_m;

        // Map of string as key
        std::map<std::string, bool> strb_m;
        std::map<std::string, int> stri_m;
        std::map<std::string, double> strd_m;
        std::map<std::string, std::string> strstr_m;

        // ... vector as value
        std::map<std::string, std::vector<bool>> str_bv_m;
        std::map<std::string, std::vector<int>> str_iv_m;
        std::map<std::string, std::vector<double>> str_dv_m;
        std::map<std::string, std::vector<std::string>> str_strv_m;

        // ... list as value
        std::map<std::string, std::list<bool>> str_bl_m;
        std::map<std::string, std::list<int>> str_il_m;
        std::map<std::string, std::list<double>> str_dl_m;
        std::map<std::string, std::list<std::string>> str_strl_m;

        // ... set as value
        std::map<std::string, std::set<int>> str_is_m;
        std::map<std::string, std::set<std::string>> str_strs_m;

        // ... map as value
        std::map<std::string, std::map<int, bool>> str_ibm_m;
        std::map<std::string, std::map<int, int>> str_iim_m;
        std::map<std::string, std::map<int, double>> str_idm_m;
        std::map<std::string, std::map<int, std::string>> str_istrm_m;

        // ... map as value
        std::map<std::string, std::map<std::string, bool>> str_strbm_m;
        std::map<std::string, std::map<std::string, int>> str_strim_m;
        std::map<std::string, std::map<std::string, double>> str_strdm_m;
        std::map<std::string, std::map<std::string, std::string>> str_strstrm_m;

        // Methods
        bool operator == (const X& other) const;

        void Fill();

        bool IsEqualBuiltIn(const X& other) const;
        bool IsEqualLists(const X& other) const;
        bool IsEqualVectors(const X& other) const;
        bool IsEqualSets(const X& other) const;
        bool IsEqualMaps(const X& other) const;
    };
}
