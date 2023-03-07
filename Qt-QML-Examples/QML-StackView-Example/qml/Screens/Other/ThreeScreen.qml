import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Screens 1.0

ThreeScreen_Form {
    id: formThreeScreen
    objectName: "ThreeScreen"

    Component {
        id: componentFourScreen
        ScreenLoader {
            screenName: "FourScreen"
            screen: FourScreen {}
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
