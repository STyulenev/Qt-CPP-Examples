# QML-Animation-Example

## Описание

Пример использования анимации в пользовательских компонентах QML:
- AdvertisingContainer - анимированная рекламная панель (с анимацией выдвижения нижний панель и изменении размера текста);
- SquareSwitchButton - кнопка-переключатель (с примером анимации смены якорей);
- SwitchButton - кнопка-переключатель (с примером анимации перемещения ползунка и плавного изменения цвета);
- HidingContainer - сворачивающийся контейнер (с примерами анимированного изменения visible и height свойств);
- ...

![alt text](doc/QML-Animation-Example-1.gif)

![alt text](doc/QML-Animation-Example-2.gif)

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
| Qt Creator | 11.0.2               |
| Qt         | 6.5.2                |
| CMake      | 3.24.2               |
| QMake      | 6.5.2.0              |
| MinGW      | 11.2 64 bit          |

Тестировалось на ОС Windows 11 22H2