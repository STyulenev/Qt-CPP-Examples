import QtQml 2.15
import QtQuick 2.15

TwoScreen_Form {
    id: formTwoScreen
    objectName: "TwoScreen"

    onLeftButtonClicked: {
        swipeView.decrementCurrentIndex();
    }

    onRightButtonClicked:  {
        if (inputAge >= 18) {
            swipeViewData.currentModel.age = inputAge;
            swipeView.incrementCurrentIndex();

            console.log(swipeViewData.currentModel.age)
        }
    }
}
