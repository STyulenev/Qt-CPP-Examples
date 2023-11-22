import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtCharts 2.15
import QtQuick.Layouts 1.15

// Import C ++ class
import ViewModels 0.1 as ViewModels

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-ChartView-Example"

    property QtObject currentView: ViewModels.LinearGraphicsView {}

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
            name: currentView.firstGraphicName
            color: "red"

            VXYModelMapper {
                model: currentView.firstGraphic
                xColumn: 0
                yColumn: 1
            }
        }

        LineSeries {
            name: currentView.secondGraphicName
            color: "blue"

            VXYModelMapper {
                model: currentView.secondGraphic
                xColumn: 0
                yColumn: 1
            }
        }
    }
}
