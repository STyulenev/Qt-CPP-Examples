#pragma once

#include <QPixmap>

struct TestModel {
    int     id;
    QString name;
    QPixmap icon;
};

Q_DECLARE_METATYPE(TestModel);
