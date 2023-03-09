import QtQuick
import QtQml 2.15

TwoScreen_Form {
    id: formTwoScreen
    objectName: "TwoScreen"

    onClickedPrintLog: {
        console.log("Print Log clicked")
    }

    onClickedBack: {
        console.log("Back")
        exit()
    }
}
