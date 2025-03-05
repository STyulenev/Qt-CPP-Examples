import QtQuick 2.15
import QtQuick.Templates 2.15 as Template

Template.Container {
    id: control

    z: 10

    implicitHeight: listView.implicitHeight + control.topPadding + control.bottomPadding
    implicitWidth: listView.implicitWidth

    opacity: 1

    topPadding: 4
    bottomPadding: 4

    function open(x, y) {
        control.y = y /* + ... */;
        control.x = x /* + ... */;
    }

    function close() {
        control.destroy();
    }

    contentItem: ListView {
        id: listView

        Component.onCompleted: {
            for (var i = 0; i < control.count; ++i) {
                var item = control.itemAt(i);
                item.clicked.connect(function() {
                    control.close();
                });
            }
        }

        implicitHeight: contentHeight + control.topPadding + control.bottomPadding
        implicitWidth: {
            var maxWidth = 0;

            for (var i = 0; i < control.count; ++i) {
                maxWidth = (maxWidth < control.itemAt(i).width) ? control.itemAt(i).width : maxWidth;
            }

            return maxWidth;
        }

        model: control.contentModel

        spacing: 5

        interactive: height < contentHeight
        clip: true
        keyNavigationWraps: false
        currentIndex: -1
    }

    background: Rectangle {
        id: rect

        color: "lightgrey"
        radius: 5

        Item {
            id: overlayItem

            z: control.z -1
            anchors.fill: parent

            parent: control.parent
            visible: control.visible

            Rectangle {
                id: overlay

                anchors.fill: parent

                opacity: 0.5
                color: "black"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    control.close();
                }
            }
        }
    }
}
