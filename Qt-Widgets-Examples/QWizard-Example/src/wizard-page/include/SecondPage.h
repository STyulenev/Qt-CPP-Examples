#pragma once

#include <QWizardPage>

namespace Ui {
    class SecondPage;
}

namespace WizardPages {

class SecondPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit SecondPage(QWidget* parent = nullptr);
    virtual ~SecondPage();

protected:
    virtual auto nextId() const -> int;

private:
    Ui::SecondPage* ui;

};

} // namespace WizardPages
