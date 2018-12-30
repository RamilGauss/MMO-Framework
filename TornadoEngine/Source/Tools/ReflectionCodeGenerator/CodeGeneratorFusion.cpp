/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "CodeGeneratorFusion.h"
#include "fmt/time.h"
#include "fmt/color.h"
#include "SaveToFile.h"
#include "IncludeListGenerator.h"
#include "JsonSerializerGenerator.h"
#include "BinaryMarshallerGenerator.h"


using namespace fmt::literals;

class IStringed
{
public:
  virtual std::string ToString() = 0;
};

class TMethodBegin : public IStringed
{
public:
  std::string mReturnedType = "void";
  std::string mNameMethod;
  std::string mEndMethod = ";";

  //std::vector<T>

  virtual std::string ToString() override
  {
    return fmt::format( "{} {}({}){}", mReturnedType, mNameMethod, mEndMethod );
  }
};
//---------------------------------------------------------------------------------------
using namespace nsReflectionCodeGenerator;

//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::Work()
{
  Collect();
  Dump();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::Collect()
{
  CollectFromIncludeList();
  CollectFromJson();
  CollectFromBinary();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::Dump()
{
  TSaveToFile stf;
  for ( auto& fileParts : mForDump )
  {
    if( stf.ReOpen( fileParts.first.data() ) == false )
      continue;
    for ( auto& part : fileParts.second )
      stf.WriteF( "%s\n", part.data() );
  }
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::CollectFromIncludeList()
{
  TIncludeListGenerator generator;
  generator.Init( mForDump );
  generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::CollectFromJson()
{
  TJsonSerializerGenerator generator;
  generator.Init( mForDump );
  generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::CollectFromBinary()
{
  TBinaryMarshallerGenerator generator;
  generator.Init( mForDump );
  generator.Work();
}
//---------------------------------------------------------------------------------------------

