﻿	Russian
	
	Установка зависимостей и компиляция проекта под Ubuntu 12/14/16/18/19  x86/64.
	
	Примечание: на данный момент можно скомпилировать и запустить тестовый пример взаимодействия Клиента и Серверного кластера (ММО сеть).
	Ядро игры и модули Графики и физики пока НЕ готовы к компиляции.
	
1. Итак, Архив MMO-Framework.zip скачан с github.com и распакован.
2. Перед началом в системе должно быть установлено:
	2.1. Synaptic - для скачивания зависимостей и программ.
	2.2. Midnight Commander.
	Примечание: для установки synaptic открыть konsole и ввести: sudo apt-get install synaptic.
	Далее ввести пароль root.
	После установки запустить synaptic: sudo synaptic и ввести пароль root. 
	Искать в synaptic слова Midnight Commander. Отметить галочкой md-dev и нажать "Применить".

3. Аналогично способом установки из п.2 искать слова в synaptic и установить:
	3.1. libssl
	3.2. libboost-dev-all (версия > 1.54).
	3.3. qt-default и qt-4.8.5+.

4. В konsole ввести sudo apt-get install g++ и ввести пароль root.

5. 
	5.1. Запустить konsole, sudo mc, ввод пароля root.
	5.2. Зайти в папку TornadoEngine/Script/ и выделить кнопкой insert все файлы. Control+X, C.
	Появится меню, выбрать "выполнить" и нажать "Установить все". Файлы станут другого цвета и появится звездочка.
	5.3. Запустить последоватьльно ./makeBase_Modules, ./makeTestClient, ./makeTestServer.
	5.4. Зайти в TornadoEngine/Exe/ и запустить в одной вкладке ./Server, в другой ./Client.


Для корректной работы ECS (поиск вариантов использования GetByValue, GetByHas, GetByValue) поправить в boost::dll
... boost_1_71_0\boost\dll\detail\demangling\itanium.hpp 

Ищем функцию
template<typename Class, typename Func>
std::string mangled_storage_impl::get_mem_fn(const std::string &name) const

правим поиск demangled
    //auto found = std::find_if( storage_.begin(), storage_.end(), [&]( const entry& e ) { return e.demangled == matcher; } );
    auto found = std::find_if(storage_.begin(), storage_.end(), [&](const entry& e) {return e.demangled.find( matcher ) != std::string::npos;});
