#include <Test_MainWindow.h>

#include <QLineEdit>
#include <QPushButton>

Test_MainWindow::Test_MainWindow(QObject* parent) :
    QObject(parent)
{

}

auto Test_MainWindow::test_nameLineEdit() -> void
{
    auto lineEdit = window.findChild<QLineEdit*>("nameLineEdit");

    QTest::keyClicks(lineEdit, "123t");
    QCOMPARE(lineEdit->text(), "t");

    lineEdit->clear();
    QTest::keyClicks(lineEdit, "123aaa");
    QCOMPARE(lineEdit->text(), "aaa");

    lineEdit->clear();
    QTest::keyClicks(lineEdit, "Name");
    QCOMPARE(lineEdit->text(), "Name");

    lineEdit->clear();
    QVERIFY2(lineEdit->text().isEmpty(), "nameLineEdit not empty");
}

auto Test_MainWindow::test_ipAddressLineEdit() -> void
{
    auto lineEdit = window.findChild<QLineEdit*>("ipAddressLineEdit");

    lineEdit->clear();
    QTest::keyClicks(lineEdit, "000.000.000.000");
    QCOMPARE(lineEdit->text(), "0.0.0.0");

    lineEdit->clear();
    QTest::keyClicks(lineEdit, "qwerty");
    QCOMPARE(lineEdit->text(), "");

    lineEdit->clear();
    QTest::keyClicks(lineEdit, "1jygb2.hbby3.435jlkf.899");
    QCOMPARE(lineEdit->text(), "12.3.43.89");

    lineEdit->clear();
    QTest::keyClicks(lineEdit, "1.1.1.1.");
    QCOMPARE(lineEdit->text(), "1.1.1.1");

    lineEdit->clear();
    QVERIFY2(lineEdit->text().isEmpty(), "ipAddressLineEdit not empty");
}

auto Test_MainWindow::test_emailLineEdit() -> void
{
    auto lineEdit = window.findChild<QLineEdit*>("emailLineEdit");

    lineEdit->clear();
    QTest::keyClicks(lineEdit, "@@@");
    QCOMPARE(lineEdit->text(), "");

    lineEdit->clear();
    QTest::keyClicks(lineEdit, "email@gmail.com");
    QCOMPARE(lineEdit->text(), "email@gmail.com");

    lineEdit->clear();
    QTest::keyClicks(lineEdit, "....email@gmail.com");
    QCOMPARE(lineEdit->text(), "email@gmail.com");

    lineEdit->clear();
    QVERIFY2(lineEdit->text().isEmpty(), "ipAddressLineEdit not empty");
}

auto Test_MainWindow::test_pushButton() -> void
{
    auto nameLineEdit = window.findChild<QLineEdit*>("nameLineEdit");
    auto ipAddressLineEdit = window.findChild<QLineEdit*>("ipAddressLineEdit");
    auto pushButton = window.findChild<QPushButton*>("pushButton");

    nameLineEdit->clear();
    QTest::keyClicks(nameLineEdit, "Name");

    ipAddressLineEdit->clear();
    QTest::keyClicks(ipAddressLineEdit, "0.0.0.0");

    QTest::mouseClick(pushButton, Qt::LeftButton);
    QCOMPARE(window.status, true);
}

auto Test_MainWindow::test_bench() -> void
{
    QBENCHMARK {
        std::vector<QString> vector;
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");

        std::vector<QString> vector2(vector);
    }
}

auto Test_MainWindow::test_bench2() -> void
{
    QBENCHMARK {
        std::vector<QString> vector;
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");

        std::vector<QString> vector2(std::move(vector));
    }
}

auto Test_MainWindow::test_bench3() -> void
{
    QBENCHMARK {
        std::vector<QString> vector;
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");

        std::vector<QString> vector2;
        std::copy(vector.begin(), vector.end(), std::back_inserter(vector2));
    }
}

auto Test_MainWindow::test_bench4() -> void
{
    QBENCHMARK {
        std::vector<QString> vector;
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");
        vector.push_back("QString");

        std::vector<QString> vector2 = vector;
    }
}
