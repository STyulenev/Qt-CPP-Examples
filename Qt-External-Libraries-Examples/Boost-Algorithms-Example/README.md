# Boost-Algorithms-Example

## Описание

Изучение темы "Algorithms" и примеры использования классов из библиотеки Boost:
- Boost.Algorithm
- Boost.Range
- Boost.Graph

[Ссылка на исходники Boost](https://github.com/boostorg/boost "Boost")

## Сборка проекта

1. Необходимо cкачать и собрать библиотеку Boost.
2. Прописать пути к заголовочным файлам и файлам .ddl/.so в СMakeLists.txt (для CMake) или Boost-Algorithms-Example.pro (для QMake).
3. Собрать проект (cборку можно производить из QtCreator или из папки build коммандами):

```
cmake ..
make
```
или

```
qmake ../-project
qmake ..
make
```

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия        |
| -----------|---------------|
| C++        | 20            |
| Qt         | 6.4.0         |
| CMake      | 3.5           |
| QMake      | 6.0.1 (6.0.0) |
| MinGW      | 9.0.0 64 bit  |
| Boost      | 1.81.0        |

## Тестирование

- [x] Windows (10, сборка 19044.2604)
- [ ] Linux
- [ ] Mac
