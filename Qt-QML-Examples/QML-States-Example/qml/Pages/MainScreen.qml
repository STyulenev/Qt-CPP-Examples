import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

MainScreen_Form {
    id: formMainScreen
    objectName: "MainScreen"

    Component.onCompleted: {
        state = "grid";
    }

    onChangeViewState: {
        if (state === "grid") {
            state = "list";
        } else {
            state = "grid";
        }
    }

    onChangeThemeState: {
        mainTheme = !mainTheme;
    }
}
