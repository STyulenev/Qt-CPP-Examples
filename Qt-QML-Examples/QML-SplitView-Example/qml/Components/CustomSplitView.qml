import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root

    // singleComponentBreakPoin - значение, меньше которого, отображается только один компонент.
    // threeComponentBreakPoint - значение, больше которого, отображаются все три компонента.
    // При singleComponentBreakPoint <= root.width <= threeComponentBreakPoint отображается два компонента.
    required property int singleComponentBreakPoint
    required property int threeComponentBreakPoint

    property alias firstContent:  firstComponent.children
    property alias secondContent: secondComponent.children
    property alias thirdContent:  thirdComponent2.children

    readonly property bool firstContentVisible: firstComponent.visible

    QtObject {
        id: internal

        property int  currentElement: 0
        property bool openThirdComponent: false
        property bool drawerOpen: false

        readonly property int duration: 300
        readonly property int animationType: Easing.InOutQuad

        onOpenThirdComponentChanged: {
            console.log("-------> onOpenThirdComponentChanged " + openThirdComponent)
        }

        function stateController() {

            if (root.width <= root.singleComponentBreakPoint) {
                switch (internal.currentElement) {
                case 0:
                    root.state = internal.openThirdComponent ? "MinimalNFirstNOpenThird" : "MinimalNFirstNCloseThird";
                    return;
                case 1:
                case 2:
                    root.state = internal.openThirdComponent ? "MinimalNSecondNOpenThird" : "MinimalNSecondNCloseThird";
                    return;
                default:
                    console.log("Error RubberSplitView.stateController(). Unknown currentElement");
                    return;
                }
            } else if (root.width > root.singleComponentBreakPoint && root.width < root.threeComponentBreakPoint) {
                root.state = (internal.openThirdComponent) ? "AverageNOpenThird" : "AverageNCloseThird";
            } else {
                root.state = (internal.openThirdComponent) ? "MaximumNOpenThird" : "MaximumNCloseThird";
            }
        }
    }

    onStateChanged: {
        console.log("===> " + state)
    }

    Component.onCompleted: {
        if (root.singleComponentBreakPoint > root.threeComponentBreakPoint) {
            console.log("error creating component")
        } else {
            internal.stateController();
        }

        root.widthChanged.connect(internal.stateController);
    }

    function openFirstPanel() {
        internal.currentElement = 0;
        internal.openThirdComponent = false;

        internal.stateController();
    }

    function openSecondPanel() {
        internal.currentElement = 1;
        internal.openThirdComponent = false;

        internal.stateController();
    }

    function openThirdPanel() {
        internal.currentElement = 2;
        internal.openThirdComponent = true;

        internal.stateController();
    }

    function openThirdPanelFromFirstPanel() {
        internal.currentElement = 0;
        internal.openThirdComponent = true;

        internal.stateController();
    }

    function openThirdPanelFromSecondPanel() {
        internal.currentElement = 1;
        internal.openThirdComponent = true;

        internal.stateController();
    }

    function closeThirdPanel() {
        internal.openThirdComponent = false;
        internal.currentElement = 1;

        internal.stateController();
    }

    SplitView {
        id: splitView

        anchors.fill: parent

        orientation: Qt.Horizontal

        Rectangle {
            id: firstComponent

            color: "lightblue"
            clip: true
        }

        Rectangle {
            id: secondComponent

            SplitView.fillWidth: true

            clip: true
            color: "lightgray"
        }

        Rectangle {
            id: thirdComponent

            clip: true
            color: "lightgreen"

            Rectangle {
                id: thirdComponent2

                anchors.fill: parent
                color: "lightgreen"
            }
        }
    }

    Drawer {
        id: drawer

        width: 360
        height: parent.height

        edge: Qt.RightEdge

        closePolicy: Popup.CloseOnPressOutside

        enter: Transition {
            //NumberAnimation { property: "opacity"; from: 1.0; to: 0.0 }
        }

        exit: Transition {
            //NumberAnimation { property: "opacity"; from: 1.0; to: 0.0 }
        }

        onOpened: {
            internal.drawerOpen = true;
        }

        onAboutToShow: {

        }

        onAboutToHide: {

        }

        onClosed: {
            internal.drawerOpen = false;

            if (state === "AverageNOpenThird" || state === "MinimalNFirstNOpenThird" || state === "MinimalNSecondNOpenThird") {
                internal.openThirdComponent = false;
                internal.stateController();
            }
        }

        Rectangle {
            id: fourthComponent

            anchors.fill: parent

            clip: true
            color: "lightpink"

        }
    }

    states: [
        // Минимальная ширина окна

        // Случай, когда размер окна минимальный, отображается первый компонент, drawer открыт
        State {
            name: "MinimalNFirstNOpenThird"

            PropertyChanges {
                target: firstComponent

                SplitView.preferredWidth: root.width
                visible: true
            }

            PropertyChanges {
                target: secondComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            PropertyChanges {
                target: thirdComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            ParentChange {
                target: thirdComponent2
                parent: fourthComponent
            }

            StateChangeScript {

                script: {
                    drawer.open();
                }
            }
        },

        // Случай, когда размер окна минимальный, отображается первый компонент, drawer скрыт
        State {
            name: "MinimalNFirstNCloseThird"

            PropertyChanges {
                target: firstComponent

                SplitView.preferredWidth: root.width
                visible: true
            }

            PropertyChanges {
                target: secondComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            PropertyChanges {
                target: thirdComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            ParentChange {
                target: thirdComponent2
                parent: thirdComponent
            }

            StateChangeScript {

                script: {
                    drawer.close();
                    // internal.drawerOpen = false;
                }
            }
        },

        // Случай, когда размер окна минимальный, отображается второй компонент, drawer открыт
        State {
            name: "MinimalNSecondNOpenThird"

            PropertyChanges {
                target: firstComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            PropertyChanges {
                target: secondComponent

                SplitView.preferredWidth: root.width
                visible: true
            }

            PropertyChanges {
                target: thirdComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            ParentChange {
                target: thirdComponent2
                parent: fourthComponent
            }

            StateChangeScript {

                script: {
                    drawer.open();
                }
            }
        },

        // Случай, когда размер окна минимальный, отображается второй компонент, drawer скрыт
        State {
            name: "MinimalNSecondNCloseThird"

            PropertyChanges {
                target: firstComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            PropertyChanges {
                target: secondComponent

                SplitView.preferredWidth: root.width
                visible: true
            }

            PropertyChanges {
                target: thirdComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            ParentChange {
                target: thirdComponent2
                parent: thirdComponent
            }

            StateChangeScript {
                script: {
                    drawer.close();
                }
            }
        },

        // Случай, когда размер окна <= root.singleComponentBreakPoint, и отображается только трейти компонент
        State {
            name: "MinimalNThird"

            /*PropertyChanges {
                target: firstComponent

                SplitView.preferredWidth: 0
                visible: false
            }
            PropertyChanges {
                target: secondComponent

                SplitView.preferredWidth: 0
                visible: false
            }
            PropertyChanges {
                target: thirdComponent

                SplitView.preferredWidth: root.width
                visible: true
            }*/

            ParentChange {
                target: thirdComponent2
                parent: fourthComponent
            }

            StateChangeScript {

                script: {
                    drawer.open();
                    // internal.drawerOpen = true;
                }
            }
        },

        // Средняя ширина окна

        // Случай, когда размер окна >= root.singleComponentBreakPoint и <= root.threeComponentBreakPoint + открыт третий компонент, отображаются второй и третий компоненты
        State {
            name: "AverageNOpenThird"

            PropertyChanges {
                target: firstComponent

                SplitView.minimumWidth: 360
                visible: true
            }
            PropertyChanges {
                target: secondComponent

                SplitView.minimumWidth: 360
                SplitView.fillWidth: true
                visible: true
            }
            PropertyChanges {
                target: thirdComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            ParentChange {
                target: thirdComponent2
                parent: fourthComponent
            }

            StateChangeScript {

                script: {
                    drawer.open();
                    // internal.drawerOpen = true;
                }
            }
        },

        // Случай, когда размер окна >= root.singleComponentBreakPoint и <= root.threeComponentBreakPoint + закрыт третий компонент, отображаются первый и второй компоненты
        State {
            name: "AverageNCloseThird"

            PropertyChanges {
                target: firstComponent

                SplitView.minimumWidth: 360
                visible: true
            }
            PropertyChanges {
                target: secondComponent

                SplitView.minimumWidth: 360
                SplitView.fillWidth: true
                visible: true
            }
            PropertyChanges {
                target: thirdComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            StateChangeScript {

                script: {
                    drawer.close();
                    internal.currentElement = 1;
                    // internal.drawerOpen = false;
                }
            }
        },

        // Максимальная ширина окна

        // Случай, когда размер окна максимальный + открыт третий компонент, отображаются все компоненты
        State {
            name: "MaximumNOpenThird"

            PropertyChanges {
                target: firstComponent

                SplitView.minimumWidth: 360
                visible: true
            }
            PropertyChanges {
                target: secondComponent

                SplitView.minimumWidth: 360
                SplitView.fillWidth: true
                visible: true
            }
            PropertyChanges {
                target: thirdComponent

                SplitView.minimumWidth: 360
                visible: true
            }

            StateChangeScript {

                script: {
                    drawer.close();
                    thirdComponent.visible = true;
                    // internal.drawerOpen = false;
                }
            }
        },

        // Случай, когда размер окна максимальный + закрыт третий компонент, отображаются первый и второй компоненты
        State {
            name: "MaximumNCloseThird"

            PropertyChanges {
                target: firstComponent

                SplitView.minimumWidth: 360
                visible: true
            }
            PropertyChanges {
                target: secondComponent

                SplitView.minimumWidth: 360
                SplitView.fillWidth: true
                visible: true
            }
            PropertyChanges {
                target: thirdComponent

                SplitView.preferredWidth: 0
                visible: false
            }

            StateChangeScript {

                script: {
                    drawer.close();
                    // internal.drawerOpen = false;
                }
            }
        }
    ]

    transitions: [
        // Переходы между состояниями с минимальной шириной окна
        Transition {
            from: "MinimalNFirstNOpenThird"
            to: "MinimalNFirstNCloseThird"

            // без изменений
        },

        Transition {
            from: "MinimalNFirstNCloseThird"
            to: "MinimalNFirstNOpenThird"

            // без изменений
        },

        Transition {
            from: "MinimalNFirstNCloseThird"
            to: "MinimalNSecondNCloseThird"

            ParallelAnimation {
                SequentialAnimation {
                    NumberAnimation {
                        target: firstComponent

                        property: "SplitView.preferredWidth"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                    NumberAnimation {
                        target: firstComponent

                        property: "visible"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                }

                NumberAnimation {
                    target: secondComponent

                    property: "SplitView.preferredWidth"
                    easing.type: internal.animationType
                    duration: internal.duration
                }
            }
        },

        Transition {
            from: "MinimalNSecondNCloseThird"
            to: "MinimalNFirstNCloseThird"

            ParallelAnimation {
                SequentialAnimation {
                    NumberAnimation {
                        target: secondComponent

                        property: "SplitView.preferredWidth"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                    NumberAnimation {
                        target: secondComponent

                        property: "visible"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                }

                NumberAnimation {
                    target: firstComponent

                    property: "SplitView.preferredWidth"
                    easing.type: internal.animationType
                    duration: internal.duration
                }
            }
        },

        Transition {
            from: "MinimalNSecondNOpenThird"
            to: "MinimalNSecondNCloseThird"

            // без изменений
        },

        Transition {
            from: "MinimalNSecondNCloseThird"
            to: "MinimalNSecondNOpenThird"

            // без изменений
        },

        // Переходы между состояниями с средней шириной окна

        Transition {
            from: "AverageNOpenThird"
            to: "AverageNCloseThird"

            ParallelAnimation {
                SequentialAnimation {
                    NumberAnimation {
                        target: thirdComponent
                        property: "SplitView.minimumWidth"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                    NumberAnimation {
                        target: thirdComponent
                        property: "visible"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                }

                NumberAnimation {
                    target: firstComponent

                    property: "SplitView.minimumWidth"
                    easing.type: internal.animationType
                    duration: internal.duration
                }
            }
        },

        Transition {
            from: "AverageNCloseThird"
            to: "AverageNOpenThird"

            ParallelAnimation {
                SequentialAnimation {
                    NumberAnimation {
                        target: firstComponent

                        property: "SplitView.minimumWidth"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                    NumberAnimation {
                        target: firstComponent

                        property: "visible"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                }

                NumberAnimation {
                    target: thirdComponent

                    property: "SplitView.minimumWidth"
                    easing.type: internal.animationType
                    duration: internal.duration
                }
            }
        },

        // Переходы между состояниями с максимальной шириной окна

        Transition {
            from: "MaximumNOpenThird"
            to: "MaximumNCloseThird"

            SequentialAnimation {
                NumberAnimation {
                    target: thirdComponent

                    property: "SplitView.minimumWidth"
                    easing.type: internal.animationType
                    duration: internal.duration
                }

                NumberAnimation {
                    target: thirdComponent
                    property: "visible"
                    duration: 0
                }
            }
        },

        Transition {
            from: "MaximumNCloseThird"
            to: "MaximumNOpenThird"

            NumberAnimation {
                target: thirdComponent
                property: "SplitView.minimumWidth"
                easing.type: internal.animationType
                duration: internal.duration
            }
        },

        // Переходы с максимальной ширины окна на среднюю ширину окна

        Transition {
            from: "MaximumNOpenThird"
            to: "AverageNOpenThird"

            NumberAnimation {
                property: "SplitView.minimumWidth"
                easing.type: internal.animationType
                duration: internal.duration
            }
        },

        // Переходы с средней ширины окна на максимальную ширину окна

        Transition {
            from: "AverageNOpenThird"
            to: "MaximumNOpenThird"

            NumberAnimation {
                target: firstComponent

                property: "SplitView.minimumWidth"
                easing.type: internal.animationType
                duration: internal.duration
            }

            ScriptAction {
                script: {
                    internal.openThirdComponent = true;
                }
            }
        },

        // Переходы с средней ширины окна на минимальную ширину окна

        Transition {
            from: "AverageNOpenThird"
            to: "MinimalNSecondNOpenThird"

            SequentialAnimation {
                NumberAnimation {
                    target: firstComponent
                    property: "SplitView.minimumWidth"
                    easing.type: internal.animationType
                    duration: internal.duration
                }

                NumberAnimation {
                    target: firstComponent

                    property: "visible"
                    duration: internal.duration
                }
            }
        },

        Transition {
            from: "MinimalNSecondNOpenThird"
            to: "AverageNOpenThird"

            SequentialAnimation {
                NumberAnimation {
                    target: firstComponent

                    property: "visible"
                    duration: internal.duration
                }

                NumberAnimation {
                    target: firstComponent
                    property: "SplitView.minimumWidth"
                    easing.type: internal.animationType
                    duration: internal.duration
                }
            }
        },

        Transition {
            from: "AverageNCloseThird"
            to: "MinimalNSecondNCloseThird"

            ParallelAnimation {
                SequentialAnimation {
                    NumberAnimation {
                        target: firstComponent

                        property: "SplitView.minimumWidth"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                    NumberAnimation {
                        target: firstComponent

                        property: "visible"
                        easing.type: internal.animationType
                        duration: internal.duration
                    }
                }

                NumberAnimation {
                    target: secondComponent

                    property: "SplitView.preferredWidth"
                    easing.type: internal.animationType
                    duration: internal.duration
                }
            }
        },

        Transition {
            from: "MinimalNSecondNCloseThird"
            to: "AverageNCloseThird"

            SequentialAnimation {

                NumberAnimation {
                    target: firstComponent

                    property: "visible"
                    duration: internal.duration
                }

                NumberAnimation {
                    target: firstComponent

                    property: "SplitView.minimumWidth"
                    easing.type: internal.animationType
                    duration: internal.duration
                }
            }
        }
    ]
}
