import QtQuick 2.0

import Sailfish.Silica 1.0 as Silica

Silica.Page {
    id: firstPage

    objectName: "firstPage"
    allowedOrientations: Silica.Orientation.All

    Silica.PageHeader {
        id: header

        objectName: "pageHeader"
        title: qsTr("First page")

        extraContent.children: [
            // ...
        ]
    }

    Silica.Button {
        id: backButton

        anchors.centerIn: parent

        height: 150
        width: 400

        text: qsTr("Back")

        onClicked: {
            pageStack.pop();
        }
    }
}
