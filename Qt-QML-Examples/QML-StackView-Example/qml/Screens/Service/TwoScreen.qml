import QtQuick 2.12
import QtQml 2.12

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
