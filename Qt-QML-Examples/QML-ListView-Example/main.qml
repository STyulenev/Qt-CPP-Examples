import QtQuick
import QtQuick.Controls 2.15
import QtQml 2.15
import QtQuick.Layouts 1.15

// Import C ++ class
import ListModels 0.1 as Models

import "qml/Widgets/" 1.0 as Widgets

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-ListView-Example"

    property QtObject currentModel: Models.ListModel{}

    Widgets.ListViewData {
        id: listView

        anchors {
            fill: parent
            topMargin: 20
            bottomMargin: 20
            rightMargin: 10
            leftMargin: 10
        }

        model: currentModel
    }
}
