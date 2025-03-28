import QtQuick 2.15

import Components 1.0 as Components

Item {
    id: page

    QtObject {
        id: internal

        property Component component1: null
        property Component component2: Rectangle {
            color: "lightblue"
        }
        property Component component3: Rectangle {
            color: "lightpink"
        }
        property Component component4: null
    }

    Row {
        id: body

        anchors.centerIn: parent

        spacing: 10

        Loader {
            id: component1Loader

            width: 100
            height: 100

            sourceComponent: internal.component1
        }

        Loader {
            id: component2Loader

            width: 100
            height: 100

            sourceComponent: internal.component2
        }

        Loader {
            id: component3Loader

            width: 100
            height: 100

            sourceComponent: internal.component3
        }

        Loader {
            id: component4Loader

            width: 100
            height: 100

            sourceComponent: internal.component4
        }
    }
}
