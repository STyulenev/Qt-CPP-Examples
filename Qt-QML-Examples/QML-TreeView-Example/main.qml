import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

// Import C ++ class
import ViewModel 0.1 as Models

// Import QML module
import Widgets 1.0 as Widgets

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-TreeView-Example"

    property QtObject currentModel: Models.TreeViewModel {}

    Widgets.TreeViewWidget {
        id: treeView

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
