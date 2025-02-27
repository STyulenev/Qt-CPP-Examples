import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import Common 1.0 as CommonData
import Components 1.0 as ComponentsLibrary

import CustomVisualType 1.0 as CustomVisualType
import CustomNonVisualType 1.0 as CustomNonVisualType

import Controllers 1.0 as Controllers

import CPPEnums 1.0 as CPPEnums

import ui.components 1.0 as UI

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
    //property int circleColor: CommonData.Enums.Colors.GREY // QML/js Enum
    /*property int circleColor: CPPEnums.ColorEnum.GREY // C++ Enum

    CustomVisualType.Circle {
        id: circle

        anchors.centerIn: parent

        width: 200
        height: 200

        //color: switch (mainWindow.circleColor) {
        //       case CommonData.Enums.Colors.GREY: return "grey";
        //       case CommonData.Enums.Colors.GREEN: return "green";
        //       case CommonData.Enums.Colors.YELLOW: return "yellow";
        //       default: return "transparent";
        //       }

        color: switch (mainWindow.circleColor) {
                       case CPPEnums.ColorEnum.GREY: return "grey";
                       case CPPEnums.ColorEnum.GREEN: return "green";
                       case CPPEnums.ColorEnum.YELLOW: return "yellow";
                       default: return "transparent";
                       }

        onColorChanged: {
            console.log("circle color = " + circle.color)
        }
    }*/

    // ComponentsLibrary.SimpleProgressBar example
    /*ComponentsLibrary.SimpleProgressBar {
        id: simpleProgressBar

        anchors.centerIn: parent
        width: 400
        height: 40

        value: 50

        onValueChanged: {
            console.log("value = " + simpleProgressBar.value)
        }
    }*/

    /*Button {
        id: button

        anchors.centerIn: parent

        width: 200
        height: 80

        text: "AssyncButton"

        property QtObject assync: Controllers.AssyncController { }

        onClicked: {
            button.assync
            .run(function() {
                console.log("first assync functions ...")
            })
            .run(function() {
                console.log("second assync functions ...")
            });
        }
    }*/

    UI.SomeComponent {
        id: someComponent

        anchors.centerIn: parent

        width: 200
        height: 200

        colorType: UI.ColorTypes.Pink
    }
}
