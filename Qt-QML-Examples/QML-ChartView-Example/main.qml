import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtCharts 2.15
import QtQuick.Layouts 1.15

// Import C ++ class
import Views 0.1 as Views

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-ChartView-Example"

    property QtObject currentModel: Views.LinearGraphicsView {}

    ChartView {
        antialiasing: true
        legend.visible: true
        anchors {
            fill: parent
            topMargin: 20
            bottomMargin: 20
            rightMargin: 10
            leftMargin: 10
        }

        LineSeries {
            name: "Chart 1"
            color: "red"

            VXYModelMapper {
                model: currentModel.firstGraphic
                xColumn: 0
                yColumn: 1
            }
        }

        LineSeries {
            name: "Chart 2"
            color: "blue"

            VXYModelMapper {
                model: currentModel.secondGraphic
                xColumn: 0
                yColumn: 1
            }
        }
    }
}
