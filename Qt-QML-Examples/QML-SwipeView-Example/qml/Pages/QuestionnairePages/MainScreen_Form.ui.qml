import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

// Import C ++ class
import Models 0.1 as Models

import Pages 1.0 as QuestionnairePages

Item {
    id: main

    property alias flickableSwipeView: swipeView.interactive

    QtObject {
        id: swipeViewData

        property int speed: 5
        property int gain: 10
        property int xValue: 976
        property int degreeValue: 143

        property QtObject currentModel: Models.QuestionnaireModel {}
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent

        QuestionnairePages.OneScreen { }
        QuestionnairePages.TwoScreen { }
        QuestionnairePages.ThreeScreen { }
        QuestionnairePages.FourScreen { }
    }

    PageIndicator {
        id: indicator

        count: swipeView.count
        currentIndex: swipeView.currentIndex

        anchors.bottom: swipeView.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
