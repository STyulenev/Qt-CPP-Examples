# QML-Translator-Example

## Описание

Пример использования QTranslator в QML. TranslationUtils используется для автоматического добавления qm файлов в файл ресурсов.

## Сборка проекта

1. Файлы перевода были созданы командами:

```bash
lupdate * -ts languages/test_en_EN.ts
lupdate * -ts languages/test_ru_RU.ts
```

2. Собрать проект. Проект может быть собран из QtCreator или из папки build коммандами:

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
| QMake      | 6.5.2.0              |
| MinGW      | 11.2 64 bit          |

Написана на ОС Windows 11 22H2

## Тестирование

- [x] Windows (11 22H2)
- [x] Linux (Ubuntu 22.04 LTS)
- [ ] Mac