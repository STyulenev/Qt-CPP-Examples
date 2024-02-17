import QtQml 2.4
import QtQuick 2.4
import QtQuick.Window 2.4
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import QtQuick.Extras 1.4 as Extras // Only Qt 5.5 - 5.15
import Components 1.0 as Components
import CppComponents 1.0 as CppComponents

ApplicationWindow {
    id: application

    visible: true
    width: 900
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
            id: customQmlGaude

            Layout.alignment: Qt.AlignCenter

            size: 300
            maximumValue: 100
            value: 0
        }

        CppComponents.CircularGauge {
            id: customCppGaude

            Layout.alignment: Qt.AlignCenter

            width: 300
            height: 300

            font {
                bold: true
                family: "Arial"
                pixelSize: 12
            }

            min: 0
            max: 100
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
            standartGaude.value  = value;
            customQmlGaude.value = value;
            customCppGaude.value = value;
        }
    }
}
