#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QStateMachine>
#include <QSignalTransition>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stateMachine = new QStateMachine(this);

    QState* state1 = new QState(stateMachine);
    state1->assignProperty(ui->yesButton, "enabled", true);
    state1->assignProperty(ui->noButton, "enabled", true);
    state1->assignProperty(ui->cancelButton, "visible", false);
    stateMachine->setInitialState(state1);

    QState* state2 = new QState(stateMachine);
    state2->assignProperty(ui->yesButton, "enabled", false);
    state2->assignProperty(ui->noButton, "enabled", false);
    state2->assignProperty(ui->cancelButton, "visible", true);
    stateMachine->setInitialState(state2);

    QSignalTransition* transition1 = state1->addTransition(ui->actionState_1, &QAction::triggered, state2);
    QSignalTransition* transition2 = state2->addTransition(ui->actionState_2, &QAction::triggered, state1);

    stateMachine->setInitialState(state1);
    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
