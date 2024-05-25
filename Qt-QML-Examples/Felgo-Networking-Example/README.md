# Felgo-Networking-Example

## Описание

Примеры создания HTTP запросов в Felgo/QML/С++ на основе:
 - Стандартного Felgo.HttpRequest (Felgo/QML);
 - Стандартного Felgo.HttpRequest + Promise (Felgo/QML);
 - Стандартного XMLHttpRequest (QML ~ QNetworkRequest и QNetworkReply);
 - Пользовательского AbstractHttpClient/CustomHttpClient (C++/QNetworkAccessManager);
 - ... 

![alt text](doc/Felgo-Networking-Example.png)

Для тестирования можно использовать http-серверы:
 - Qt-Console-Examples/QHttpServer-Example;
 - Qt-External-Libraries-Examples/POCO-Example;
 - ...

## Сборка проекта

Проект необходимо собирать с помощью Felgo IDE.

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 20                   |
| Qt Creator | 11.0.2               |
| Qt         | 6.4.1                |
| CMake      | 3.24.2               |
| Felgo      | 4.1.0                |
| MinGW      | 11.2 64 bit          |

Тестировалось на ОС Windows 11 22H2