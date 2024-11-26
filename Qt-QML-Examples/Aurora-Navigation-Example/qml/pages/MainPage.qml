import QtQuick 2.0

import Sailfish.Silica 1.0 as Silica

Silica.Page  {
    id: mainPage

    objectName: "mainPage"
    allowedOrientations: Silica.Orientation.All

    Silica.PageHeader {
        id: header

        objectName: "pageHeader"
        title: qsTr("Main page")

        extraContent.children: [
            // ...
        ]
    }

    Row {
        id: layout

        anchors.centerIn: parent

        spacing: 20

        Silica.Button {
            id: toFirstPageButton

            height: 150
            width: 400

            text: qsTr("To the first page")

            onClicked: {
                pageStack.push(firstPage);
            }
        }

        Silica.Button {
            id: toSecondPageButton

            height: 150
            width: 400

            text: qsTr("To the second page")

            onClicked: {
                pageStack.push(secondPage);
            }
        }
    }

    property Component firstPage:  FirstPage {}
    property Component secondPage: SecondPage {}
}
