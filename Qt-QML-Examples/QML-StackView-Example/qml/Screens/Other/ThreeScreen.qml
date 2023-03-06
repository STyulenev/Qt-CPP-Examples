import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Screens 1.0 as Screens

ThreeScreen_Form {
    id: formThreeScreen
    objectName: "ThreeScreen"

    Component {
        id: componentFourScreen
        Screens.ScreenLoader {
            screenName: "FourScreen"
            screen: Screens.FourScreen {}
        }
    }

    onClickedFourScreen: {
        console.log("Open FourScreen")
        push(componentFourScreen)
    }

    onClickedBack: {
        console.log("Back")
        exit()
    }
}
