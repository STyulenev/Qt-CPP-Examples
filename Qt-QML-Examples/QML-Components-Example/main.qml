import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import Common 1.0 as CommonData
import Components 1.0 as ComponentsLibrary

import CustomVisualType 1.0 as CustomVisualType
import CustomNonVisualType 1.0 as CustomNonVisualType

ApplicationWindow {
    id: mainWindow

    visible: true
    width: CommonData.Consts.screenWidth
    height: CommonData.Consts.screenHeight
    title: qsTr("QML-Components-Example")

    // ComponentsLibrary.LabelAndTextField example
    /*ComponentsLibrary.LabelAndTextField {
        anchors.centerIn: parent
        labelText: "some text"

        labelPosition: Qt.AlignRight
        textFieldText: "text"

        width: 150
        height: 40
    }*/

    // ComponentsLibrary.LabelAndComboBox example
    /*ComponentsLibrary.LabelAndComboBox {
        anchors.centerIn: parent
        labelPosition: Qt.AlignLeft
        labelText: "some text"

        comboBoxModel: [ "1", "2", "3" ]
    }*/

    // CustomNonVisualType.DateTime example
    /*property QtObject dateTime: CustomNonVisualType.DateTime { }

    Label {
        anchors.centerIn: parent
        color: "black"
        text: ("%1 %2").arg(dateTime.date).arg(dateTime.time)
        z: 1
    }*/

    // CustomVisualType.Circle example + Enums example
    property int circleColor: CommonData.Enums.Colors.GREY

    CustomVisualType.Circle {
        id: circle

        anchors.centerIn: parent

        width: 200
        height: 200

        color: switch (mainWindow.circleColor) {
               case CommonData.Enums.Colors.GREY: return "grey";
               case CommonData.Enums.Colors.GREEN: return "green";
               case CommonData.Enums.Colors.YELLOW: return "yellow";
               default: return "transparent";
               }

        onColorChanged: {
            console.log("circle color = " + circle.color)
        }
    }
}
