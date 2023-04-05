import QtQuick

// Import C ++ class
import TableModels 0.1 as Models

// Import QML module
import Widgets 1.0 as Widgets

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-TableView-Delegates-Example"

    property QtObject currentModel: Models.TableModel{}

    Widgets.TableViewData {
        id: tableView
        model: currentModel
        anchors.fill: parent

        hasHorizontalHeader: true
        hasVerticalHeader: true
    }
}
