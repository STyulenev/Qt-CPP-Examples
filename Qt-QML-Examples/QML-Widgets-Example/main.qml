import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import Common 1.0 as CommonData
import Widgets 1.0 as WidgetsLibrary

ApplicationWindow {
    id: mainWindow
    visible: true
    width: CommonData.Consts.screenWidth
    height: CommonData.Consts.screenHeight
    title: qsTr("QML-Widgets-Example")

    WidgetsLibrary.LabelAndTextField {
        anchors.centerIn: parent
        labelText: "some text"

        labelPosition: Qt.AlignRight
        textFieldText: "text"

        width: 150
        height: 40
    }
}
