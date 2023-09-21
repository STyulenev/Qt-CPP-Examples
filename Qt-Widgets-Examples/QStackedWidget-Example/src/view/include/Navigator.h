#pragma once

#include "BaseScreen.h"

#include <QStack>
#include <QStackedWidget>

namespace Views {

class Navigator : public QObject
{
    Q_OBJECT

private:
    QStackedWidget* m_container;
    QStack<Screens::BaseScreen*> m_stackWidgets;

public:
    explicit Navigator() = delete;
    explicit Navigator(QStackedWidget* container, Screens::BaseScreen* startScreen);
    virtual ~Navigator() = default;

private:
    auto connectScreen(Screens::BaseScreen* screen) -> void;
    auto disconnectScreen(Screens::BaseScreen* screen) -> void;

public slots:
    auto back() -> void;
    auto back(QVariant data) -> void;
    auto backTo(QString screenName) -> void;
    auto backToAndNext(QString screenName, Screens::BaseScreen* newScreen) -> void;
    auto next(Screens::BaseScreen* newScreen) -> void;
    auto replace(Screens::BaseScreen* newScreen) -> void;

};

} // namespace Views
