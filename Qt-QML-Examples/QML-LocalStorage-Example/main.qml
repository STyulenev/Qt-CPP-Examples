import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import QtCore as Core
import QtQuick.LocalStorage 2.0 as Sql // for DataBase.js

import Logics 1.0 as Logics

Window {
    id: window

    width: 900
    height: 600
    visible: true

    title: qsTr("QML-LocaleStorage-Example")

    Core.Settings {
        property alias x: window.x
        property alias y: window.y
        property alias width: window.width
        property alias height: window.height
    }

    Text {
        text: "?"
        anchors.horizontalCenter: parent.horizontalCenter

        Component.onCompleted: {
            Logics.DataBase.selectAll();
        }
    }
}
