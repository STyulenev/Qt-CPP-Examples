# cpprestsdk-Example

## Описание

Пример создания HTTP сервера с использованием cpprestsdk.

[Ссылка на библиотеку cpprestsdk](https://github.com/microsoft/cpprestsdk "cpprestsdk")

## Сборка проекта

В примере присутствуют два типа сборки - CMake и QMake.
Сборку можно производить из QtCreator или из папки build командами:

### CMake:

```bash
cmake ..
make
```
> Для debug - "cmake -DCMAKE_BUILD_TYPE=Debug ..", для release - "cmake -DCMAKE_BUILD_TYPE=Release .."

## Сборка и запуск через Docker контейнер

1. Создать образ. С помощью CMake:
```bash
docker build  -t cpprestsdk-example -f .\Dockerfile .
```
2. Запуск контейнера:
```bash
docker run -p 8000:8000 cpprestsdk-example
```

> При возникновении проблем смотреть Qt-CPP-Examples/Qt-External-Libraries-Examples/Docker-Example/README.md

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 17                   |
| Qt         | 5.15.2               |
| CMake      | 3.16.3               |
| gcc        | 9.4.0                |
| Docker     | 26.1.1               |

## Тестирование

- [x] Windows (через Docker)
- [x] Linux (Ubuntu 24.04)
- [ ] Mac
