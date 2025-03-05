import QtQuick 2.15
import QtQuick.Controls 2.15

Row {
    id: buttonsGroup

    anchors.verticalCenter: parent.verticalCenter

    spacing: 5

    property var buttons

    Repeater {
        model: buttonsGroup.buttons

        delegate: Rectangle {
            id: delegate

            height: 50
            width: 50
            radius: 10

            color: "lightblue"

            Text {
                id: title

                anchors.centerIn: parent
                text: model.modelData.text ? model.modelData.text : ""
            }

            MouseArea {
                id: mouseArea

                anchors.fill: parent

                onClicked: {
                    try {
                        buttonsGroup.buttons[index].action();
                    } catch (error) {
                        console.log(error);
                    }
                }
            }
        }
    }
}
