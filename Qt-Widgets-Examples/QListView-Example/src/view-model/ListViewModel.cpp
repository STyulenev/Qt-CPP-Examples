#include <ListViewModel.h>
#include <QImage>

namespace ViewModels {

struct TestModel {
    int id;
    QString title;
    QImage  image;
    QString description;
};

ListViewModel::ListViewModel(QObject* parent) :
    QAbstractListModel(parent)
{
    model = {
              { 1, "China", QImage(":/res/china.png"), "China officially the People's Republic of China (PRC), is a country in East Asia."
                " It is the world's most populous country, with a population exceeding 1.4 billion." },
              { 2, "Germany", QImage(":/res/germany.png"), "Germany (Deutschland), officially the Federal Republic of Germany, is a federal "
                "parliamentary republic in central-western Europe." },
              { 3, "India", QImage(":/res/india.png"), "India, officially the United Republic of India, is a country in South Asia. It is the "
                "seventh-largest country by area, the most populous country with over 1.2 billion people, and the most populous democracy in the world." },
              { 5, "Russia", QImage(":/res/russia.png"), "Russia or the Russian Federation, is a transcontinental country spanning Eastern "
                "Europe and Northern Asia. It is the largest country in the world, encompassing one-eighth of Earth's inhabitable landmass." },
              { 6, "Spain", QImage(":/res/spain.png"), "Spain, the Kingdom of Spain is a state in south-west Europe. It occupies a large part "
                "of the Iberian Peninsula." },
              { 7, "United Kingdom", QImage(":/res/united-kingdom.png"), "The United Kingdom of Great Britain and Northern Ireland (the United "
                "Kingdom or the UK) is a constitutional monarchy comprising most of the British Isles." }
            };
}

ListViewModel::~ListViewModel()
{

}

auto ListViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return model.length();
}

auto ListViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    switch (role) {
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
    case Qt::DisplayRole:
        return model.at(index.row()).title;
    case Qt::ToolTipRole:
        return model.at(index.row()).description;
    case Qt::DecorationRole:
        return model.at(index.row()).image;
    }

    return QVariant();
}

auto ListViewModel::flags([[maybe_unused]] const QModelIndex& index) const -> Qt::ItemFlags
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}


} // namespace ViewModels
