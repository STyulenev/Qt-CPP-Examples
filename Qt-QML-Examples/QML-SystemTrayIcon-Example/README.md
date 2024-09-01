# QML-SystemTrayIcon-Example

## Описание

Пример использования SystemTrayIcon в QML.

![alt text](doc/QML-SystemTrayIcon-Example-1.png)

![alt text](doc/QML-SystemTrayIcon-Example-2.png)

## Сборка проекта

Проект может быть собран из QtCreator или из папки build командами:

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
| Qt Creator | 13.0.2               |
| Qt         | 6.6.3                |
| CMake      | 3.24.2               |
| QMake      | 6.6.3.0              |
| MinGW      | 11.2.0 64 bit        |

Тестировалось на ОС Windows 11 22H2