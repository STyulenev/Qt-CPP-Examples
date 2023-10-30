import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

SomeScreen_Form {
    id: formSomeScreen

    QtObject {
        id: internal

        property bool isOpened: false
        readonly property int heightElement: 40
    }

    onMenuButtonClicked: {
        if (internal.isOpened) {
            drawer.close();
        } else {
            drawer.open();
        }
    }

    Drawer {
        id: drawer
        dragMargin: 60
        y: headerSize
        width: 0.4 * parent.width
        height: parent.height - headerSize
        clip: true

        ColumnLayout {
            anchors {
                fill: parent
                margins: 5
            }

            Label {
                text: qsTr("Title")

                height: internal.heightElement
                Layout.fillWidth: true

                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Button {
                text: qsTr("Exit")
                height: internal.heightElement
                Layout.fillWidth: true

                onClicked: {
                    Qt.callLater(Qt.quit);
                }
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }

        onOpened: {
            internal.isOpened = true;
        }

        onClosed: {
            internal.isOpened = false;
        }
    }
}
