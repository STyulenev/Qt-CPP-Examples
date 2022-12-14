#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    addItemInListWidget(":/res/cpp.png", "C++",
                        "C++ (pronounced \"C plus plus\") is a high-level general-purpose programming language created by"
                        " Danish computer scientist Bjarne Stroustrup as an extension of the C programming language, or \"C with Classes\".");

    addItemInListWidget(":/res/csharp.png", "C#",
                        "C# (pronounced see sharp) is a general-purpose, high-level multi-paradigm programming language."
                        " C# encompasses static typing, strong typing, lexically scoped, imperative, declarative, functional,"
                        " generic, object-oriented (class-based), and component-oriented programming disciplines.");

    addItemInListWidget(":/res/java.png", "Java",
                        "Java is a high-level, class-based, object-oriented programming language that is designed to have as few"
                        " implementation dependencies as possible. It is a general-purpose programming language intended to let"
                        " programmers write once, run anywhere (WORA), meaning that compiled Java code can run on all platforms"
                        " that support Java without the need to recompile.");

    addItemInListWidget(":/res/python.png", "Python",
                        "Python is a high-level, general-purpose programming language. Its design philosophy emphasizes code"
                        " readability with the use of significant indentation.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::addItemInListWidget(QString&& image, QString&& title, QString&& description) -> void
{
    QListWidgetItem* item = new QListWidgetItem();
    CustomWidget* widget = new CustomWidget(this);

    widget->setImage(std::move(image));
    widget->setTitle(std::move(title));
    widget->setDescription(std::move(description));

    item->setSizeHint(widget->sizeHint());

    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, widget);
}

