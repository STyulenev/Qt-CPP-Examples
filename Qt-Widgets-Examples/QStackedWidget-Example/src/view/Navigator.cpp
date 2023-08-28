#include "Navigator.h"

namespace Views {

Navigator::Navigator(QStackedWidget* container, Screens::BaseScreen* startScreen) :
    m_container(container)
{
    connectScreen(startScreen);
    this->m_stackWidgets.append(startScreen);
    m_container->addWidget(m_stackWidgets.last());
    m_container->setCurrentIndex(0);
}

auto Navigator::next(Screens::BaseScreen* newScreen) -> void
{
    disconnectScreen(m_stackWidgets.last());
    connectScreen(newScreen);
    m_stackWidgets.append(newScreen);
    m_container->addWidget(newScreen);
    m_container->setCurrentWidget(newScreen);
}

auto Navigator::back() -> void
{
    m_container->removeWidget(m_stackWidgets.last());
    delete m_stackWidgets.last();
    m_stackWidgets.removeLast();
    connectScreen(m_stackWidgets.last());
    m_container->setCurrentWidget(m_stackWidgets.last());
    m_stackWidgets.last()->updateScreen();
}

auto Navigator::backTo(QString screenName) -> void
{
    while (!m_stackWidgets.isEmpty()) {
        if (m_stackWidgets.last()->screenName() == screenName) {
            connectScreen(m_stackWidgets.last());
            m_container->setCurrentWidget(m_stackWidgets.last());
            break;
        } else {
            m_container->removeWidget(m_stackWidgets.last());
            delete m_stackWidgets.last();
            m_stackWidgets.removeLast();
        }
    }
}

auto Navigator::backToAndNext(QString screenName, Screens::BaseScreen* newScreen) -> void
{
    while (!m_stackWidgets.isEmpty()) {
        if (m_stackWidgets.last()->screenName() == screenName) {
            next(newScreen);
            break;
        } else {
            m_container->removeWidget(m_stackWidgets.last());
            delete m_stackWidgets.last();
            m_stackWidgets.removeLast();
        }
    }
}

auto Navigator::replace(Screens::BaseScreen* newScreen) -> void
{
    m_container->removeWidget(m_stackWidgets.last());
    disconnectScreen(m_stackWidgets.last());
    delete m_stackWidgets.last();
    m_stackWidgets.removeLast();
    m_stackWidgets.append(newScreen);
    connectScreen(newScreen);
    m_container->addWidget(newScreen);
}

auto Navigator::connectScreen(Screens::BaseScreen* screen) -> void
{
    connect(screen, &Screens::BaseScreen::back, this, &Navigator::back);
    connect(screen, &Screens::BaseScreen::backTo, this, &Navigator::backTo);
    connect(screen, &Screens::BaseScreen::backToAndNext, this, &Navigator::backToAndNext);
    connect(screen, &Screens::BaseScreen::replace, this, &Navigator::replace);
    connect(screen, &Screens::BaseScreen::next, this, &Navigator::next);
}

auto Navigator::disconnectScreen(Screens::BaseScreen* screen) -> void
{
    disconnect(screen, &Screens::BaseScreen::back, this, &Navigator::back);
    disconnect(screen, &Screens::BaseScreen::backTo, this, &Navigator::backTo);
    disconnect(screen, &Screens::BaseScreen::backToAndNext, this, &Navigator::backToAndNext);
    disconnect(screen, &Screens::BaseScreen::replace, this, &Navigator::replace);
    disconnect(screen, &Screens::BaseScreen::next, this, &Navigator::next);
}

} // namespace Views
