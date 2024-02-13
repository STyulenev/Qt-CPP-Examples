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

    // Felgo SortFilterProxyModel
    SortFilterProxyModel {
        id: sortFilterProxyModel
        sourceModel: qmlListModel

        // configure sorters
        sorters: [
            LocaleAwareSorter {
                id: nameSorter
                roleName: "name"
            }
        ]

        filters: [
            ValueFilter {
                roleName: "group"
                value: "fruit"
            }
        ]
    }

    // JavaScript json array
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

        model: sortFilterProxyModel // or qmlListModel or jsListModel
        emptyText.text: "No items available"

        delegate: Rectangle {
            width: parent.width
            height: 50
            color: model.color // model.color for qmlListView or sortFilterProxyModel, modelData["color"] for jsListModel

            AppText {
                anchors.centerIn: parent
                text: model.name // model.name for qmlListView or sortFilterProxyModel, modelData["name"] for jsListModel
            }
        }
    }
}

