import QtQuick 2.0

import Sailfish.Silica 1.0 as Silica

Silica.CoverBackground {
    id: coverBackground

    objectName: "defaultCover"

    Silica.CoverTemplate {
        id: coverTemplate

        objectName: "applicationCover"
        primaryText: "App"
        secondaryText: qsTr("Template")

        icon {
            source: Qt.resolvedUrl("../icons/Aurora-Navigation-Example.svg")
            sourceSize {
                width: icon.width
                height: icon.height
            }
        }
    }
}
