To launch Editor use [Hub](https://github.com/RamilGauss/TornadoHub/releases).

## Disclaimer
Compete without pretense with engines like Unity, UnrealEngine, Godot, etc.  
I would like to try a bunch of C ++ with a code generator and see what happens.  
Will the code generator and ECS add convenience and speed to development?  
This is a research project.  

## Дисклеймер
Без претензий конкурировать с такими движками как Unity, UnrealEngine, Godot и т.д.  
Хочется попробовать связку C++ с кодогенератором и посмотреть что из этого выйдет.  
Добавит ли кодогенератор и ECS удобства и скорость разработки?  
Это исследовательский проект.  


## Features

Only free and open source engines / libraries / frameworks!

|               | GUI         | Graphic     | Physic |  Network    |   Sound |  ORM DataBase |
|----------     | ------------| ------------|--------|-------------|---------|------------|
|Implementaion  | [Dear ImGui](https://github.com/ocornut/imgui)  |   [Ogre](https://github.com/OGRECave/ogre)      | [Bullet](https://github.com/bulletphysics/bullet3) | High: [MMO Engine](https://github.com/RamilGauss/MMO-Framework/tree/master/Source/Modules/MMOEngine)<br>Low: [NetTransport](https://github.com/RamilGauss/MMO-Framework/tree/master/Source/Modules/NetTransport)  |    ?     |      ?     |




### GUI

<img src="./Doc/gui_example.gif">

[Video](http://www.youtube.com/watch?v=g8IlYRepclE)

### English 
	
    Engine features:

  The ability to control the initial number of modules.
The module is a graphical, physical, network, GUI, etc engines.
    
  MMO (network) component can work with more than one million Clients.
This is achieved by using the cluster organization within the Server.

  For compiling requires: see file HowToCompile_Win.txt.
To view the architectural decisions need Enterprise Architect 7.0+.
[Article on habrahabr](http://habrahabr.ru/post/233915/).

[Dependencies](https://github.com/RamilGauss/MMO-FrameworkDependency).

Other dependencies got via [conan](http://conan.io).

### Russian
    
    Возможности движка:

Возможность управления количеством модулей.
Модуль это графический, физический, сетевой, GUI и т.д движки.
    
  ММО(сетевой) компонент может работать с более чем миллионом Клиентов.
Это достигается с помощью кластерной организации внутри Сервера.

  Для компиляции требуется: смотри HowToCompile_Win.txt.
  
Для просмотра архитектурных решений потребуется Enterprise Architect 7.0+.
[Статья на хабре](http://habrahabr.ru/post/233915/).

[Зависимости](https://github.com/RamilGauss/MMO-FrameworkDependency).

Остальные зависимости через [conan](http://conan.io).
//------------------------------------------------------------------------------------------