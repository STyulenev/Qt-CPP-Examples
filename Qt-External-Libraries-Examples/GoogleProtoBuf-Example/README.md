# GoogleProtoBuf-Example

Пример использования протокола сериализации структурированных данных Google Protocol Buffer (https://github.com/protocolbuffers/protobuf).

## Сборка проекта

1 - Необходимо собрать библиотеку LimeReport.
2 - Прописать пути к заголовочным файлам, файлам .ddl/.so и protoc в protobuf/CMakeLists.txt (для CMake) или protobuf/Protobuf.pri (для QMake).
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

| Название   | Версия               |
| -----------|----------------------|
| C++        | 20                   |
| Qt         | 6.4.0                |
| CMake      | 3.5                  |
| QMake      | 6.0.1 (6.0.0)        |
| MinGW      | 9.0.0 64 bit         |
| ProtoBuf   | v21.9                |

Тестировалось на ОС Windows 10 (сборка 19044.2604)
