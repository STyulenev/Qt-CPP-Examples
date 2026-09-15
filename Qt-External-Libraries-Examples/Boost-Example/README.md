# Boost-Example

## Примеры

* Boost-Algorithms-Example - Примеры использования алгоритмов из библиотеки Boost
* Boost-Asio-Example - Примеры сетевого программирования из библиотеки Boost
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
2. Распаковать в любую директорию, условно (в примерах - C:\3rdparty\boost)
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

> При необходимости можно выбрать тип сборки: variant=debug или variant=release
> При необходимости можно добавить путь для установки, например: --prefix=C:\3rdparty\boost_1_85_0\boost-install install

Пример:
```bash
.\b2 toolset=gcc link=shared variant=release --prefix=C:\3rdparty\boost_1_85_0\boost-install install
```

## Установка Boost для Linux (Ubuntu 20.04.0 LTS)

Выполнить команду:
```bash
sudo apt-get install libboost-all-dev
```

## Установка Boost через conan

Пример conanfile.txt лежит в /Boost-Asio-Example. Или командами:
1. Необходимо скачать и установить Conan.
2. Создать профиль:

```bash
conan profile detect --force
```

3. Сгенерировать CMake файлы для поиска библиотек в папку build:

```bash
conan install . --output-folder=build --build=missing
```

> Если библиотек нет на локальной машине, Conan скачает их из conan-center и соберёт

4. Собрать проект (cборку можно производить из QtCreator или из папки build командами):

```bash
cmake ..
make
```
> Для debug - "cmake -DCMAKE_BUILD_TYPE=Debug ..", для release - "cmake -DCMAKE_BUILD_TYPE=Release .."

