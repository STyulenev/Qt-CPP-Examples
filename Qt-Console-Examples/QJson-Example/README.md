# QJson-Example

## Описание

Пример использования QJson в Qt:
- QJsonArray
- QJsonDocument
- QJsonObject
- QJsonValue

## Сборка проекта

В примере присутствуют два типа сборки - CMake и QMake.
Сборку можно производить из QtCreator или из папки build коммандами:

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

| Название | Версия        |
| ---------|---------------|
| C++      | 20            |
| Qt       | 6.4.0         |
| CMake    | 3.5           |
| QMake    | 6.0.1 (6.0.0) |
| MinGW    | 9.0.0 64 bit  |

Тестировалось на ОС Windows 10 (сборка 19044.2604)