import QtQuick

// Import C ++ class
import ViewModels 0.1 as ViewModels

// Import QML module
import Widgets 1.0 as Widgets

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-TableView-Example"

    property QtObject cppTableViewModel: ViewModels.TableViewModel { }

    Widgets.TableViewData {
        id: tableView
        anchors.fill: parent

        hasHorizontalHeader: true
        hasHorizontalSeparator: true

        model: cppTableViewModel.tableModel

        horizontalHeaders: cppTableViewModel.horizontalHeaders
        columnWidths: cppTableViewModel.columnWidths
        textAlignments: cppTableViewModel.textAlignments
    }
}
