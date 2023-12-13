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
    int nextId() const;

private:
    Ui::ThirdPage* ui;

};

} // namespace WizardPages
