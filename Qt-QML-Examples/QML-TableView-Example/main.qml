import QtQuick

// Import C ++ class
import TableModels 0.1 as Models

import "qml/Widgets/" 1.0 as Widgets

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true

    property QtObject currentModel: Models.TableModel{}

    Widgets.TableViewData {
        id: tableView
        anchors.fill: parent

        hasHorizontalHeader: true
        hasHorizontalSeparator: true

        model: currentModel
    }
}
