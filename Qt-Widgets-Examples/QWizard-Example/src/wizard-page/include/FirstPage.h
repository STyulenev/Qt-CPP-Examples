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
    explicit FirstPage(QWidget* parent = nullptr);
    virtual ~FirstPage();

protected:
    int nextId() const;

private:
    Ui::FirstPage* ui;

};

} // namespace WizardPages
