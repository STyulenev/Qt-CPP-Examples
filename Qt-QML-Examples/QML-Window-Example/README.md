# QML-Window-Example

## Описание

Пример использования окон и диалогов в QML:

- MessageBox (custom window с загрузкой компонента и удалением);
- FileDialog (standart dialog);
- MessageDialog (standart dialog);
- ColorDialog (standart dialog);
- FolderDialog (standart dialog);
- FontDialog (standart dialog);
- Popup (standart popup).

![alt text](doc/QML-Window-Example.gif)

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