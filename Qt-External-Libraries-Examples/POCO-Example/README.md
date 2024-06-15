# POCO-Example

## Описание

Пример использования библиотеки сетевых мультиплатформенных приложений POCO.

[Ссылка на исходники POCO](https://github.com/pocoproject/poco "POCO")

Для тестирования можно использовать http-клиенты:
 - Qt-Console-Examples/QNetworkAccessManager-Example;
 - Qt-External-Libraries-Examples/CURL-Example;
 - Qt-External-Libraries-Examples/libcpr-Example;
 - Postman.

Или любой другой.

## Сборка проекта

1. Необходимо скачать и собрать библиотеку POCO.
2. Прописать пути к заголовочным файлам и файлам .ddl/.so в СMakeLists.txt (для CMake) или src/Source.pri (для QMake).
3. Собрать проект (cборку можно производить из QtCreator или из папки build командами):

### CMake:

```bash
cmake ..
make
```
> Для debug - "cmake -DCMAKE_BUILD_TYPE=Debug ..", для release - "cmake -DCMAKE_BUILD_TYPE=Release .."

### QMake:

```bash
qmake ..
make
```
> Для debug - "qmake .. CONFIG+=debug", для release - "qmake .. CONFIG+=release"

## Сборка проекта с Conan

Qt >= 6.0.0 и Conan 2.0 загрузит библиотеку автоматически или командами:

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

## Сборка проекта с Vcpkg

Qt >= 6.0.0 и Vcpkg загрузит библиотеку автоматически или командами:

```bash
vcpkg install
```

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
| Postman    | 10.0.0               |
| POCO       | 1.12.4               |

## Тестирование

- [x] Windows (11, сборка 22H2)
- [ ] Linux
- [ ] Mac

## Возможные проблемы

 - Библиотека нашла БД старой или несовместимой версии (например, PostgreSQL), из-за чего не может быть собран модуль Data, DataPostgreSQL и т.д.
 - Произошла ошибка до установки заголовочных файлов в install директорию.
 - Модуль ActiveRecord не собирается (отключение опции сборки в CMake исправляет это, при условии, что модуль не успользуется).
