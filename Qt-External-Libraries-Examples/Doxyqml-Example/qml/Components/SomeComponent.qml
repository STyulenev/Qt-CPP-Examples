import QtQuick 2.15

/**
 * Пользовательский прямоугольник с возможностью нажатия
 */
Rectangle {
    id: root

    /**
     * Сигнал нажатия на прямоугольник
     * @param type Некоторый тестовый числовой параметр
     */
    signal clicked(var type)

    /**
     * Тестовая функция
     * @param type:string a Тестовый параметр #1
     * @param type:string b Тестовый параметр #2
     * @return type:string Сумма двух переданных строк
     */
    function someFunction(a, b) {
        return a + b;
    }

    MouseArea {
        anchors.fill: parent

        onClicked: root.clicked(1)
    }
}
