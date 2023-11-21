import QtQml
import QtQuick

// Import C ++ class
import ViewModels 0.1 as ViewModels

// Import QML module
import Widgets 1.0 as Widgets

import Qt.labs.qmlmodels

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-TableView-Example"

    property QtObject cppTableViewModel: ViewModels.TableViewModel { }

    QtObject  {
        id: qmlTableModelData

        property var horizontalHeaders: [ qsTr("id"), qsTr("name"), qsTr("number"), qsTr("status") ]
        property var textAlignments: [ Qt.AlignCenter, Qt.AlignCenter, Qt.AlignCenter, Qt.AlignCenter ]
        property var columnWidths: [ 0.1, 0.35, 0.35, 0.2 ];
    }

    TableModel {
        id: qmlTableModel

        TableModelColumn { display: "id" }
        TableModelColumn { display: "name" }
        TableModelColumn { display: "number" }
        TableModelColumn { display: "status" }

        rows: [
            {
                id: 1,
                name: "John",
                number: "12345",
                status: "yes",
            },
            {
                id: 2,
                name: "Masha",
                number: "12346",
                status: "no",
            },
            {
                id: 3,
                name: "Ben",
                number: "12347",
                status: "yes",
            },
            {
                id: 4,
                name: "Alla",
                number: "12348",
                status: "no",
            }
        ]
    }

    Widgets.TableViewData {
        id: tableView
        anchors.fill: parent

        hasHorizontalHeader: true
        hasHorizontalSeparator: true

        // cpp model

        /*model: cppTableViewModel.tableModel
        horizontalHeaders: cppTableViewModel.horizontalHeaders
        columnWidths: cppTableViewModel.columnWidths
        textAlignments: cppTableViewModel.textAlignments*/

        // or qml model

        model: qmlTableModel
        horizontalHeaders: qmlTableModelData.horizontalHeaders
        columnWidths: qmlTableModelData.columnWidths
        textAlignments: qmlTableModelData.textAlignments
    }
}
