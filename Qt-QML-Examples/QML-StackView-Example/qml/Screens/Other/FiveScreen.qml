import QtQml 2.15
import QtQuick 2.15

FiveScreen_Form {
    id: formFiveScreen
    objectName: "FiveScreen"

    onClickedBackToThreeScreen: {
        console.log("Back To Three Screen");
        backTo("ThreeScreen");
    }

    onBackButtonClicked: {
        console.log("Back");
        exit();
    }
}
