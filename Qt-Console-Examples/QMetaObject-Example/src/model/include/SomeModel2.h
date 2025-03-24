#pragma once

#include <QObject>

namespace Models {

class SomeModel2 : public QObject
{
    Q_OBJECT

public:
    explicit SomeModel2(QObject* parent = nullptr);
    ~SomeModel2();

public slots:
    QString getData();
    void setData(const QString& data);

private:
    QString data;

};

} // namespace Models
