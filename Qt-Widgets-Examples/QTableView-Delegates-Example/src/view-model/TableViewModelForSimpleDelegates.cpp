#include "TableViewModelForSimpleDelegates.h"

#include <QTime>
#include <QDate>

namespace ViewModels {
	
const QString text = "C++ is a high-level general-purpose programming language created by Danish computer "
        "scientist Bjarne Stroustrup as an extension of the C programming language, or 'C with Classes'.";

struct TestModelSimple {
    int     line_0;
    QString line_1;
    int     line_2;
    double  line_3;
    QTime   line_4;
    QDate   line_5;
    int     line_6;
    QString line_7;
	QString line_8;
};

TableViewModelForSimpleDelegates::TableViewModelForSimpleDelegates(QObject* parent) :
    QAbstractTableModel(parent)
{
    model = { { 1, "string", 12, 12.34, QTime::currentTime(), QDate::currentDate(), 20, "A", text },
              { 2, "string", 15, 34.34, QTime::currentTime(), QDate::currentDate(), 30, "B", text },
              { 3, "string", 35, 45.23, QTime::currentTime(), QDate::currentDate(), 40, "C", text },
              { 4, "string", 23, 123.2, QTime::currentTime(), QDate::currentDate(), 50, "D", text }
            };
}

TableViewModelForSimpleDelegates::~TableViewModelForSimpleDelegates()
{

}

auto TableViewModelForSimpleDelegates::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 9;
}

auto TableViewModelForSimpleDelegates::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto TableViewModelForSimpleDelegates::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role ==Qt::TextAlignmentRole)
        return Qt::AlignCenter;

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return model.at(index.row()).line_0;
        case 1: return model.at(index.row()).line_1;
        case 2: return model.at(index.row()).line_2;
        case 3: return model.at(index.row()).line_3;
        case 4: return model.at(index.row()).line_4;
        case 5: return model.at(index.row()).line_5;
        case 6: return model.at(index.row()).line_6;
        case 7: return model.at(index.row()).line_7;
		case 8: return model.at(index.row()).line_8;
        [[unlikely]] default: assert(!"Should not get here");
        }
    }

    return QVariant();
}

auto TableViewModelForSimpleDelegates::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

auto TableViewModelForSimpleDelegates::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "ReadOnly";
            case 1: return "LineEdit";
            case 2: return "SpinBox";
            case 3: return "DoubleSpinBox";
            case 4: return "TimeEdit";
            case 5: return "DateEdit";
            case 6: return "Slider";
            case 7: return "ComboBox";
			case 8: return "MultiLineText";
            [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section;
        }
    }

    return QVariant();
}

auto TableViewModelForSimpleDelegates::setData(const QModelIndex& index, const QVariant& value, int role) -> bool
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
        case 7:
            model[index.row()].line_7 = value.toString();
            break;
		case 8:
            model[index.row()].line_8 = value.toString();
            break;
        }

        emit dataChanged(index,index);
    }

    return true;
}

} // namespace ViewModels
