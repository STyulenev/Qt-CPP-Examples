import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    id: root

    signal closeWindow()

    width: 500
    height: 250

    property alias content: bodyItem.children

    Rectangle {
        id: bodyItem

        anchors.fill: parent

        color: "transparent"
    }
}
