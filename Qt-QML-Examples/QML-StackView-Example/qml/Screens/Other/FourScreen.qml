import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

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
        push(componentFiveScreen);
    }

    onBackButtonClicked: {
        console.log("Back");
        exit();
    }
}
