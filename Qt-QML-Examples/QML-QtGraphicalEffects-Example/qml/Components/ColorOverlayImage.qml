import QtQuick 2.15
import QtQuick.Controls 2.15

import Qt5Compat.GraphicalEffects // - for Qt 6
//import QtGraphicalEffects 1.15  // - for Qt 5

Image {
    id: root

    property alias overlayColor: overlay.color

    ColorOverlay {
        id: overlay

        anchors.fill: parent

        source: root
    }
}
