import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

// Import C ++ class
import ViewModels 1.0 as ViewModels

// Import QML module
import Widgets 1.0 as Widgets

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-RadioButtonGroup-Example"

    property QtObject viewModel: ViewModels.RadioButtonGroupsViewModel { }

    Widgets.RadioButtonGroup {
        id: radioButtonGroup

        anchors.fill: parent
        model: appWindow.viewModel.radioButtonGroupModel
        columns: 1
        rows: 3
    }
}
