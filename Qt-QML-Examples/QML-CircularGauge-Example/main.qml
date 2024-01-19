import QtQml 2.4
import QtQuick 2.4
import QtQuick.Window 2.4
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import QtQuick.Extras 1.4 as Extras
import Components 1.0 as Components

ApplicationWindow {
    visible: true
    width: 800
    height: 500
    title: qsTr("QML-CircularGauge-Example")

    RowLayout {
        id: body

        anchors {
            top: parent.top
            right: parent.right
            left: parent.left
            bottom: slider.top
            margins: 20
        }

        Extras.CircularGauge {
            id: standartGaude

            Layout.alignment: Qt.AlignCenter

            height: 200
            width: 200

            maximumValue: 100
            value: 0
        }

        Components.CircularGauge {
            id: customGaude

            Layout.alignment: Qt.AlignCenter

            size: 300
            maximumValue: 100
            value: 0
        }
    }

    Slider {
        id: slider

        anchors {
            bottom: parent.bottom
            right: parent.right
            left: parent.left

            margins: 20
        }

        height: 50

        from: 0
        to: 100
        value: 0

        onValueChanged: {
            standartGaude.value = value;
            customGaude.value = value;
        }
    }
}
