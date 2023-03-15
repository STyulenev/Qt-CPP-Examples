import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

MainScreen_Form {
    id: formMainScreen
    objectName: "MainScreen"

    Component.onCompleted: {
        state = "Grid";
    }

    onChangeViewState: {
        if (state === "Grid") {
            state = "List";
        } else {
            state = "Grid";
        }
    }

    onChangeThemeState: {
        sunTheme = !sunTheme;
    }
}
