import QtQuick 2.12
import QtQml 2.12

import Screens 1.0 as Screens

FiveScreen_Form {
    id: formFiveScreen
    objectName: "FiveScreen"

    onClickedBackToThreeScreen: {
        console.log("Back To ThreeScreen")
        backTo("ThreeScreen")
    }

    onClickedBack: {
        console.log("Back")
        exit()
    }
}
