import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import Common 1.0 as CommonData
import Widgets 1.0 as WidgetsLibrary

import CustomVisualType 1.0 as CustomVisualType
import CustomNonVisualType 1.0 as CustomNonVisualType

ApplicationWindow {
    id: mainWindow

    visible: true
    width: CommonData.Consts.screenWidth
    height: CommonData.Consts.screenHeight
    title: qsTr("QML-Components-Example")

    // WidgetsLibrary.LabelAndTextField example
    /*WidgetsLibrary.LabelAndTextField {
        anchors.centerIn: parent
        labelText: "some text"

        labelPosition: Qt.AlignRight
        textFieldText: "text"

        width: 150
        height: 40
    }*/

    // WidgetsLibrary.LabelAndComboBox example
    /*WidgetsLibrary.LabelAndComboBox {
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

    // CustomVisualType.Circle example
    CustomVisualType.Circle {
        id: circle

        anchors.centerIn: parent

        width: 200
        height: 200

        color: "green"
    }
}
