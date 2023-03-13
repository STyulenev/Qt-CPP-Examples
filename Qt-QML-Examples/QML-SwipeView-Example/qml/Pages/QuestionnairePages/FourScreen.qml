import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import Common 1.0 as CommonData

FourScreen_Form {
    id: formFourScreen
    objectName: "FourScreen"

    onActiveFocusChanged: {
        labelName = qsTr("Name: ") + swipeViewData.currentModel.name;
        labelAge = qsTr("Age: ") + swipeViewData.currentModel.age;
        labelSex = qsTr("Sex: ") + CommonData.Helpers.getSex(swipeViewData.currentModel.sex);
    }

    onLeftButtonClicked: {
        swipeView.setCurrentIndex(0);
    }

    onRightButtonClicked:  {
        Qt.callLater(Qt.quit);
    }
}
