import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

Window {
    id: root

    property int mb_YES   : 0x01 << 1
    property int mb_NO    : 0x01 << 2
    property int mb_CANCEL: 0x01 << 3

    property string title: ""
    property string description: ""
    property int btnType: 0x01
    property int retValue: 0x01

    modality: Qt.ApplicationModal
    flags: Qt.FramelessWindowHint | Qt.Window

    width: 350
    height: 180
    color: "transparent"

    Component.onCompleted: {
        console.log("create window");
    }

    Component.onDestruction: {
        console.log("delete window");
    }

    Rectangle {
        id: body

        anchors {
            fill: parent
            margins: 4
        }

        color: "#23518b"
        radius: 5

        Item {
            id: headerItem

            anchors {
                left: parent.left
                top: parent.top
                right: parent.right
            }

            height: 40

            Text {
                id: text

                anchors {
                    verticalCenter: parent.verticalCenter
                    left: parent.left
                    leftMargin: 10
                }

                text: root.title
                color: "white"
            }

            Button {
                id: closeButton
                z: 2

                anchors {
                    right: parent.right
                    rightMargin: 5
                    verticalCenter: parent.verticalCenter
                }

                width: 50
                height: 40
                text: "X"

                onClicked: {
                    root.checkd(mb_CANCEL);
                }
            }

            MouseArea {
                id: dragMouseArea

                property point clickPos
                property bool isPressed: false

                anchors {
                    left: parent.left
                    top: parent.top
                    bottom: parent.bottom
                    right: closeButton.left
                }

                Connections {
                    target: dragMouseArea

                    function onPressed(mouse) {
                        dragMouseArea.isPressed = true;
                        dragMouseArea.clickPos = Qt.point(mouse.x, mouse.y);
                    }

                    function onReleased() {
                        dragMouseArea.isPressed = false;
                    }

                    function onPositionChanged(mouse) {
                        const delta = Qt.point(mouse.x - dragMouseArea.clickPos.x, mouse.y - dragMouseArea.clickPos.y);
                        const tmpX = root.x + delta.x;
                        const tmpY = root.y + delta.y;

                        if (tmpX + root.width > 25 && Screen.desktopAvailableWidth - tmpX > 25)
                            root.x = tmpX;

                        if (tmpY + root.height > 25 && Screen.desktopAvailableHeight - tmpY > 25)
                            root.y = tmpY;
                    }
                }
            }
        }

        Rectangle {
            id: id_item_body

            anchors {
                left: parent.left
                top: headerItem.bottom
                right: parent.right
                bottom: parent.bottom
            }

            color: "#3568a7"
            radius: parent.radius

            Keys.onPressed: {
                root.close()
            }

            Item {
                id: messageItem

                anchors {
                    fill: parent
                    bottomMargin: 55
                }

                Text {
                    id: messageText

                    anchors {
                        fill: parent
                        leftMargin: 30
                        rightMargin: 30
                    }

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WordWrap
                    color: "white"
                    text: qsTr(description)
                }
            }

            RowLayout {
                id: buttonsLayout

                anchors {
                    left: parent.left
                    right: parent.right
                    top: messageItem.bottom
                    bottom: parent.bottom
                }
            }
        }
    }

    onBtnTypeChanged: {
        create(root.btnType)
    }

    Component {
        id: newButtonComponent

        Button {
            property int type: 0x01
            onClicked: checkd(type)
        }
    }

    function checkd(_type) {
        root.retValue = _type;
        root.close();
    }

    function add_one(type, text) {
        var obj = newButtonComponent.createObject(buttonsLayout, {
                                                      "Layout.alignment" : Qt.AlignHCenter,
                                                      "Layout.preferredWidth" : 100,
                                                      "Layout.preferredHeight" : 40,
                                                      "text" : text });
        obj.type = type;
    }

    function create(type) {
        if ((type & root.mb_YES) === root.mb_YES) {
            add_one(root.mb_YES, "yes");
        }

        if ((type & root.mb_NO) === root.mb_NO) {
            add_one(root.mb_NO, "no");
        }

        if ((type & root.mb_CANCEL) === root.mb_CANCEL) {
            add_one(root.mb_CANCEL, "cancel");
        }
    }
}
