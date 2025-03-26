# QPluginLoader-Example

## Описание

Пример использования QPluginLoader для загрузки QML плагинов в runtime. TestPlugin - пример плагина.

![alt text](doc/QPluginLoader-Example.png)

## Использование

1. Собрать TestPlugin.
2. Добавить полученную dll или so в директорию plugins рядом с исполняемым файлом.
3. Собрать QPluginLoader-Example.
4. Запустить. В GUI будет загружен простейший qml компонент и отображён на экране.

## Сборка проекта

Сборку можно производить из QtCreator или из папки build командами:

### CMake:

```bash
cmake ..
sudo make install
```
> Для debug - "cmake -DCMAKE_BUILD_TYPE=Debug ..", для release - "cmake -DCMAKE_BUILD_TYPE=Release .."

### QMake:

```bash
qmake ..
sudo make install
```
> Для debug - "qmake .. CONFIG+=debug", для release - "qmake .. CONFIG+=release"

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

Тестировалось на ОС Windows 11 22H2