![SWUbanner](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/banner2-direct.svg)

# MMO-Framework

To launch Editor use [Hub](https://github.com/RamilGauss/TornadoHub/releases).

## Why?

- Proof of Concept. Expanding the capabilities of ready-made MMO RPG games. You can add new functionality by writing your own server for an existing client.
One of the possible options for such an implementation: a client patch that embeds the MMO transport from the MMO-Framework into the client (or intercepting and replacing packets).
Further, the transfer of the commands used in the client to the server code. And writing server logic.
Server implementation with MMO-Framework can include physics, network, logic and database. 

- Writing your own MMO RPG on PC in Windows/Linux. At the moment, the main target platform is PC. 

## Disclaimer
No claims to compete with engines such as Unity, UnrealEngine, Godot, etc.  
I would like to try a bunch of C ++ with a code generator and see what happens.
Will the code generator and ECS add convenience and speed to development?  
This is a research project.  

## Features

Only free and open source engines / libraries / frameworks!

|               | GUI         | Graphic     | Physic |  Network    |   Sound |  ORM DataBase |
|----------     | ------------| ------------|--------|-------------|---------|------------|
|Implementaion  | [Dear ImGui](https://github.com/ocornut/imgui)  |   [BigJack](https://github.com/RamilGauss/MMO-Framework/tree/master/Source/Modules/GraphicEngine)      | [Bullet](https://github.com/bulletphysics/bullet3) | High: [MMO Engine](https://github.com/RamilGauss/MMO-Framework/tree/master/Source/Modules/MMOEngine)<br>Low: [NetTransport](https://github.com/RamilGauss/MMO-Framework/tree/master/Source/Modules/NetTransport)  |    ?     |      ?     |

## GUI  
Grid and layouts
<br>
<img src="./Doc/gridAndLayouts.gif">
<br>
Component viewer
<br>
<img src="./Doc/componentViewer.gif">
<br>
<img src="./Doc/open_project_file.gif">
<br>
<img src="./Doc/gui_example.gif">
<br>
<img src="./Doc/tree_view_editing.gif">

## ECS

<img src="./Doc/ECS_tree_conveyor_uml.png">

ECS_tree_conveyor_uml

[Video](http://www.youtube.com/watch?v=g8IlYRepclE)

## Engine features:

  The ability to control the initial number of modules.
The module is a graphical, physical, network, GUI, etc engines.
    
  MMO (network) component can work with more than one million Clients.
This is achieved by using the cluster organization within the Server.

  For compiling requires: see file HowToCompile_Win.txt.
To view the architectural decisions need Enterprise Architect 7.0+.
[Article on habrahabr](http://habrahabr.ru/post/233915/).

Dependencies got via [conan](http://conan.io).

---

# MMO-Framework (rus)

## Дисклеймер
Без претензий конкурировать с такими движками как Unity, UnrealEngine, Godot и т.д.  
Хочется попробовать связку C++ с кодогенератором и посмотреть что из этого выйдет.  
Добавит ли кодогенератор и ECS удобства и скорость разработки?  
Это исследовательский проект.  
    
## Возможности движка

Возможность управления количеством модулей.
Модуль это графический, физический, сетевой, GUI и т.д движки.
    
  ММО(сетевой) компонент может работать с более чем миллионом Клиентов.
Это достигается с помощью кластерной организации внутри Сервера.

  Для компиляции требуется: смотри HowToCompile_Win.txt.
  
Для просмотра архитектурных решений потребуется Enterprise Architect 7.0+.
[Статья на хабре](http://habrahabr.ru/post/233915/).

Зависимости через [conan](http://conan.io).
//------------------------------------------------------------------------------------------

## Зачем?  

- Proof of Concept. Расширение возможностей готовых ММО РПГ игр. Вы можете добавить новую функциональность с помощью написания своего собственного сервера для уже готового клиента.
Один из возможных вариантов такой реализации: патч клиента, который встраивает ММО-транспорт из фреймворка в клиент (или перехват и подмена пакетов).
Далее перенос используемых команд в клиенте в серверный код. И написание серверной логики.
Серверная реализация с помощью MMO-Framework может включать физику, сеть, логику и базу данных.
  
- Написание своей ММО РПГ на PC в Windows/Linux. На данный момент основная целевая платформа - PC.

