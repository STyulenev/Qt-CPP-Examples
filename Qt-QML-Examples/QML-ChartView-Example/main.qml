import QtQuick 2.15
import QtQml 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.15
import QtCharts 2.15 as QtCharts
// Import C++ class
import ViewModels 0.1 as ViewModels

// Import QML module
import Components 1.0 as Components

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

            QtCharts.ChartView {
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

                QtCharts.LineSeries {
                    name: currentView.firstGraphicName
                    color: "red"

                    QtCharts.VXYModelMapper {
                        model: currentView.firstGraphic
                        xColumn: 0
                        yColumn: 1
                    }
                }

                QtCharts.LineSeries {
                    name: currentView.secondGraphicName
                    color: "blue"

                    QtCharts.VXYModelMapper {
                        model: currentView.secondGraphic
                        xColumn: 0
                        yColumn: 1
                    }
                }
            }
        }
        Tab {
            title: "Example piechart"

            RowLayout {
                anchors.fill: parent

                QtCharts.ChartView {
                    id: standartPieChartView

                    title: "Standart PieChartView"

                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    legend.alignment: Qt.AlignBottom
                    antialiasing: true

                    property var othersSlice

                    QtCharts.PieSeries {
                        id: pieSeries

                        QtCharts.PieSlice {
                            label: "Element 1"
                            value: 22.0
                        }
                        QtCharts.PieSlice {
                            label: "Element 2"
                            value: 15.0
                        }
                        QtCharts.PieSlice {
                            label: "Element 3"
                            value: 9.0
                        }
                    }

                    Component.onCompleted: {
                        othersSlice = pieSeries.append("Element 4", 52.0);
                        pieSeries.find("Element 3").exploded = true;
                    }
                }

                Components.CustomPieChart {
                    id: customPieChartView

                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    model: [
                            {
                                value: 0.2,
                                color: "lightgreen"
                            },
                            {
                                value: 0.3,
                                color: "lightgrey"
                            },
                            {
                                value: 0.4,
                                color: "lightblue"
                            },
                            {
                                value: 0.1,
                                color: "orange"
                            }
                        ]
                }
            }
        }
    }
}
