#pragma once

#include "BaseScreen.h"

#include <QStackedWidget>
#include <QStack>

namespace Views {

class Navigator : public QObject
{
    Q_OBJECT

private:
    QStackedWidget* m_container;
    QStack<Screens::BaseScreen*> m_stackWidgets;

public:
    explicit Navigator() = delete;
    explicit Navigator(QStackedWidget* container, Screens::BaseScreen* startFragment);
    virtual ~Navigator() = default;

private:
    auto connectScreen(Screens::BaseScreen* fragment) -> void;
    auto disconnectScreen(Screens::BaseScreen* fragment) -> void;

public slots:
    auto back() -> void;
    auto backTo(QString screenName) -> void;
    auto next(Screens::BaseScreen* newFragment) -> void;
    auto replace(Screens::BaseScreen* newFragment) -> void;

};

} // namespace Views
