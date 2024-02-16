# Doctest-Example

## Описание

Пример использования однофайлового модуля тестирования Doctest.

[Ссылка на исходники Doctest](https://github.com/doctest/doctest "Doctest")

## Сборка

### CMake:

Собрать проект (cборку можно производить из QtCreator или из папки build коммандами):

```bash
cmake ..
make
```
> Для debug - "cmake -DCMAKE_BUILD_TYPE=Debug ..", для release - "cmake -DCMAKE_BUILD_TYPE=Release .."

Файл doctest.h будет автоматически загружен с github.

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 20                   |
| Qt Creator | 11.0.2               |
| Qt         | 6.5.2                |
| CMake      | 3.24.2               |
| MinGW      | 11.2 64 bit          |

Тестировалось на ОС Windows 11 22H2