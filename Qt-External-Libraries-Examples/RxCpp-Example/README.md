# RxCpp-Example

## Описание

Пример использования библитеки реактивных расширений RxCpp для стандартной библиотеки STL.

[Ссылка на исходники RxCpp](https://github.com/ReactiveX/RxCpp "RxCpp")

## Сборка

### CMake:

1. Скачать и установить RxCpp.
2. Указать пути в src/view/CMakeLists.txt.
3. Собрать проект (cборку можно производить из QtCreator или из папки build коммандами):

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

Тестировалось на ОС Windows 11 22H2