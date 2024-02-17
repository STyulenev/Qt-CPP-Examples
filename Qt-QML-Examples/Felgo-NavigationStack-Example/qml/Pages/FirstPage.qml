import QtQuick

import Pages 1.0 as Pages

FirstPage_Form {
    id: firstPage

    Component {
        id: secondPage

        Pages.SecondPage {

        }
    }

    onClicked: {
        navigationStack.push(secondPage)
    }
}

