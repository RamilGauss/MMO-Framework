## Библиотека для разработки сценариев

Реализован граф, в котором переход между состояниями (Зона) происходит с помощью процессов.

```cpp
TZoneManager zoneMgr;

TZone a("A");
TZone b("B");

zoneMgr.AddZone(&a);
zoneMgr.AddZone(&b);

TSimpleProcess a_process;
a_process.Setup("a->b", &a, &b);
```

Например, есть две Зоны `A` и `B`. Начальное состояние - Зона `A`.
Для перехода из `A` в `B` нужно запустить процесс `a->b`.

```cpp
TCtx ctx;
a.AddContext(&ctx);

ctx.StartProcess("a->b");
```

Для запуска процесса перехода нужно дать квант `TZoneManager`, который владеет Зонами и процессом.

```cpp
TCtx ctx;
a.AddContext(&ctx);

ctx.StartProcess("a->b");

zoneMgr.Work();
```