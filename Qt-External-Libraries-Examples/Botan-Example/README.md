# Botan-Example

## Описание

Пример использования библиотеки Botan для создания сертификатов X509.

[Ссылка на библиотеку Botan](https://github.com/randombit/botan "Botan")

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
> Проект в Qt следует запускать в терминале (поставить галочку в кладке сборка проекта), иначе не будут отображены логи.

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
| Botan         | 2.19.5               |

Тестировалось на ОС Windows 11 22H2

## Тестирование

- [x] Windows 11 22H2
- [ ] Linux
- [ ] Mac
