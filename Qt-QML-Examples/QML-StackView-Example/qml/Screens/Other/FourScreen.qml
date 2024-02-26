import QtQuick 2.15

import Screens 1.0 as Screens

FourScreen_Form {
    id: formFourScreen
    objectName: "FourScreen"

    Component {
        id: componentFiveScreen
        Screens.ScreenLoader {
            screenName: "FiveScreen"
            screen: FiveScreen {}
        }
    }

    onClickedFourScreen: {
        console.log("Open FiveScreen");
        next(componentFiveScreen);
    }

    onBackButtonClicked: {
        console.log("Back");
        exit();
    }
}
