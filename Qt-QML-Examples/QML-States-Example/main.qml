import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import Common 1.0 as CommonData
import Pages 1.0 as Pages

ApplicationWindow {
    id: mainWindow
    visible: true
    width: CommonData.Consts.screenWidth
    height: CommonData.Consts.screenHeight
    title: qsTr("QML-States-Example")

    Pages.MainScreen {
        id: swipeView
        anchors.fill: parent
    }
}
