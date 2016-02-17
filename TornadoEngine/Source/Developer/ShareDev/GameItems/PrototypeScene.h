/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#ifndef PrototypeSceneH
#define PrototypeSceneH

class PrototypeScene
{
  // контроль над событиями
  virtual void Suspend();
  virtual void Pause();
  virtual bool IsPaused();

  // загрузка и сохранение
  virtual bool Load(const char* nameMap);
  virtual bool Save(const char* nameMap);

  // синхронизация
  virtual bool Update();
};

#endif
