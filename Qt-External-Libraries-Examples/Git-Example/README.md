# Git-Example

## Описание

Пример использования системы контроля версий git для добавления подмодулей в cmake сборку:
 - git submodule;
 - FetchContent.

На примере:
 - toml (git submodule);
 - GoogleTest (git submodule);
 - Boost (FetchContent).

Команды для создания подмодулей:
```bash
git submodule add https://github.com/ToruNiina/toml11 extern/toml11
git submodule add https://github.com/google/googletest.git extern/googletest
```
> В папке с проектом необходимо инициализировать git: git init

## Сборка проекта

Команды для получения/обновления подмодулей:
```bash
git submodule update
```

Сборку можно производить из QtCreator или из папки build коммандами:

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
| Qt Creator | 11.0.2               |
| Qt         | 6.5.2                |
| CMake      | 3.24.2               |
| MinGW      | 11.2 64 bit          |

## Тестирование

- [x] Windows 11 22H2
- [ ] Linux
- [ ] Mac