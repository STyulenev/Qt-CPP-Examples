#pragma once

#include <Entity>

#include <QDebug>

class DAO
{
private:
    static DAO* self;

    DAO() {}
    DAO(const DAO&);
    auto operator=(DAO&) -> DAO&;

public:
    static DAO* getConnection();

    /*!
     * \brief Получить список всех Customer
     * \return ListCustomer \see "Customer.h"
     */
    auto getListOfCustomers() -> ListCustomer;

    /*!
     * \brief Получить список всех Order
     * \return ListOrder \see "Order.h"
     */
    auto getListOfOrders() -> ListOrder;

    /*!
     * \brief Получить список всех Product
     * \return ListProduct \see "Product.h"
     */
    auto getListOfProducts() -> ListProduct;

    /*!
     * \brief Получить список Customer с дополнительными условиями WHERE
     * \return ListCustomer \see "Customer.h"
     */
    auto getListOfCustomersWithWhere(/* ... */) -> ListCustomer;

    /*!
     * \brief Получить список Order с дополнительными условиями WHERE
     * \return ListOrder \see "Order.h"
     */
    auto getListOfOrdersWithWhere(/* ... */) -> ListOrder;

    /*!
     * \brief Получить список Product с дополнительными условиями WHERE
     * \return ListProduct \see "Product.h"
     */
    auto getListOfProductsWithWhere(/* ... */) -> ListProduct;

    /*!
     * \brief Вставка новой записи Customer с использованием qx::dao::insert (Customer object)
     */
    auto insertNewCustomer(/* ... */) -> void;

    /*!
     * \brief Вставка новой записи в таблицу Product с использованием полного запроса qx::QxSqlQuery
     */
    auto insertNewProduct(/* ... */) -> void;

    /*!
     * \brief Удаление записи Customer с использованием qx::dao::delete_by_query по id
     */
    auto deleteCustomer(/* ... */) -> void;
};

