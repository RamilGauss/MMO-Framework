/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GlobalParamsH
#define GlobalParamsH

//#define DURATION_FIGHT_MINUTE 15 // длительность боя,минут
//#define DURATION_FIGHT_MS (DURATION_FIGHT_MINUTE*60*1000) // длительность боя, мс
//#define COUNT_COMMAND_IN_FIGHT 1// размер одной из команды в бою
// \\ игровые параметры \\

// версии
#define VER_GAME_ENGINE           ((unsigned short)150)
#define COUNT_GAME_ENGINE_MODULES ((unsigned short)3)

#define VER_GRAPHIC_ENGINE ((unsigned short)56)
#define VER_PHYSIC_ENGINE  ((unsigned short)0)
#define VER_MMO_ENGINE     ((unsigned short)950)

extern char strVerGameEngine[260];
extern char strVerGraphicEngine[260];
extern char strVerPhysicEngine[260];
extern char strVerNetEngine[260];

/* описание структуры хранения моделей и карт
//----------------------------------------------------
//    Список карт и моделей
//----------------------------------------------------
 формат один:
 ---------
 [MAIN]
    cnt=N
 [PART0]
    id=ID
    path=PATH
    ...
 [PART(N-1)]
    ...
 ---------
 path - название папки, которая находится в той же папке, что и файл списка

 //----------------------------------------------------
 //    Файл карты
 //----------------------------------------------------
 ---------
 [MAIN]
    cnt=N
    common property - будет уточняться
 [PART0]
    id_model=
    id_behavior=
    coord=;;;
    orient=;;;
    state=
    ...
 [PART(N-1)]
    ...
 ---------
 индекс - он же ID на карте
 //----------------------------------------------------
 //    Файл модели DX
 //----------------------------------------------------
 ---------
 [MAIN]
    LOD= - дистанция от камеры до объекта
    CntGroup=4 - кол-во частей
 [JOINT]
    root=Hull - имя корня
    node0 = Hull
    cntJoint = 5
    nameJoint0 = Turret
    matrix0_0=1;0;0;0;
    matrix0_1=0;1;0;0;
    matrix0_2=0;0;1;0;
    matrix0_3=0;0;0;1;
    nameJoint(cntJoint) = ...
    ...
    node1 = Turret
    ...
    node(CntGroup-1)
    ...
 [PART0]
    strPathShader=shader.fx - название шейдера
    strTechnique=TexturedSpecular - функция внутри шейдера
    strTexture=PzVl_Tiger_I.dds - название файла текстуры
    strName=Hull - имя (для отладки)
    vAmbient=0.4;0.4;0.4; - 
    vDiffuse=0.4;0.4;0.4;
    vSpecular=1;1;1;
    nShininess=1
    fAlpha=1.0
    bSpecular=0
    mTypeLOD=0   - детализация
    mflgNormal=1 - разрушен ли
    primitives=Hull.obj - набор вершин, индексов, нормалей
 [PART(N-1)]
 ...
 ---------

 
    Состав частей для танка: 
  Пушка Gun
  Башня Turret
  Корпус Hull
  Траки TrackR и TrackL
  Шасси ChassisR и ChassisL

 */

// Файлы текстур и шейдеров задаются для каждой группы отдельно


#endif
