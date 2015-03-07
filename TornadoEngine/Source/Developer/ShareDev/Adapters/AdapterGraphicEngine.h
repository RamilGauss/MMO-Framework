/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterGraphicEngineH
#define AdapterGraphicEngineH

#include <boost/smart_ptr/scoped_ptr.hpp>
#include "PrototypeDev.h"

class TGraphicEngine_OGRE_MyGUI;

class DllExport AdapterGraphicEngine : public PrototypeDev
{
	boost::scoped_ptr<TGraphicEngine_OGRE_MyGUI> mGE;
public:
  AdapterGraphicEngine();
  virtual ~AdapterGraphicEngine();

  virtual bool Work();

protected:
 
};

#endif
