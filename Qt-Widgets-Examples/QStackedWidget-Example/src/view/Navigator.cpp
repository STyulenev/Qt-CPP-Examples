#include "Navigator.h"

namespace Views {

Navigator::Navigator(QStackedWidget* container, Screens::BaseScreen* startFragment) :
    m_container(container)
{
    connectScreen(startFragment);
    this->m_stackWidgets.append(startFragment);
    m_container->addWidget(m_stackWidgets.last());
    m_container->setCurrentIndex(0);
}

auto Navigator::next(Screens::BaseScreen* newFragment) -> void
{
    disconnectScreen(m_stackWidgets.last());
    connectScreen(newFragment);
    m_stackWidgets.append(newFragment);
    m_container->addWidget(newFragment);
    m_container->setCurrentWidget(newFragment);
}

auto Navigator::back() -> void
{
    m_container->removeWidget(m_stackWidgets.last());
    delete m_stackWidgets.last();
    m_stackWidgets.removeLast();
    connectScreen(m_stackWidgets.last());
    m_container->setCurrentWidget(m_stackWidgets.last());
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

auto Navigator::backToAndNext(QString screenName, Screens::BaseScreen* newFragment) -> void
{
    while (!m_stackWidgets.isEmpty()) {
        if (m_stackWidgets.last()->screenName() == screenName) {
            next(newFragment);
            break;
        } else {
            m_container->removeWidget(m_stackWidgets.last());
            delete m_stackWidgets.last();
            m_stackWidgets.removeLast();
        }
    }
}

auto Navigator::replace(Screens::BaseScreen* newFragment) -> void
{
    m_container->removeWidget(m_stackWidgets.last());
    disconnectScreen(m_stackWidgets.last());
    delete m_stackWidgets.last();
    m_stackWidgets.removeLast();
    m_stackWidgets.append(newFragment);
    connectScreen(newFragment);
    m_container->addWidget(newFragment);
}

auto Navigator::connectScreen(Screens::BaseScreen* fragment) -> void
{
    connect(fragment, &Screens::BaseScreen::back, this, &Navigator::back);
    connect(fragment, &Screens::BaseScreen::backTo, this, &Navigator::backTo);
    connect(fragment, &Screens::BaseScreen::backToAndNext, this, &Navigator::backToAndNext);
    connect(fragment, &Screens::BaseScreen::replace, this, &Navigator::replace);
    connect(fragment, &Screens::BaseScreen::next, this, &Navigator::next);
}

auto Navigator::disconnectScreen(Screens::BaseScreen* fragment) -> void
{
    disconnect(fragment, &Screens::BaseScreen::back, this, &Navigator::back);
    disconnect(fragment, &Screens::BaseScreen::backTo, this, &Navigator::backTo);
    disconnect(fragment, &Screens::BaseScreen::backToAndNext, this, &Navigator::backToAndNext);
    disconnect(fragment, &Screens::BaseScreen::replace, this, &Navigator::replace);
    disconnect(fragment, &Screens::BaseScreen::next, this, &Navigator::next);
}

} // namespace Views
