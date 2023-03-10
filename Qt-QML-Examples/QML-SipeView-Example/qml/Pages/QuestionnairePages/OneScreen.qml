import QtQml 2.15
import QtQuick 2.15

import Pages 1.0

OneScreen_Form {
    id: formOneScreen
    objectName: "OneScreen"

    onClickedTwoScreen: {
        console.log(swipeViewData.xValue)

        console.log(swipeViewData.currentModel.name)
    }
}
