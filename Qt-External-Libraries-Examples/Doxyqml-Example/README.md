# Doxyqml-Example

## Описание

Пример использования Doxyqml для автоматической генерации документации qml-файлов при сборке.

[Ссылка на исходники Doxyqml](https://invent.kde.org/sdk/doxyqml "Doxyqml")

### Установка

```bash
sudo apt install doxygen
sudo apt install doxyqml
```

## Сборка

### CMake

Doxygen файл с настройками был уже создан командами:

```bash
cd docs && doxygen -g Doxyfile.in ..
```
Настройки для qml (doxyqml) добавлены в Doxyfile.in

Сборка проекта:

```bash
cd build
cmake ..
make
```

> make doc_doxygen - только для сборки документации

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 17                   |
| Qt         | 5.15.2               |
| CMake      | 3.16.3               |
| gcc        | 9.4.0                |
| Doxygen    | 1.9.8                |
| Doxyqml    | 0.3.0                |

## Тестирование

- [ ] Windows
- [x] Linux (Ubuntu 24.04.1)
- [ ] Mac
