# CPack-Example

## Описание

Пример автоматизированной сборки deb пакета с инструментом упаковки CPack:
- исполняемый файл;
- динамическая библиотека.

 > Исполняемый файл и динамическая библиотека не связаны между собой.

## Сборка и пакетирование

Создаём директорию сборки и собираем проект:
```bash
mkdir build && cd build
cmake -G "xxxxx" -DCMAKE_TOOLCHAIN_FILE=aaa.cmake [options] --target-all -DCMAKE_INSTALL_PREFIX=/usr ..
make -j4
```

Где:
 - xxxx - тип генератора;
 - aaa.cmake - путь к файлу тулчейна при кроссплатформенной сборке;
 - 4 - количество потоков для сборки (если генератор однопоточный по умолчанию).

Сборка deb пакета:
```bash
cpack -G DEB
```

Проверка lintian
```bash
lintian <full_deb_name>
```

Установка deb пакета:
```bash
sudo dpkg --install <full_deb_name>
```

Удаление deb пакета:
```bash
sudo dpkg --remove <deb_name>
```

Где:
 - full_deb_name - название-пакета_текущая.версия_архитектура.deb (cpack-example_0.5_amd64.deb)
 - deb_name - название-пакета (cpack-example)
 
## Использование

Для подключения библиотеки:
```cmake
find_package(cpack-lib REQUIRED)

# ...

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CPACK_LIB_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    # ...
    cpack-lib # или ${CPACK_EXAMPLE_LIBS}
)
```

Для запуска испоняемого файла:
```bash
cpack-bin
```

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 20                   |
| Qt         | 6.4.0                |
| CMake      | 3.5                  |
| gcc        | 9.4.0                |

## Тестирование

- [ ] Windows
- [x] Linux (Ubuntu 20.04.1)
- [ ] Mac

