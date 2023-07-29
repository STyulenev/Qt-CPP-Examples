import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

// Import C ++ class
import Views 0.1 as Views

// Import QML module
import Widgets 1.0 as Widgets

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-RadioButtonGroup-Example"

    property QtObject viewModel: Views.RadioButtonGroupsView {}

    Widgets.RadioButtonGroup {
        id: radioButtonGroup

        anchors.fill: parent
        model: appWindow.viewModel.radioButtonGroupModel
        columns: 1
        rows: 3
    }
}
