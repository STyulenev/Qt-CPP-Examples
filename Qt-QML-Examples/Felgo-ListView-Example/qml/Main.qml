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

    AppListView {

        model: qmlListModel
        delegate: Rectangle {
            width: parent.width
            height: 50
            color: model.color

            AppText {
                anchors.centerIn: parent
                text: model.name
            }
        }
    }
}

