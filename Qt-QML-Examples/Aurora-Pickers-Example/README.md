# Aurora-Pickers-Example

## Описание

Пример использования пикеров и диалогов в Aurora/QML.

## Сборка проекта

Проект необходимо собирать с помощью Aurora IDE или из консоли:

### CMake:

```bash
mkdir build && cd build

alias sfdk=/path to Aurora IDE/bin/sfdk
sfdk config target=AuroraOS-5.1.0.100-base-armv7hl
sfdk build-init
sfdk build-shell cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug ../Aurora-Navigation-Example/
sfdk build-shell cmake --build . -j6
```
### CMake:

```bash
mkdir build && cd build

alias sfdk=/path to Aurora IDE/bin/sfdk
sfdk config target=AuroraOS-5.1.0.100-base-armv7hl
sfdk build-init
sfdk build-shell qmake -DCMAKE_BUILD_TYPE=Debug ../Aurora-Navigation-Example/
sfdk build-shell make
```

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 17                   |
| CMake      | 3.13                 |
| QMake      | 3.1                  |
| Qt         | 5.6.3                |
| Aurora     | 5.1.0.100            |
| MinGW      | 11.2 64 bit          |

Тестировалось на планшете T1100 (ARM) + Ubuntu 22.04