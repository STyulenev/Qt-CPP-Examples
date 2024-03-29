#include "BaseScreen.h"

namespace Screens {

BaseScreen::BaseScreen(QWidget* parent) :
    QWidget(parent)
{

}

auto BaseScreen::screenName() const -> const QString&
{
    return m_screenName;
}

auto BaseScreen::setScreenName(const QString& newScreenName) -> void
{
    m_screenName = newScreenName;
}

} // namespace Screens
