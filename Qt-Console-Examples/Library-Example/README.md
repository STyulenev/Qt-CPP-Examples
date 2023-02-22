# Library-Example

Пример использования статической и динамической библиотеки с несколькими проектами.

## Структура проекта

```
Library-Example
│   .gitignore
│   CMakeLists.txt
│   Library-Example.pro
│
└───build
│   │
│   └───.gitignore
│
└───ProjectOne
│   │
│   └───StaticLibrary
│       │
│       └───CMakeLists.txt
│           StaticLibrary.pro
│           ...
│       CMakeLists.txt
│       ProjectTwo.pro
│       ...
│       
└───ProjectTwo
│   │
│   └───CMakeLists.txt
│       ProjectTwo.pro
│       ...
│
└───SharedLibrary
    │
    └───CMakeLists.txt
        SharedLibrary.pro
        ...

```

* build - Директория для сборки
* ProjectOne - Первое приложение
* StaticLibrary - Статическая библиотека
* ProjectTwo - Второе приложение
* SharedLibrary - Динамическая библиотека