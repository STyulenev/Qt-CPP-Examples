# QXlsx-Example

Пример использования библиотеки QXlsx для взаимодействия с таблицами Microsoft Excel (https://github.com/QtExcel/QXlsx).

## Сборка проекта

1 - Необходимо скачать и собрать библиотеку QXlsx.
2 - Прописать пути к заголовочным файлам и файлам .ddl/.so в СMakeLists.txt (для CMake) или QXlsx-Example.pro (для QMake).
3 - Собрать проект (cборку можно производить из QtCreator или из папки build коммандами):

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
| QXlsx      | 1.4.5         |

Тестировалось на ОС Windows 10 (сборка 19044.2604)