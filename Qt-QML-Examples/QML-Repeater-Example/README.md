# QML-Repeater-Example

## Описание

Пример использования Repeater в QML:
- Battery - пример создания компонента для уровня заряда батареи (горизонтальная/вертикальная).
- ButtonGroup - пример создания группы кнопок с передачей js-массива в Repeater.
- Carousel - пример carousel-компонента;
- SignalLevel - пример создания компонента для уровня сигнала.
- SimpleTable + SimpleTableModel - пример создания простой таблицы на основе пользовательской табличной модели.
- SoundLevel - пример создания компонента для уровня громкости.

![alt text](doc/QML-Repeater-Example-1.png)

![alt text](doc/QML-Repeater-Example-2.png)

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