#pragma once

#include <QWizardPage>

namespace Ui {
    class ThirdPage;
}

namespace WizardPages {

class ThirdPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ThirdPage(QWidget* parent = nullptr);
    virtual ~ThirdPage();

protected:
    virtual auto nextId() const -> int;

private:
    Ui::ThirdPage* ui;

};

} // namespace WizardPages
