import QtQuick
import QtQuick.Controls 2.15

// Import C ++ class
import ListModels 0.1 as CPPModels

// Import QML module
import Components 1.0 as Components
import Models 1.0 as QMLModels

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-ListView-Example"

    property QtObject cppListModel: CPPModels.ListModel { }
    property QtObject qmlListModel: QMLModels.QMLListModel { }
    property QtObject xmlListModel: QMLModels.QMLXmlListModel { }
    property QtObject jsonListModel: QMLModels.QMLJSONListModel { }
    property QtObject objectModel: QMLModels.QMLObjectModel { }

    Components.ListViewData {
        id: listView

        anchors {
            fill: parent
            topMargin: 20
            bottomMargin: 20
            rightMargin: 10
            leftMargin: 10
        }

        model: cppListModel // or jsonModel.model or qmlListModel or xmlModel
    }

    /*ListView {
        id: listView

        anchors {
            fill: parent
            topMargin: 20
            bottomMargin: 20
            rightMargin: 10
            leftMargin: 10
        }

        model: objectModel
    }*/
}
