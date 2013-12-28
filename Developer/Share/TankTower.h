/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TankTowerH
#define TankTowerH

#include "../GameLib/IActor.h"


class TTankTower : public IActor
{
  nsStruct3D::TMatrix16 mMatrixForCamera;

public:
  typedef enum{
    Engine          = 1>>1, // двигатель, поврежден
    EngineBreak     = 2>>1, // двигатель, не работает
    //------------------------------------------------
    Gun             = 3>>1, // пушка 
    GunBreak        = 4>>1, // пушка 
    //------------------------------------------------
    Tower           = 5>>1, // башн€
    TowerBreak      = 6>>1, // башн€
    //------------------------------------------------
    Chassis         = 7>>1, // шасси
    ChassisBreak    = 8>>1, // шасси
    //------------------------------------------------
    Optica          = 9>>1, // триплекс рассто€ни€
    OpticaBreak     = 10>>1, // триплекс рассто€ни€
    //------------------------------------------------
    LeftTrack       = 11>>1,
    LeftTrackBreak  = 12>>1,
    //------------------------------------------------
    RightTrack      = 13>>1,
    RightTrackBreak = 14>>1,
    //------------------------------------------------
    BK              = 15>>1,// бое укладка повреждена
  }eMaskDefectDevice;

  typedef enum{
    e1 = 1>>1, 
    e2 = 2>>1, 
    e3 = 3>>1, 
    e4 = 4>>1, 
    e5 = 5>>1, 
    e6 = 6>>1, 
    e7 = 7>>1, 
    e8 = 8>>1, 
  }eMaskDefectCrew;
  //----------------------------------------

  typedef enum{
    eLeft=0,
    eRight,
    eBack,
    eForward,
  }ePushButton;
public:
  TTankTower();
  virtual ~TTankTower();

  virtual bool GetMirror(char ** pData,int &size);
  virtual void SetMirror(char *pData,int size);

  virtual void SetHuman(char* pData, int size);

  virtual bool Animate(unsigned int time_ms);

  // from IBaseObject
  virtual const nsStruct3D::TMatrix16* GetMatrixForCamera();

public://protected:
  // debug only
  void RotateTurret(float ugol);
  void RotateVerticalGun(float ugol);

protected:
  virtual void SetupShaderStackModelGE();
  virtual void EventSetModelGE();

protected:
  int mIndexTrackR;
  int mIndexTrackL;
  int mIndexTime;
  int mIndexVelocity;
  std::vector<int> mShaderStackMask;

public:
#pragma pack(push, 1)
  struct TProperty
  {
    unsigned int mID_tank;
    // базовые
    float mMassa;                    //масса, кг
    float mPower;                    //мощность двигател€, ¬т
    float mSpeedRotate;              //мощность поворота, град/сек
    float mDistView;                 //дальность обзора, м
    float mVisibilityStatic;         //видимость неподвижный
    float mVisibilityDinamic;        //          подвижный, коэф
    float mSpeedRotateTower;         // скорость вращени€ башни, рад/сек
    float mSpeedReductionGun;        // скорость движени€ пушки, рад/с
    // Property, которые не мен€ютс€
    float mMaxSpeedForward;          //максимальна€ скорость вперед, м/с
    float mMaxSpeedBackward;         //максимальна€ скорость назад, м/с
    float mRadiusRadio;              // радиус действи€ радио, м - зависит от рации и радиста

    // максимальный угол вертикальной наводки у пушки
    float mVMaxGunUgol;  // вверх, рад
    float mVMinGunUgol;  // вниз, рад
    // максимальный угол вертикальной наводки у пушки
    float mHMaxGunUgol;  // по часовой стрелке, рад
    float mHMinGunUgol;  // против часовой стрелке, рад
  };
#pragma pack(pop)

  struct TDefShell
  {
    float damage;              // урон, хп
    float depthShoot;          // пробиваемость, мм
    float mSpeedShell;               // скорость снар€да
  };

  // характеристики
  // свойства в бою

  unsigned int maskDefectDevice;   // маска неисправности устройств,  0 - исправно, 1 - неисправно см. eMaskDefectDevice
  unsigned int maskDefectCrew;     // маска контузии экипажа,  0 - здоров, 1 - контужен см. eMaskDefectCrew

  // состо€ние

  // ЅЅ
  TDefShell mShellBron; // зависит от пушки
  // ќ‘
  TDefShell mShellExplosive; // зависит от пушки
  //  —
  TDefShell mShellCumul; // зависит от пушки

  float mProbablyFireEngine;       // веро€тность загорани€ танка, зависит от двигател€
  unsigned short mFireDamage; 
  float mProbablyExplosiveStackShell; // веро€тность взрыва Ѕ 
  unsigned short mExplosiveStackShellDamage; 

  unsigned short mHP;              // у.е. зависит от типа танка и типа башни

  float mCentrRotate;              //центр поворота, смещение относительно центра танка, м  от типа танка и типа шасси

  // Property, которые мен€ютс€
  TProperty mProperty;

  // характеристики оруди€
  unsigned short mCntCommonShell;   // общее кол-во снар€дов
  unsigned short mCntBronShell;     // бронебойный
  unsigned short mCntExplosiveShell;// ќ‘
  unsigned short mCntCumulShell;    // кумул€тивный

  unsigned short mMaxCntShell;
  unsigned char mTypeCurShell;
  unsigned char mTypeNextShell;

  float mTimeReload;               // врем€ перезар€дки, сек
  float mSpeedReductionAim;        // скорость наведени€


  // есть два фактора: экипаж и комплектаци€ танка
  // комплектаци€
  unsigned char mTower; // номер, 0 - базова€ (сток)
  unsigned char mGun;
  unsigned char mChassis;
  unsigned char mEngine;
  unsigned char mRadio;

  // установленные модули
  unsigned int maskModule;

  unsigned int mTimeRefreshOrientAim;

  // маска нажатых клавиш
  unsigned int mTimeRefreshPushButton;// когда последний раз мен€лась маска
  unsigned int mMaskPushButton; // см. ePushButton
  unsigned int mRestReload;

};


#endif