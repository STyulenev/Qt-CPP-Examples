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
    property int btnType: 0x01  // button combination type
    property int retValue: 0x01 // The button type that clicks after the dialog box

    modality: Qt.ApplicationModal
    flags: Qt.FramelessWindowHint | Qt.Window

    width: 313
    height: 150
    color: "transparent"

    Component.onCompleted: {
        console.log("create window");
    }

    Component.onDestruction: {
        console.log("delete window");
    }

    Rectangle {
        anchors {
            fill: parent
            margins: 4
        }
        color: "#23518b"
        radius: 5

        Item {
            id: id_item_header
            anchors {
                left: parent.left
                top: parent.top
                right: parent.right
            }
            height: 40

            Text {
                id: id_img_icon
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: parent.left
                    leftMargin: 10
                }
                text: qsTr("hint")
                color: "white"
            }

            Button {
                id: img
                text: "x"
                anchors {
                    right: parent.right
                    rightMargin: 5
                    verticalCenter: parent.verticalCenter
                }
                width: 30
                height: 30
                onClicked: checkd(mb_CANCEL)
            }

            MouseArea {
                id: dragMouseArea
                property point clickPos
                property bool isPressed: false

                anchors {
                    left: parent.left
                    top: parent.top
                    bottom: parent.bottom
                    right: img.left
                }

                Connections {
                    target: dragMouseArea

                    function onPressed(mouse) {
                        dragMouseArea.isPressed = true
                        dragMouseArea.clickPos = Qt.point(mouse.x, mouse.y)
                    }

                    function onReleased() {
                        dragMouseArea.isPressed = false
                    }

                    function onPositionChanged(mouse) {
                        var delta = Qt.point(mouse.x - dragMouseArea.clickPos.x, mouse.y - dragMouseArea.clickPos.y)
                        var tmpX = root.x + delta.x
                        var tmpY = root.y + delta.y
                        if (tmpX + root.width > 25 && Screen.desktopAvailableWidth - tmpX > 25)
                            root.x = tmpX
                        if (tmpY + root.height > 25 && Screen.desktopAvailableHeight - tmpY > 25)
                            root.y = tmpY
                    }
                }
            }
        }

        Rectangle {
            id: id_item_body

            anchors {
                left: parent.left
                top: id_item_header.bottom
                right: parent.right
                bottom: parent.bottom
            }

            Keys.onPressed: root.close()
            color: "#3568a7"
            radius: parent.radius

            Item {
                id: id_rect_msg

                anchors {
                    fill: parent
                    bottomMargin: 55
                }

                Text {
                    anchors {
                        fill: parent
                        leftMargin: 30
                        rightMargin: 30
                    }

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WordWrap
                    color: "white"
                    text: qsTr(title)
                }
            }

            RowLayout {
                id: buttonsLayout

                anchors {
                    left: parent.left
                    right: parent.right
                    top: id_rect_msg.bottom
                    bottom: parent.bottom
                }
            }
        }
    }

    onBtnTypeChanged: {
        create(root.btnType)
    }

    Component {
        id: id_btn_comp

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
        var obj = id_btn_comp.createObject(buttonsLayout, {
                                               "Layout.alignment" : Qt.AlignHCenter,
                                               "Layout.preferredWidth" : 60,
                                               "Layout.preferredHeight" : 30,
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
            add_one(root.mb_CANCEL,"cancel");
        }
    }
}
