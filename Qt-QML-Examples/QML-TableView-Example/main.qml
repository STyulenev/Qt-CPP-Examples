import QtQuick
import QtQuick.Controls 2.15
import QtQml 2.15
import QtQuick.Layouts 1.15

// Import C ++ class
import TableTable 0.1 as Models

import "qml/Widgets/" 1.0 as ASP // ????

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    //title: qsTr("Hello World")

    property bool hasHeader: true

    property QtObject currentModel: Models.TableModel{}

    ASP.TableViewData {
        /// No functionality part
        id: tableView1
        //anchors.horizontalCenter: parent.horizontalCenter
        anchors.fill: parent

        model: currentModel
    }



}
