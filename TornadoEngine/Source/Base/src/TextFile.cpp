/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#include "TextFile.h"


TTextFile::TTextFile( std::string& path )
{
  mPath = path;
}
//-------------------------------------------------------------------
void TTextFile::Load( std::string& str )
{
  if ( mLoader.ReOpen( (char*) mPath.data() ) == false )
    return;

  TContainer c;
  mLoader.ReadSmall( c );
  str = std::string( c.GetPtr(), c.GetSize() );
}
//-------------------------------------------------------------------
void TTextFile::Load( std::string& path, std::string& str )
{
  TTextFile tf( path );
  tf.Load( str );
}
//-------------------------------------------------------------------
void TTextFile::Save( std::string& str, bool append )
{
  if ( mSaver.ReOpen( (char*) mPath.data(), append ) == false )
    return;
  mSaver.Write( str.data(), str.length() );
}
//-------------------------------------------------------------------
void TTextFile::Save( std::string& path, std::string& str, bool append )
{
  TTextFile tf( path );
  tf.Save( str, append );
}
//-------------------------------------------------------------------
