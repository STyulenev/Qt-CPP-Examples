# QSS-Example

## Описание

Пример использования стилей CSS (QSS) для изменения внешнего вида виджетов:
 - QMainWindow;
 - QHeaderView;
 - QTableCornerButton;
 - QTableView;
 - QPushButton;
 - QCheckBox;
 - QToolButton;
 - QTabWidget;
 - QGroupBox;
 - QLineEdit;
 - QProgressBar;
 - QComboBox;
 - QFrame (HLine, VLine);
 - QScrollBar;
 - QMessageBox;
 - QDateEdit;
 - QCalendarWidget.

![alt text](doc/QSS-Example.gif)

## Сборка проекта

Проект может быть собран из QtCreator или из папки build коммандами:

### CMake:

```bash
cmake -DCMAKE_BUILD_TYPE=type -G generator ..
cmake --build .
```
> type заменить на Debug, Release или другой
> generator заменить на Ninja, Unix Makefiles или другой

### QMake:

```bash
qmake CONFIG+=type ..
make
```
> type заменить на debug, release или другой

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
