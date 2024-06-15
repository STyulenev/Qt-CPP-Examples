# Boost-Containers-Example

## Описание

Изучение темы "Containers" и примеры использования классов из библиотеки Boost:
- Boost.MultiIndex
- Boost.Bimap
- Boost.Array
- Boost.Unordered
- Boost.CircularBuffer
- Boost.Heap
- Boost.Intrusive
- Boost.MultiArray
- Boost.Container

[Ссылка на исходники Boost](https://github.com/boostorg/boost "Boost")

## Сборка проекта

1. Необходимо cкачать и собрать библиотеку Boost.
2. Прописать пути к заголовочным файлам и файлам .ddl/.so в containers-examples/СMakeLists.txt (для CMake) или containers-examples/Source.pri (для QMake).
3. Собрать проект (cборку можно производить из QtCreator или из папки build командами):

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
| Qt Creator | 11.0.2               |
| Qt         | 6.5.2                |
| CMake      | 3.24.2               |
| QMake      | 6.5.2.0              |
| MinGW      | 11.2 64 bit          |
| Boost      | 1.81.0               |

## Тестирование

- [x] Windows (11, сборка 22H2)
- [ ] Linux
- [ ] Mac
