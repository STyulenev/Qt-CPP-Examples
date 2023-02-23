#include <TableViewModel.h>

namespace ViewModels {

struct TestModel {
    int id;
    QString firstName;
    QString lastName;
    QString title;
    QString text;
    bool status;
};

TableViewModel::TableViewModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    model = { { 1, "John",   "Adam",  "C++", "C++ (pronounced \"C plus plus\") is a"
                " high-level general-purpose programming language created by Danish computer"
                " scientist Bjarne Stroustrup as an extension of the C programming language, or \"C with Classes\".",
                true },
              { 2, "Philip", "Brown", "C#", "C# (pronounced see sharp) is a"
                " general-purpose, high-level multi-paradigm programming language. C# encompasses static typing,"
                " strong typing, lexically scoped, imperative, declarative, functional, generic, object-oriented"
                " (class-based), and component-oriented programming disciplines.",
                false },
              { 3, "Ben",    "Dixon", "Java",   "Java is a high-level, class-based, object-oriented"
                " programming language that is designed to have as few implementation dependencies as possible."
                " It is a general-purpose programming language intended to let programmers write once, run anywhere"
                " (WORA), meaning that compiled Java code can run on all platforms that support Java without the need to recompile.",
                false },
              { 4, "Roy",    "Ford",  "Python", "Python is a high-level, general-purpose programming language."
                " Its design philosophy emphasizes code readability with the use of significant indentation.",
                false }
            };
}

TableViewModel::~TableViewModel()
{

}

auto TableViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return 6;
}

auto  TableViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto TableViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (index.column()) {
        case 0: return model.at(index.row()).id;
        case 1: return model.at(index.row()).firstName;
        case 2: return model.at(index.row()).lastName;
        case 3: return model.at(index.row()).title;
        case 4: return model.at(index.row()).text;
        case 5: return model.at(index.row()).status;
            [[unlikely]] default: assert(!"Should not get here");
        }
    }

    if (role == Qt::TextAlignmentRole) {
        if (index.column() == 4)
            return Qt::AlignLeft;
        else
            return Qt::AlignCenter;
    }

    return QVariant();
}

auto TableViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled;
}

auto TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (role == Qt::DisplayRole ) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return "id";
            case 1: return "First Name";
            case 2: return "Last Name";
            case 3: return "Title";
            case 4: return "Text";
            case 5: return "Status";
                [[unlikely]] default: assert(!"Should not get here");
            }
        } else [[likely]] {
            return section + 1;
        }
    }

    return QVariant();
}

auto TableViewModel::setData(const QModelIndex& index, const QVariant& value, int role) -> bool
{
    if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            model[index.row()].id = value.toInt();
            break;
        case 1:
            model[index.row()].firstName = value.toString();
            break;
        case 2:
            model[index.row()].lastName = value.toString();
            break;
        case 3:
            model[index.row()].title = value.toString();
            break;
        case 4:
            model[index.row()].text = value.toString();
            break;
        case 5:
            model[index.row()].status = value.toBool();
            break;
        }

        emit dataChanged(index,index);
    }

    return true;
}

auto TableViewModel::insertRows(int position, int rows, [[maybe_unused]] const QModelIndex& parent) -> bool
{
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        TestModel data;
        data.id = position;
        data.status = false;

        model.insert(position, data);
    }

    endInsertRows();

    return true;
}

auto TableViewModel::removeRows(int position, int rows, [[maybe_unused]] const QModelIndex& parent) -> bool
{
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        model.removeAt(position);
    }

    endRemoveRows();

    return true;
}

} // namespace ViewModels
