# Примеры программ с использованием фреймворка Qt

## Структура проекта

```
Qt-CPP-Examples
│   README.md
│
└───doc
│   │
│   └───*.gif / *.png / ...
│
└───Qt-Console-Examples
│   │
│   └───...
│
└───Qt-External-Libraries-Examples
│   │
│   └───...
│
└───Qt-QML-Examples
│   │
│   └───...
│
└───Qt-Widgets-Examples
    │
    └───...

```

* doc - Директория для документации (gif / png / ...)
* Qt-Console-Examples - Директория с примерами консольных программ на Qt
* Qt-External-Libraries-Examples - Директория с примерами Qt + внешние библиотеки
* Qt-QML-Examples - Директория с QML примерами
* Qt-Widgets-Examples - Директория Qt примерами c использованием виджетов

## Qt-Console-Examples

### QHttpServer-Example

Пример использования HTTP сервера с добавлением, удалением и получением списка пользователей.

## Qt-External-Libraries-Examples

* Boost-Algorithms-Example - Примеры использования алгоритмов из библиотеки Boost
* Boost-Containers-Example - Примеры использования контейнеров из библиотеки Boost
* GoogleProtoBuf-Example - Пример использования протокола сериализации структурированных данных Google Protocol Buffer
* GoogleTest-Example - Пример использования библиотеки тестирования GoogleTest
* OpenMP-Example - Пример использования библиотеки распараллеливания программ OpenMP
* POCO-Example - Пример использования библиотеки сетевых мультиплатформенных приложений POCO
* QxORM-Example - Пример использования ORM библиотеки для Qt
* Docker-Example - Пример использования Docker для GUI приложения Qt (Vcxsrv + WSL2 для перенаправления окна)

## Qt-Widgets-Examples

### QListWidget-Example

Пример использования QListWidget с ui формой.

![alt text](doc/QListWidget-Example.png)

### QTableView-Delegates-Example

Пример использования делегатов для редактирования данных в ячейках QTableView.

![alt text](doc/QTableView-Delegates-Example.gif)

### QTableView-ProxyModel-Example

Пример использования proxy model для фильтрации данных view model при отображении в QTableView.

![alt text](doc/QTableView-ProxyModel-Example.gif)

### QTableView-QDataWidgetMapper-Example

Пример использования mapper для изменения данных в моделе таблицы QTableView.

![alt text](doc/QTableView-QDataWidgetMapper-Example.gif)

### QTableView-QSqlQueryModel-Example

Пример использования QSqlQueryModel для отображении данных из БД в QTableView.

### QTest-Example

Пример тестирования ui формы и других функций в Qt.

