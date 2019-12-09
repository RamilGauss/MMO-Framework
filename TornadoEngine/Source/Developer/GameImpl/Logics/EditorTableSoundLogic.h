/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef EditorTableSoundLogicH
#define EditorTableSoundLogicH

#include "ModuleClientLogic.h"

class TEditorTableSound;

class TEditorTableSoundLogic : public TModuleClientLogic
{
  TEditorTableSound* mEditorTableSound;
public:
  TEditorTableSoundLogic();
  virtual ~TEditorTableSoundLogic();

  virtual void StartEvent();
  virtual void InitLog();
protected:
  virtual bool WorkClient();

  virtual void Input(int id_sender, void* p, int size);
private:
  void StartTimer();
  void InitForms();

  void InitPhysic();

  void GraphicBeginWork();
  void FreeGraphicResource();

  void PhysicBeginWork();
  void PhysicEndWork();
};

#endif
