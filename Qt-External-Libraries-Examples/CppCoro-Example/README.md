# CppCoro-Example

## Описание

Пример создания корутин с использованием CppCoro.

[Ссылка на библиотеку CppCoro](https://github.com/lewissbaker/cppcoro "CppCoro")

## Сборка проекта

В примере присутствуют два типа сборки - CMake и QMake.
Сборку можно производить из QtCreator или из папки build командами:

### CMake:

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
| Qt         | 5.15.2               |
| CMake      | 3.16.3               |
| gcc        | 9.4.0                |
| cppcoro    | cci.20230629         |

## Тестирование

- [ ] Windows
- [x] Linux (Ubuntu 24.04)
- [ ] Mac
