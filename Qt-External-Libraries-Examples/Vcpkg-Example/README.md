# Vcpkg-Example

## Описание

Пример использования пакетного менеджера Vcpkg в Qt (на примере библиотеки boost 1.83.0 date_time).

[Ссылка на пакетный менеджер Vcpkg](https://github.com/microsoft/vcpkg "Vcpkg")

## Сборка проекта

1. Необходимо скачать и установить Vcpkg.
2. Собрать проект (cборку можно производить из QtCreator или из папки build командами):

```bash
cmake ..
make
```
> Для debug - "cmake -DCMAKE_BUILD_TYPE=Debug ..", для release - "cmake -DCMAKE_BUILD_TYPE=Release .."

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 20                   |
| Qt Creator | 11.0.2               |
| Qt         | 6.5.2                |
| CMake      | 3.24.2               |
| Vcpkg      | 2023.10.19 Release   |
| MinGW      | 11.2 64 bit          |

Тестировалось на ОС Windows 11 22H2
