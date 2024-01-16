#pragma once

#include <QWizardPage>

namespace Ui {
    class FinalPage;
}

namespace WizardPages {

class FinalPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit FinalPage(QWidget* parent = nullptr);
    virtual ~FinalPage();

    virtual auto initializePage() -> void;

private:
    Ui::FinalPage* ui;

};

} // namespace WizardPages
