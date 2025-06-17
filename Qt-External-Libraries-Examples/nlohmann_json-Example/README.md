# nlohmann_json-Example

## Описание

Пример использования библиотеки nlohmann_json для работы с json.

[Ссылка на библиотеку nlohmann_json](https://github.com/nlohmann/json "nlohmann_json")

## Сборка проекта

1. Необходимо скачать и установить Conan.
2. Создать профиль:

```bash
conan profile detect --force
```

3. Сгенерировать CMake файлы для поиска библиотек в папку build:

```bash
conan install . --output-folder=build --build=missing
```

> Если библиотек нет на локальной машине, Conan скачает их из conan-center и соберёт

4. Собрать проект (cборку можно производить из QtCreator или из папки build командами):

```bash
cmake ..
make
```
> Для debug - "cmake -DCMAKE_BUILD_TYPE=Debug ..", для release - "cmake -DCMAKE_BUILD_TYPE=Release .."

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название      | Версия               |
| --------------|----------------------|
| C++           | 20                   |
| Qt Creator    | 13.0.2               |
| Qt            | 6.6.3                |
| CMake         | 3.24.2               |
| Conan         | 2.0.11               |
| MinGW         | 11.2 64 bit          |
| nlohmann_json | 3.12.0               |

Тестировалось на ОС Windows 11 22H2

## Тестирование

- [x] Windows
- [ ] Linux (Ubuntu 22.04 LTS)
- [ ] Mac
