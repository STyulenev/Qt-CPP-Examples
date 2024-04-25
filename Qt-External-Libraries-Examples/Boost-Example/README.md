# Boost-Example

## Примеры

* Boost-Algorithms-Example - Примеры использования алгоритмов из библиотеки Boost
* Boost-Containers-Example - Примеры использования контейнеров из библиотеки Boost
* Boost-DataStructures-Example - Примеры использования структур данных из библиотеки Boost
* Boost-FunctionalProgramming-Example - Примеры использования функциональных объектов из библиотеки Boost
* Boost-GenericProgramming-Example - Примеры использования универсального программирования и метапрограммирования шаблонов из библиотеки Boost
* Boost-MemoryManagement-Example - Примеры использования умных указателей из библиотеки Boost
* Boost-NumberHandling-Example - Примеры использования модуля работы с числами из библиотеки Boost
* Boost-StringHandling-Example - Примеры использования строк из библиотеки Boost
* Boost-Test-Example - Примеры использования тестов из библиотеки Boost

## Установка Boost для Windows

1. Скачать дистрибутив с официального сайта.
2. Распаковать в любую директорию, условно (в примерах - C:\3rdparty\)
3. Выполнить bootstrap.sh, для создания b2.
4. Выполнить b2.exe.

Для создания динамических библиотек и компилятора gcc:
```bash
.\b2 toolset=gcc link=shared
```

Для создания динамических библиотек и компилятора msvc:
```bash
.\b2 toolset=msvc link=shared
```

> Можно выбрать тип сборки variant=debug или variant=release

## Установка Boost для Linux (Ubuntu 20.04.0 LTS

Выполнить команду:
```bash
sudo apt-get install libboost-all-dev
```
