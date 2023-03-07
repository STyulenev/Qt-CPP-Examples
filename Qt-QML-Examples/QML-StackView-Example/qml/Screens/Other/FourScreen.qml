import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Screens 1.0

FourScreen_Form {
    id: formFourScreen
    objectName: "FourScreen"

    Component {
        id: componentFiveScreen
        ScreenLoader {
            screenName: "FiveScreen"
            screen: FiveScreen {}
        }
    }

    onClickedFourScreen: {
        console.log("Open FiveScreen")
        push(componentFiveScreen)
    }

    onClickedBack: {
        console.log("Back")
        exit()
    }
}
