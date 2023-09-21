#pragma once

#include "ScreenPrecompile.h"

namespace Views {
    class Navigator;
}

namespace Screens {

class BaseScreen : public QWidget
{
    Q_OBJECT

    friend class Views::Navigator;

private:
    QString m_screenName;

public:
    explicit BaseScreen(QWidget* parent = nullptr);
    virtual ~BaseScreen() = default;

    auto screenName() const -> const QString&;
    auto setScreenName(const QString& newScreenName) -> void;

protected:
    virtual auto updateScreen() -> void = 0;
    virtual auto updateScreen(QVariant data) -> void = 0;

signals:
    auto back() -> void;
    auto back(QVariant data) -> void;
    auto backTo(QString screenName) -> void;
    auto backToAndNext(QString screenName, Screens::BaseScreen* newFragment) -> void;
    auto next(BaseScreen* newFragment) -> void;
    auto replace(BaseScreen* newFragment) -> void;

};

} // namespace Screens
