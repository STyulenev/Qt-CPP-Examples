# Docker-Example

## Описание

Пример использования Docker для GUI приложения Qt.

![alt text](doc/Docker-Example.png)

## Сборка проекта для Windows

1. Установить Docker.
2. Установить WSL2.
3. Установить и запустить VcXsrv Windows X Server.
4. Для перенаправления GUI, необходимо указать ip в переменную IP_ADDRESS.
5. Команды для создание образа и запуска контейнера:

```bash
docker build  -t docker-example -f .\deploy\Dockerfile --build-arg IP_ADDRESS='your ip addres' .
docker run docker-example
```

Если необходимо запустить контейнер и работать в нём через командную строку (следует убрать ENTRYPOINT и пересоздать образ):
```bash
docker run -it docker-example sh
```

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
| VcXsrv     | 1.17.0.0-3           |
| Docker     | 26.1.1               |

Тестировалось на ОС Windows 11 22H2

## Тестирование

- [x] Windows (11, сборка 22H2) без Docker
- [x] Linux (Ubuntu 18.04) в Docker
- [ ] Mac
