# Docker-Example

Пример использования Docker для GUI приложения Qt.

## Сборка проекта для Windows

1 - Установить Docker.
2 - Установить WSL2.
3 - Установить и запустить Vcxsrv.
4 - В Dockerfile указать ip DISPLAY (для перенаправления).
5 - Выполнить комманды:

```
docker build -t docker-cpp-sample .
docker run docker-cpp-sample
```

