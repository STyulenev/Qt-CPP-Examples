import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root

    clip: true

    required property var model

    Timer {
        id: timer

        interval: 3000
        running: true
        repeat: true

        onTriggered: {
            if (layout.currentIndex === layout.count - 1) {
                layout.currentIndex = 0;
            } else {
                layout.currentIndex = layout.currentIndex + 1;
            }
        }
    }

    StackLayout {
        id: layout

        anchors.fill: parent

        Repeater {
            model: root.model
            delegate: Rectangle {
                id: delegate

                radius: 5
                width: root.width
                height: root.height
                color: modelData["color"]

                Label {
                    id: title

                    anchors.centerIn: parent

                    color: "black"
                    text: modelData["text"]
                }
            }
        }
    }

    PageIndicator {
        id: indicator

        anchors {
            bottom: layout.bottom
            horizontalCenter: parent.horizontalCenter
        }

        count: layout.count
        currentIndex: layout.currentIndex
    }
}
