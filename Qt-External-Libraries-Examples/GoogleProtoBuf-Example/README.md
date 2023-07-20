# GoogleProtoBuf-Example

## Описание

Пример использования протокола сериализации структурированных данных Google Protocol Buffer.

[Ссылка на исходники GoogleProtoBuf](https://github.com/protocolbuffers/protobuf "GoogleProtoBuf")

## Сборка проекта

1. Необходимо собрать библиотеку LimeReport.
2. Прописать пути к заголовочным файлам, файлам .ddl/.so и protoc в src/protobuf/CMakeLists.txt (для CMake) или src/protobuf/Protobuf.pri (для QMake).
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
| MinGW      | 9.0.0 64 bit         |
| ProtoBuf   | v21.9                |

## Тестирование

- [x] Windows (10, сборка 19044.2604)
- [ ] Linux
- [ ] Mac
