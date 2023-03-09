import QtQuick
import QtQml 2.15

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
