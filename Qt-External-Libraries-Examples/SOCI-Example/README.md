# SOCI-Example

## Описание

Пример использования библиотеки SOCI для взаимодействия с базами данных PostgreSQL.

[Ссылка на исходники SOCI](https://github.com/SOCI/soci "SOCI")

![alt text](doc/SOCI-Example.png)

## Сборка проекта

1. Необходимо скачать и собрать библиотеку PostgreSQL.
2. Сгенерировать базу данных (или doc/create_database.sql):

``` sql
CREATE DATABASE test_db;

CREATE TABLE IF NOT EXISTS Customers
(
    id         SERIAL PRIMARY KEY,
    first_name CHARACTER VARYING(30) NOT NULL,
    last_name  CHARACTER VARYING(30) NOT NULL,
    e_mail     CHARACTER VARYING(50) UNIQUE,
    age        INTEGER DEFAULT 18 CHECK(age > 0 AND age < 100)
);

CREATE TABLE IF NOT EXISTS Products
(
    id SERIAL PRIMARY KEY,
    product_type CHARACTER VARYING(30) NOT NULL,
    product_name CHARACTER VARYING(30) NOT NULL,
    manufacturer CHARACTER VARYING(30) NOT NULL,
    product_count INTEGER DEFAULT 0,
    price BIGINT CHECK(price > 0)
);

CREATE TABLE IF NOT EXISTS Orders
(
    id SERIAL PRIMARY KEY,
    customer_id INTEGER,
    product_id  INTEGER,
    quantity INTEGER NOT NULL CHECK(quantity > 0),
    order_date DATE,
    order_time TIME,
    FOREIGN KEY (customer_id) REFERENCES Customers (id) ON DELETE RESTRICT,
    FOREIGN KEY (product_id) REFERENCES Products (id) ON DELETE RESTRICT
);

INSERT INTO Customers VALUES (default, 'Roy', 'Jones', 'roy_jones@gmail.com', 19);
INSERT INTO Customers VALUES (default, 'Philip', 'Morgan', 'philip_morgan@yandex.com', 24);
INSERT INTO Customers VALUES (default, 'Mary', 'Parker', 'mary_parker@free.com', 43);

INSERT INTO Products VALUES (default, 'Phone', 'iPhone 14', 'Apple', 3, 98000);
INSERT INTO Products VALUES (default, 'Phone', 'Galaxy A23', 'Samsung', 2, 55000);
INSERT INTO Products VALUES (default, 'Phone', 'Redmi 12T', 'Xiaomi', 7, 46000);
INSERT INTO Products VALUES (default, 'Laptop', 'RedmiBook 15', 'Xiaomi', 4, 46000);
INSERT INTO Products VALUES (default, 'Laptop', 'V15', 'Lenovo', 6, 46000);

INSERT INTO Orders VALUES (default, 1, 1, 2, '2022-01-08', '12:21:34');
INSERT INTO Orders VALUES (default, 2, 3, 1, '2022-01-04', '10:41:54');
INSERT INTO Orders VALUES (default, 3, 5, 1, '2022-01-12', '16:09:12');
```
3. Скачать и собрать библиотеку SOCI.
4. Прописать пути к заголовочным файлам и файлам .ddl/.so в src/СMakeLists.txt (для CMake) или src/Source.pri (для QMake).
5. Собрать проект (cборку можно производить из QtCreator или из папки build коммандами):

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

## Версии

Версии сред, языков и утилит, которые использовались на момент написания проекта.

| Название   | Версия               |
| -----------|----------------------|
| C++        | 20                   |
| Qt Creator | 11.0.2               |
| Qt         | 6.5.2                |
| CMake      | 3.24.2               |
| MinGW      | 11.2 64 bit          |
| PostgreSQL | 16                   |

## Тестирование

- [x] Windows 11 22H2
- [ ] Linux
- [ ] Mac

## Возможные проблемы

 - Отсутствуют пути в переменных среды к PostgreSQL.
 - Кирилица в пути утстановки PostgreSQL.
 - Косые черты в стиле Windows (\), необходимы в стиле Unix (/).
 - CMake не видит версию PostgreSQL (следует добавить - set(PostgreSQL_ADDITIONAL_VERSIONS "16")).