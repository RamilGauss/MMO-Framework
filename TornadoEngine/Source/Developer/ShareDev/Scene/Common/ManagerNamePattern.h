/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerNamePatternH
#define ManagerNamePatternH

#include <vector>
#include <string>

class TManagerNamePattern
{
  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecNameType;
public:
  TManagerNamePattern();
  int GetCount();
  std::string Get(int index);

  static std::string Animated();
  static std::string Light();
  static std::string Model();
  static std::string Skybox();
  static std::string Skydome();
  static std::string Skyplane();
  static std::string Sound();
  static std::string Terrain();
  static std::string Zone();

	typedef enum
	{
		eBase = 0,

		eAnimated,
		eLight,
		eModel,
		eSky,
		eSound,
		eTerrain,
		eZone,
	}eBaseType;
};

#endif
