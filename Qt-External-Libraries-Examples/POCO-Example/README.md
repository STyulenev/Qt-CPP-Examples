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

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 20                   |
| Qt         | 6.4.0                |
| CMake      | 3.5                  |
| QMake      | 6.0.1 (6.0.0)        |
| MSVC2019   | 17.4.33403.182 64 bit|
| Postman    | 10.0.0               |
| POCO       | 1.12.4               |

## Тестирование

- [x] Windows (10, сборка 19044.2604)
- [ ] Linux
- [ ] Mac
