#include <TableViewModel.h>

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

int TableViewModel::columnCount([[maybe_unused]] const QModelIndex& index) const
{
    return 6;
}

int TableViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const
{
    return model.length();
}

QVariant TableViewModel::data(const QModelIndex& index, int role) const
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

Qt::ItemFlags TableViewModel::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEnabled;
}

QVariant TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
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

bool TableViewModel::setData(const QModelIndex& index, const QVariant& value, int role)
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
