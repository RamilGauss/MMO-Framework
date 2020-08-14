/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Tokenizer.h"

#include <boost/wave/cpplexer/cpp_lex_token.hpp>    // token class
#include <boost/wave/cpplexer/cpp_lex_iterator.hpp> // lexer class

#include "LoadFromFile.h"
#include "SingletonManager.h"
#include "Config.h"
#include "TokenInfoManager.h"
#include "TokenInfo.h"
#include "ConfigContainer.h"

using namespace boost::wave;
using namespace nsReflectionCodeGenerator;

bool TTokenizer::Work( std::string& instr, std::list<TTokenInfo>& resultList )
{
  auto configContainer = SingletonManager()->Get<TConfigContainer>();

  try
  {
    typedef boost::wave::cpplexer::lex_token<> token_type;
    typedef boost::wave::cpplexer::lex_iterator<token_type> lexer_type;
    typedef token_type::position_type position_type;

    auto flags = boost::wave::language_support( boost::wave::support_cpp | boost::wave::support_option_long_long );

    position_type pos;
    lexer_type it = lexer_type( instr.begin(), instr.end(), pos, flags );
    lexer_type end = lexer_type();

    while ( it != end )
    {
      auto token = *it;
      auto id = token_id( token );
      auto category = CATEGORY_FROM_TOKEN( id );
      if ( category == UnknownTokenType )
      {
        it++;
        continue;
      }

      TTokenInfo tokenInfo;
      tokenInfo.id = id;
      auto tokenName = get_token_name( id );
      tokenInfo.strId = std::string( tokenName.data(), tokenName.size() );
      auto value = it->get_value();
      auto size = value.size();
      for ( std::size_t i = 0; i < size; ++i )
      {
        auto v = value [i];
        switch ( v )
        {
          case '\r':  tokenInfo.value += "\\r"; break;
          case '\n':  tokenInfo.value += "\\n"; break;
          case '\t':  tokenInfo.value += "\\t"; break;
          default:
            tokenInfo.value += v;
            break;
        }
      }

      resultList.push_back( tokenInfo );
      ++it;
    }
  }
  catch ( ... )
  {
    return false;
  }
  return true;
}
//--------------------------------------------------------------------------------------------------------
std::string TTokenizer::ErrorDesc()
{
  return "";
}
//--------------------------------------------------------------------------------------------------------
