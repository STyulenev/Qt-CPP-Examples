import Felgo
import QtQuick

App {
    id: app

    // QML ListModel
    ListModel {
        id: qmlListModel
        ListElement {
            name: "Banana"
            group: "fruit"
            color: "yellow"
        }
        ListElement {
            name: "Apple"
            group: "fruit"
            color: "green"
        }
        ListElement {
            name: "Potato"
            group: "vegetable"
            color: "red"
        }
    }

    property var jsListModel: [
        {
            name: "Banana",
            group: "fruit",
            color: "yellow"
        },
        {
            name: "Apple",
            group: "fruit",
            color: "green"
        },
        {
            name: "Potato",
            group: "vegetable",
            color: "red"
        }
    ]

    AppListView {
        id: appListView

        model: qmlListModel // jsListModel
        emptyText.text: "No items available"

        delegate: Rectangle {
            width: parent.width
            height: 50
            color: model.color // model.color for qmlListView, modelData["color"] for jsListModel

            AppText {
                anchors.centerIn: parent
                text: model.name // model.name for qmlListView, modelData["name"] for jsListModel
            }
        }
    }
}

