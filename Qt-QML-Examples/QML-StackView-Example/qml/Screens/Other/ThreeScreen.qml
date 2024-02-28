import QtQuick 2.15

import Screens 1.0 as Screens

ThreeScreen_Form {
    id: formThreeScreen
    objectName: "ThreeScreen"

    Component {
        id: componentFourScreen
        Screens.ScreenLoader {
            screenName: "FourScreen"
            screen: FourScreen {}
        }
    }

    onClickedFourScreen: {
        console.log("Open FourScreen");
        next(componentFourScreen);
    }

    onBackButtonClicked: {
        console.log("Back");
        exit();
    }
}
