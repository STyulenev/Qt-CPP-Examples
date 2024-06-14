import QtQuick 2.15
import QtQml 2.15
import QtQuick.Controls 1.4
import QtCharts 2.15
import QtQuick.Layouts 1.15

// Import C ++ class
import ViewModels 0.1 as ViewModels

ApplicationWindow {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-ChartView-Example"

    TabView {
        anchors.fill: parent

        Tab {
            title: "Example graph"

            property QtObject currentView: ViewModels.LinearGraphicsView { }

            ChartView {
                id: standartGraphicChartView

                anchors.centerIn: parent

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
        Tab {
            title: "Example piechart"

            ChartView {
                id: standartPieChartView

                title: "Standart PieChartView"
                anchors.fill: parent
                legend.alignment: Qt.AlignBottom
                antialiasing: true

                property var othersSlice

                PieSeries {
                    id: pieSeries

                    PieSlice {
                        label: "Element 1"
                        value: 22.0
                    }
                    PieSlice {
                        label: "Element 2"
                        value: 15.0
                    }
                    PieSlice {
                        label: "Element 3"
                        value: 9.0
                    }
                }

                Component.onCompleted: {
                    othersSlice = pieSeries.append("Element 4", 52.0);
                    pieSeries.find("Element 3").exploded = true;
                }
            }
        }
    }
}
