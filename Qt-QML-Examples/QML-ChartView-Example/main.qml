import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QtCharts as QtCharts

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

    TabBar {
        id: tabBar

        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }

        TabButton {
            text: qsTr("Example graph")
        }

        TabButton {
            text: qsTr("Example piechart")
        }

        TabButton {
            text: qsTr("Example bar")
        }
    }

    StackLayout {
        id: stackLayout

        anchors {
            top: tabBar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        currentIndex: tabBar.currentIndex

        Item {
            id: page1

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
                    name: page1.currentView.firstGraphicName
                    color: "red"

                    QtCharts.VXYModelMapper {
                        model: page1.currentView.firstGraphic
                        xColumn: 0
                        yColumn: 1
                    }
                }

                QtCharts.LineSeries {
                    name: page1.currentView.secondGraphicName
                    color: "blue"

                    QtCharts.VXYModelMapper {
                        model: page1.currentView.secondGraphic
                        xColumn: 0
                        yColumn: 1
                    }
                }
            }
        }

        Item {
            id: page2

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

        Item {
            id: page3

            QtCharts.ChartView {
                id: standartBarSeries

                anchors.fill: parent

                title: "Standart Bar series"
                legend.alignment: Qt.AlignBottom
                antialiasing: true

                QtCharts.BarSeries {
                    id: mySeries

                    axisX: QtCharts.BarCategoryAxis {
                        categories: ["#1", "#2", "#3", "#4", "#5", "#6" ]
                    }

                    QtCharts.BarSet {
                        label: "First"
                        values: [1, 7, 3, 2, 8, 1]
                    }
                    QtCharts.BarSet {
                        label: "Second"
                        values: [7, 2, 5, 2, 6, 8]
                    }
                    QtCharts.BarSet {
                        label: "Third"
                        values: [3, 5, 7, 8, 1, 5]
                    }
                    QtCharts.BarSet {
                        label: "Fourth"
                        values: [2, 6, 3, 5, 9, 7]
                    }
                }
            }
        }
    }
}
