import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import Screens 1.0 as Screens

SplashScreen_Form {
    id: formSplashScreen
    objectName: "SplashScreen"

    // for Navigation.StackView
    Component {
        id: componentOneScreen
        Screens.ScreenLoader {
            screenName: "OneScreen"
            screen: Screens.OneScreen {
                anchors.fill: parent
            }
        }
    }

    Component {
        id: componentThreeScreen
        Screens.ScreenLoader {
            screenName: "ThreeScreen"
            screen: Screens.ThreeScreen {
                anchors.fill: parent
            }
        }
    }

    // for Navigation.StackView
    /*Component {
        id: componentOneScreen
        Screens.OneScreen {
            anchors.fill: parent
            screenName: "OneScreen"
        }
    }

    Component {
        id: componentThreeScreen
        Screens.ThreeScreen {
            anchors.fill: parent
            screenName: "ThreeScreen"
        }
    }*/

    onClickedService: {
        console.log("OneScreen load");
        next(componentOneScreen);
    }

    onClickedOther: {
        console.log("ThreeScreen load");
        next(componentThreeScreen);
    }
}
