# QtUiPlugin-Example

## Описание

Пример использования QtUiPlugin для добавления новых виджетов в QtCreator.
В примере используется ToleranceBar ([Ссылка на исходники ToleranceBar](https://www.opendesktop.org/p/1132117 "ToleranceBar"))

![alt text](doc/QtUiPlugin-Example.png)

## Сборка проекта

В примере присутствуют два типа сборки - CMake и QMake.
Для сборки необходимы инструменты qttools:

```bash
sudo apt-get install qttools5-dev
```

Сборку можно производить из QtCreator или из папки build коммандами:

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

## Использование

1. Собранную библиотеку необходимо добавить в плагины qt: /usr/lib/x86_64-linux-gnu/qt5/plugins/designer/ (для x86). Это
необходимо, чтобы Qt Designer увидел виджеты и добавил в меню выбора. Для автоматизации процесса можно использовать CPack.

2. Заголовочные файлы так же добавить в /usr/include/x86_64-linux-gnu/qt5/QtUiPlugin или в любое другое удобное место.

3. Добавить в проект пути до библиотеки и заголовочных файлов.

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 17                   |
| Qt         | 5.12.8               |
| CMake      | 3.16.3               |
| gcc        | 9.4.0                |

## Тестирование

- [ ] Windows
- [x] Linux (Ubuntu 20.04.1)
- [ ] Mac