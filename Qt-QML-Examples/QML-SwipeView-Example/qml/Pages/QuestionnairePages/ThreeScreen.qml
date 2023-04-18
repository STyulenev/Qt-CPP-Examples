import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import Common 1.0 as CommonData

ThreeScreen_Form {
    id: formThreeScreen
    objectName: "ThreeScreen"

    Component.onCompleted : {
        inputSex.model = CommonData.Helpers.getSexList();
        inputSex.currentIndex = swipeViewData.currentModel.sex
    }

    onLeftButtonClicked: {
        swipeView.decrementCurrentIndex();
    }

    onRightButtonClicked:  {
        swipeViewData.currentModel.sex = inputSex.currentIndex;
        swipeView.incrementCurrentIndex();

        console.log(swipeViewData.currentModel.sex)
    }
}
