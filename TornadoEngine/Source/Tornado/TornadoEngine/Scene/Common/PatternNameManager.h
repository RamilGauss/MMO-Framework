/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef PatternNameManagerH
#define PatternNameManagerH

#include <vector>
#include <string>

class TPatternNameManager
{
  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecNameType;
public:
  TPatternNameManager();
  int GetCount();
  std::string Get(int index);

  static std::string MapParameter();
  static std::string Animated();
  static std::string Light();
  static std::string Model();
  static std::string Skybox();
  static std::string Skydome();
  static std::string Skyplane();
  static std::string Sound();
  static std::string Terrain();
  static std::string Volume();

  typedef enum
  {
    eBase = 0,
    
    eMapParameter,
    eAnimated,
    eLight,
    eModel,
    eSky,
    eSound,
    eTerrain,
    eVolume,
  }eBaseType;
};

#endif
