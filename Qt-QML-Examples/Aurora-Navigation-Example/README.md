# Aurora-Navigation-Example

## Описание

Пример использования стандартной навигации в Aurora/QML (from Silica).

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
### QMake:

```bash
mkdir build && cd build

alias sfdk=/path to Aurora IDE/bin/sfdk
sfdk config target=AuroraOS-5.1.0.100-base-armv7hl
sfdk build-init
sfdk build-shell qmake -DCMAKE_BUILD_TYPE=Debug ../Aurora-Navigation-Example/
sfdk build-shell make
```

Также необходимо в настройках подключить IDE к устройству с AuroraOS для тестирования.

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 11                   |
| CMake      | 3.5                  |
| QMake      | 3.1                  |
| Qt         | 5.6.3                |
| Aurora     | 5.1.0.100            |
| GCC        | 7.1                  |

Тестировалось на планшете T1100 (ARM) + Ubuntu 22.04