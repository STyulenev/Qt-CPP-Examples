#include "TableViewModelForSimpleDelegates.h"

#include <QTime>
#include <QDate>

struct TestModel {
    int id;
    QString line_1;
    int     line_2;
    double  line_3;
    QTime   line_4;
    QDate   line_5;
    int     line_6;
};

TableViewModelForSimpleDelegates::TableViewModelForSimpleDelegates(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { 1, "string", 12, 12.34, QTime::currentTime(), QDate::currentDate(), 20 },
              { 2, "string", 15, 34.34, QTime::currentTime(), QDate::currentDate(), 30 },
              { 3, "string", 35, 45.23, QTime::currentTime(), QDate::currentDate(), 40 },
              { 4, "string", 23, 123.2, QTime::currentTime(), QDate::currentDate(), 50 }
            };
}

TableViewModelForSimpleDelegates::~TableViewModelForSimpleDelegates()
{

}

int TableViewModelForSimpleDelegates::columnCount([[maybe_unused]] const QModelIndex& index) const
{
    return 7;
}

int TableViewModelForSimpleDelegates::rowCount([[maybe_unused]] const QModelIndex& index) const
{
    return model.length();
}

QVariant TableViewModelForSimpleDelegates::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole) {


        switch (index.column()) {
        case 0: return model.at(index.row()).id;
        case 1: return model.at(index.row()).line_1;
        case 2: return model.at(index.row()).line_2;
        case 3: return model.at(index.row()).line_3;
        case 4: return model.at(index.row()).line_4;
        case 5: return model.at(index.row()).line_5;
        case 6: return model.at(index.row()).line_6;
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

Qt::ItemFlags TableViewModelForSimpleDelegates::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

QVariant TableViewModelForSimpleDelegates::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "id";
            case 1: return "LineEdit";
            case 2: return "SpinBox";
            case 3: return "DoubleSpinBox";
            case 4: return "TimeEdit";
            case 5: return "DateEdit";
            case 6: return "Slider";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

bool TableViewModelForSimpleDelegates::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            break;
        case 1:
            model[index.row()].line_1 = value.toString();
            break;
        case 2:
            model[index.row()].line_2 = value.toInt();
            break;
        case 3:
            model[index.row()].line_3 = value.toDouble();
            break;
        case 4:
            model[index.row()].line_4 = value.toTime();
            break;
        case 5:
            model[index.row()].line_5 = value.toDate();
            break;
        case 6:
            model[index.row()].line_6 = value.toInt();
            break;
        }

        emit dataChanged(index,index);
    }

    return true;
}
