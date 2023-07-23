import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: radioButtonGroup

    property alias model: maker.model

    ButtonGroup {
        id: group
        exclusive: true
    }

    Grid {
        id: container
        columns: 2
        rows: 2

        anchors.fill: parent
        spacing: 5

        Repeater {
            id: maker

            delegate: Item {
                id: item
                width: 150
                height: 40

                RadioButton {
                    text: model.text
                    checked: model.checked
                    enabled: model.enabled
                    anchors.centerIn: parent

                    ButtonGroup.group: group

                    Connections {
                        function onReleased() {
                            model.EditRole = group.buttons[index].checked;
                        }
                    }
                }
            }
        }
    }
}
