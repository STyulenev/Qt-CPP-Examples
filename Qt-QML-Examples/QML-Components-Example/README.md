# QML-Components-Example

## Описание

Примеры использования дополнительных пользовательских компонентов в QML/C++.

QML компоненты:
- Label + TextField (с различным расположением label - снизу, сверху, слева или справа);
- Label + ComboBox (с различным расположением label - снизу, сверху, слева или справа);

С++ компоненты:
- AssyncController - (не визуальный) компонент/контроллер для выноса QML/js функции в другой поток через C++/QtConcurrent;
- Circle - (визуальный) компонент для отображения простого круга с обработкой клика + enum из С++ и QML/js;
- DateTime - (не визуальный) компонент для получения времени/даты из c++ слоя;

Библиотеки:
- uilib - пример вынесения qml и c++ в отдельную библиотеку-плагин;
- ...

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

## Сборка с  Docker
Собрать (заменить your_ip_address на свой ip):
```bash
docker build -t qml-example --build-arg IP_ADDRESS='your ip addres' .
```

Запуск контейнера:
```bash
docker run qml-example
```

> Дополнительно потребуется VcXsrv Windows X Server для проброса экрана (см. Qt-CPP-Examples/Qt-External-Libraries-Examples/Docker-Example/README.md)

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 20                   |
| Qt         | 6.4.0                |
| CMake      | 3.5                  |
| QMake      | 6.0.1 (6.0.0)        |
| MinGW      | 9.0.0 64 bit         |

Тестировалось на ОС Windows 10 (сборка 19044.2604)