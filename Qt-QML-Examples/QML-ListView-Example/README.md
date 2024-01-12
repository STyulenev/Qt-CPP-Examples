# QML-ListView-Example

## Описание

Пример использования ListView в QML на основе различных моделей:
- На основе ListModel (qml);
- На основе QAbstractListModel (с++);
- На основе XmlListModel (qml);
- На основе JSONListModel (qml - https://github.com/kromain/qml-utils);
- На основе ObjectModel (qml).

![alt text](doc/QML-ListView-Example.png)

## Сборка проекта

Проект может быть собран из QtCreator или из папки build коммандами:

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

Тестировалось на ОС Windows 11 22H2