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

    // Felgo JsonListModel
    JsonListModel {
        id: jsonListModel
        source: jsListModel
        fields: ["name", "group", "color"]
    }

    AppListView {
        id: appListView

        model: jsonListModel // sortFilterProxyModel or qmlListModel or jsListModel
        emptyText.text: "No items available"

        delegate: Rectangle {
            width: parent.width
            height: 50

            // model.color for qmlListView / sortFilterProxyModel / JsonListModel
            // modelData["color"] for jsListModel
            color: model.color

            AppText {
                anchors.centerIn: parent
                // model.name for qmlListView / sortFilterProxyModel / JsonListModel
                // modelData["name"] for jsListModel
                text: model.name
            }
        }
    }
}

