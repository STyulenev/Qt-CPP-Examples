import QtQml 2.15
import QtQuick 2.15

TwoScreen_Form {
    id: formTwoScreen
    objectName: "TwoScreen"

    onClickedPrintLog: {
        console.log("Print Log clicked");
    }

    onBackButtonClicked: {
        console.log("Back");
        exit();
    }
}
