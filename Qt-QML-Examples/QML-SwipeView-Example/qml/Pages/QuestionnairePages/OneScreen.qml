import QtQml 2.15
import QtQuick 2.15

import Pages 1.0

OneScreen_Form {
    id: formOneScreen
    objectName: "OneScreen"

    onRightButtonClicked:  {
        if (inputName) {
            swipeViewData.currentModel.name = inputName;
            swipeView.incrementCurrentIndex();

            console.log(swipeViewData.currentModel.name)
        }
    }
}
