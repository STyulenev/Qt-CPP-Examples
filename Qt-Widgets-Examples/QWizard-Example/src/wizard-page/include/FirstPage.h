#pragma once

#include <QWizardPage>

namespace Ui {
    class FirstPage;
}

namespace WizardPages {

class FirstPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit FirstPage(QWidget* widget = nullptr);
    virtual ~FirstPage();

protected:
    virtual auto nextId() const -> int;
    virtual auto validatePage() -> bool;

private:
    Ui::FirstPage* ui;

};

} // namespace WizardPages
