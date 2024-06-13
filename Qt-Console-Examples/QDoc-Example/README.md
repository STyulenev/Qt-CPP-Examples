# QDoc-Example

## Описание

Пример использования QDoc для создания документации C++ и QML файлов.

## Создание документации

Документация создаётся командами:
```bash
cd doc
qdoc config.qdocconf
```

Для ОС Windows (для версии 6.5.2 и компилятора gcc), если не задан путь для qdoc:
```bash
cd doc
C:\Qt\6.5.2\mingw_64\bin\qdoc.exe config.qdocconf
```

Пример использования стилей css взят из [Ссылка на исходники qdoc-example](https://github.com/retifrav/qdoc-example "qdoc-example")

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