#include "EditForm.h"
#include "ui_EditForm.h"

EditForm::EditForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditForm)
{
    ui->setupUi(this);

    ui->firstNameLineEdit->setPlaceholderText("first name...");
    ui->lastNameLineEdit->setPlaceholderText("last name...");
    ui->titleLineEdit->setPlaceholderText("title...");
    ui->textPlainTextEdit->setPlaceholderText("text...");
}

EditForm::~EditForm()
{
    delete ui;
}

auto EditForm::setModel(QAbstractTableModel* model) -> void
{
    mapper = std::make_shared<QDataWidgetMapper>();

    mapper->setOrientation(Qt::Horizontal);
    mapper->setModel(model);
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    mapper->addMapping(ui->idSpinBox,         0);
    mapper->addMapping(ui->firstNameLineEdit, 1);
    mapper->addMapping(ui->lastNameLineEdit,  2);
    mapper->addMapping(ui->titleLineEdit,     3);
    mapper->addMapping(ui->textPlainTextEdit, 4);
    mapper->addMapping(ui->statusCheckBox,    5);

    connect(ui->previousButton, &QPushButton::clicked, mapper.get(), &QDataWidgetMapper::toPrevious);
    connect(ui->nextButton, &QPushButton::clicked, mapper.get(), &QDataWidgetMapper::toNext);
    connect(mapper.get(), &QDataWidgetMapper::currentIndexChanged, this, &EditForm::updateButtons);
}

auto EditForm::editCurrentRow(int row) -> void
{
    mapper->setCurrentIndex(row);
}

auto EditForm::updateButtons(int row) -> void
{
    ui->previousButton->setEnabled(row > 0);
    ui->nextButton->setEnabled(row < mapper->model()->rowCount() - 1);
}
