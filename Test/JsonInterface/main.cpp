#include <fstream>
#include <iostream>
#include <sstream>

#include <fmt/color.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

#include "Base/Common/JsonPopMaster.h"
#include "Base/Common/JsonPushMaster.h"
#include "Base/Common/HiTimer.h"

int main(int argc, char** argv)
{
    // Add to serialize
    rapidjson::Document doc(rapidjson::Type::kObjectType);
    rapidjson::Document::Object jobj = doc.GetObject();

    auto& it = jobj.FindMember("asdasd");
    if ( it == jobj.MemberEnd() ) {
        std::cout << "Found\n";
    }

    // Push
    TJsonPushMaster::PushNull(jobj, "empty");
    int n = 42;
    TJsonPushMaster::Push(jobj, "n", n);
    double d = 42;
    TJsonPushMaster::Push(jobj, "d", d);
    std::string s = "42";
    TJsonPushMaster::Push(jobj, "s", s);
    bool b = true;
    TJsonPushMaster::Push(jobj, "b", b);

    auto newObject = TJsonPushMaster::AddObject(jobj, "new object");

    std::string name = "asdf";
    TJsonPushMaster::Push(newObject, "name", name);

    TJsonPushMaster::Value arr(rapidjson::kArrayType);

    std::string arrValue = "42";
    int arrV = 123;
    TJsonPushMaster::PushBack(arr, arrV);

    TJsonPushMaster::Value arrInner(rapidjson::kArrayType);
    TJsonPushMaster::PushBack(arrInner, arrValue);
    TJsonPushMaster::PushBack(arrInner, arrValue);
    TJsonPushMaster::PushBack(arrInner, arrValue);
    TJsonPushMaster::PushBack(arrInner, arrValue);
    TJsonPushMaster::PushBack(arrInner, arrValue);

    TJsonPushMaster::PushBack(arr, arrInner);
    TJsonPushMaster::PushBack(arr, arrV);
    TJsonPushMaster::PushBack(arr, b);

    TJsonPushMaster::Value objInArr(rapidjson::kObjectType);
    auto o = objInArr.GetObject();
    TJsonPushMaster::Push(o, "d", d);

    TJsonPushMaster::PushBack(arr, objInArr);


    TJsonPushMaster::Push(newObject, "array", arr);

    auto innerObject = TJsonPushMaster::AddObject(newObject, "inner");
    TJsonPushMaster::Push(innerObject, "name", name);

    // Pop
    auto fArr = TJsonPopMaster::FindArray(jobj, "array");
    for ( auto& e : fArr ) {
        e.GetArray();
    }


    bool bOut = false;
    TJsonPopMaster::PopBool(jobj, "b", bOut);

    auto isNull = TJsonPopMaster::Find(jobj, "empty").IsNull();

    double retD = 123;
    TJsonPopMaster::PopNum(jobj, "d", retD);

    int retI = 123;
    TJsonPopMaster::PopNum(jobj, "n", retI);

    std::string retS = "asdadasd";
    TJsonPopMaster::PopStr(jobj, "s", retS);

    //###
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
    doc.Accept(writer);
    auto dump = sb.GetString();
    fmt::print(fg(fmt::color::lime), dump );
    //###

    return 0;
}