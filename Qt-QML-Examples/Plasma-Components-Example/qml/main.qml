import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Layouts 1.2

import org.kde.plasma.components 3.0 as PlasmaComponents3

Window
{
    id: app

    visible: true
    width: 500
    height: 400
    title: i18n("Plasma-Components-Example")

    ColumnLayout {
        anchors.fill: parent

        PlasmaComponents3.Label {
            id: label

            Layout.fillWidth: true
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignTop

            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            text: i18n("PlasmaComponents3.Label")
            color: "black"
        }

        PlasmaComponents3.ComboBox {
            id: comboBox

            Layout.preferredWidth: 250
            Layout.preferredHeight: 50

            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

            textRole: "text"
            valueRole: "value"
            model: [
                { value: "a", text: i18n("PlasmaComponents3.ComboBox A") },
                { value: "b", text: i18n("PlasmaComponents3.ComboBox B") },
                { value: "c", text: i18n("PlasmaComponents3.ComboBox C") },
            ]
        }

        PlasmaComponents3.Button {
            id: button

            Layout.preferredWidth: 250
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter | Qt.AlignTop

            text: i18n("PlasmaComponents3.Button")
        }

        PlasmaComponents3.CheckBox {
            id: checkBox

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter | Qt.AlignTop

            text: i18n("PlasmaComponents3.CheckBox") // text color is white
            checked: true
        }

        PlasmaComponents3.Slider {
            id: slider

            Layout.fillWidth: true

            from: 0
            to: 100
            value: 50
            stepSize: 5
        }

        PlasmaComponents3.SpinBox {
            id: spinBox

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter | Qt.AlignTop

            from: 0
            to: 100
            value: 25
            stepSize: 1
        }

        PlasmaComponents3.TextArea {
            id: textArea

            Layout.preferredWidth: 250
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            text: "PlasmaComponents3\nTextArea"
        }

        PlasmaComponents3.TextField {
            id: textField

            Layout.preferredWidth: 250
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            placeholderText: i18n("PlasmaComponents3.TextField...")
        }

        RowLayout {
            id: radioButtons

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            PlasmaComponents3.RadioButton {
                text: i18n("One")
                checked: true
                autoExclusive: true
            }

            PlasmaComponents3.RadioButton {
                text: i18n("Two")
                autoExclusive: true
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
