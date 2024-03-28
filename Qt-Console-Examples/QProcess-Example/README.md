# QProcess-Example

## Описание

Пример использования QProcess для взайимодействия с консолью.

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
| C++        | 17                   |
| Qt         | 5.12.8               |
| CMake      | 3.16.3               |
| gcc        | 9.4.0                |

Исходный код создавался на ОС Ubuntu 20.04.1

## Тестирование

- [x] Windows (11 22H2)
- [x] Linux (Ubuntu 20.04.1)
- [ ] Mac
