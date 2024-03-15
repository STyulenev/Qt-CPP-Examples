import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

import Common 1.0 as CommonData

ApplicationWindow {
    id: mainWindow

    visible: true
    width: CommonData.Consts.screenWidth
    height: CommonData.Consts.screenHeight
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    title: qsTr("QML-StackView-Example")

    header: Rectangle {
        id: screenHeader
        visible: true

        height: 40
        color: "green"

        Text {
            id: name
            anchors.centerIn: parent
            text: contentFrame.currentItem.screenName ? contentFrame.currentItem.screenName : ""
        }
    }

    StackView {
        id: contentFrame
        objectName: "BaseStackView"

        anchors.fill: parent

        Component.onCompleted: contentFrame.push("qrc:/qml/Screens/Splash/SplashScreen.qml")

        pushEnter: null
        pushExit: null
        popEnter: null
        popExit: null
        replaceEnter: null
        replaceExit: null

        onCurrentItemChanged: {
            contentFrame.currentItem.forceActiveFocus();
        }

        Connections {
            target: contentFrame.currentItem

            function onExit() {
                contentFrame.pop();
            }

            function onNext(screen) {
                contentFrame.push(screen);
            }

            function onReplace(screen) {
                contentFrame.replace(contentFrame.currentItem, screen);
            }

            function onBackTo(name) {
                contentFrame.pop(contentFrame.find(function (item, id) {
                    if (item.objectName === name) {
                        return item;
                    }
                }))
            }
        }
    }
}
