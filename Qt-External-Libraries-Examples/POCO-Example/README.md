# POCO-Example

## Описание

Пример использования библиотеки сетевых мультиплатформенных приложений POCO.

[Ссылка на исходники POCO](https://github.com/pocoproject/poco "POCO")

## Сборка проекта

1. Необходимо скачать и собрать библиотеку POCO.
2. Прописать пути к заголовочным файлам и файлам .ddl/.so в СMakeLists.txt (для CMake) или src/Source.pri (для QMake).
3. Собрать проект (cборку можно производить из QtCreator или из папки build коммандами):

### CMake:

```bash
cmake ..
make
```
> Для debug - "cmake -DCMAKE_BUILD_TYPE=Debug ..", для release - "cmake -DCMAKE_BUILD_TYPE=Release .."

### QMake:

```bash
qmake ..
make
```
> Для debug - "qmake .. CONFIG+=debug", для release - "qmake .. CONFIG+=release"

## Сборка проекта с Conan

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

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 20                   |
| Qt Creator | 11.0.2               |
| Qt         | 6.5.2                |
| CMake      | 3.24.2               |
| QMake      | 6.5.2.0              |
| MinGW      | 11.2 64 bit          |
| Postman    | 10.0.0               |
| POCO       | 1.12.4               |

## Тестирование

- [x] Windows (11, сборка 22H2)
- [ ] Linux
- [ ] Mac
