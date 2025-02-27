import QtQuick 2.15

import ui.components 1.0 as UI

Rectangle {
    id: component

    Component.onCompleted: {
        setColor();
    }

    property int colorType: UI.ColorTypes.Black

    function setColor() {
        console.log("1 = " + colorType)
        switch (colorType) {
        case UI.ColorTypes.Black:
            console.log("2")
            component.color = "black";
            return;
        case UI.ColorTypes.Grey:
            console.log("3")
            component.color = "grey";
            return;
        case UI.ColorTypes.Yellow:
            component.color = "yellow";
            return;
        case UI.ColorTypes.Pink:
            component.color = "pink";
            return;

            // ...
        }
    }

    color: "green"

    onColorTypeChanged: {
        setColor();
    }

    // ...
}
