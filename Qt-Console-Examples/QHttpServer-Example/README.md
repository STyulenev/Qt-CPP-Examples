# QHttpServer-Example

## Описание

Пример использования HTTP сервера с добавлением, удалением и получением списка пользователей.

## Сборка проекта

В примере присутствуют два типа сборки - CMake и QMake.
Сборку можно производить из QtCreator или из папки build командами:

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

## Сборка и запуск через Docker контейнер

1. Создать образ.
1.1 С помощью CMake:
```bash
docker build  -t qhttpserver-example -f .\deploy\Dockerfile-Ubuntu-CMake .
```
1.2 С помощью QMake:
```bash
docker build  -t qhttpserver-example -f .\deploy\Dockerfile-Ubuntu-QMake .
```
2. Запуск контейнера:
```bash
docker run -p 8000:8000 qhttpserver-example
```

> При возникновении проблем смотреть Qt-CPP-Examples/Qt-External-Libraries-Examples/Docker-Example/README.md

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
| Docker     | 26.1.1               |

Тестировалось на ОС Windows 11 22H2

## Тестирование

- [x] Windows (11, сборка 22H2) без Docker
- [x] Linux (Ubuntu 18.04) в Docker
- [ ] Mac
