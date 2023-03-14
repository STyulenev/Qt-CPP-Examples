import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import Screens 1.0 as Screens

SplashScreen_Form {
    id: formSplashScreen
    objectName: "SplashScreen"

    Component {
        id: componentOneScreen
        Screens.ScreenLoader {
            screenName: "OneScreen"
            screen: Screens.OneScreen {}
        }
    }

    Component {
        id: componentThreeScreen
        Screens.ScreenLoader {
            screenName: "ThreeScreen"
            screen: Screens.ThreeScreen {}
        }
    }

    onClickedService: {
        console.log("OneScreen load");
        push(componentOneScreen)
    }

    onClickedOther: {
        console.log("ThreeScreen load");
        push(componentThreeScreen)
    }
}
