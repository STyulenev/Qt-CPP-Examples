# CppUTest-Example

## Описание

Пример использования библиотеки тестирования CppUTest.

[Ссылка на исходники CppUTest](https://github.com/cpputest/cpputest "CppUTest")

## Сборка

### CMake:

1. Установить CppUTest (static, conan, fetch или другими способами).
2. Собрать проект (cборку можно производить из QtCreator или из папки build коммандами):

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
| MinGW      | 11.2 64 bit          |

## Тестирование

- [x] Windows 11 22H2
- [ ] Linux
- [ ] Mac