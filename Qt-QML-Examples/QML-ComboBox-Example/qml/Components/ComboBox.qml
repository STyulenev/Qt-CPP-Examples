import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

//import Common 1.0 as Common

Template.ComboBox {
    id: comboBox

    implicitWidth: implicitBackgroundWidth
    implicitHeight: implicitBackgroundHeight

    textRole: "DisplayRole"

    delegate: MenuItem {
        id: menuItem
        width: ListView.view ? ListView.view.width : 0
        //text: comboBox.textRole ? (Array.isArray(comboBox.model) ? modelData[comboBox.textRole] : model[comboBox.textRole]) : model.textRole
        highlighted: comboBox.highlightedIndex === index
        hoverEnabled: comboBox.hoverEnabled

        Row {
            anchors.fill: parent

            Image {
                source: model.DecorationRole

                width: comboBox.height - 5
                height: comboBox.height - 5
            }

            Text {
                text: model.DisplayRole
                font: comboBox.font
                verticalAlignment: Text.AlignVCenter
            }
        }

        Canvas {
            id: dot
            x: menuItem.width - width + 2
            y: menuItem.topPadding + (menuItem.availableHeight - height) / 2
            width: menuItem.height
            height: menuItem.height
            visible: menuItem.hovered

            onPaint: {
                var context = getContext("2d");
                context.reset();
                context.arc(height / 2, height / 2, 7, 0 * Math.PI, 2 * Math.PI);
                context.fillStyle = "blue";
                context.fill();
            }
        }
    }

    indicator: Canvas {
        id: canvas
        x: comboBox.width - width - 5
        y: comboBox.topPadding + (comboBox.availableHeight - height) / 2
        width: comboBox.height * (comboBox.hovered ? 0.65 : 0.6)
        height: comboBox.height * (comboBox.hovered ? 0.55 : 0.5)
        rotation: popup.opened ? 90 : 0

        Connections {
            target: comboBox

            function onPressedChanged() {
                canvas.requestPaint();
            }
        }

        onPaint: {
            var context = getContext("2d");
            context.reset();
            context.moveTo(0, 0);
            context.lineTo(width, 0);
            context.lineTo(width / 2, height);
            context.closePath();
            context.fillStyle = "blue";
            context.fill();
        }
    }

    contentItem: TextField {
        id: inputField
        leftPadding: 6
        rightPadding: 6 - comboBox.padding
        topPadding: 0
        bottomPadding: 0

        font {
            pixelSize: 15
            bold: false
        }

        text: comboBox.displayText
        enabled: comboBox.editable
        autoScroll: comboBox.editable
        readOnly: comboBox.down
        inputMethodHints: comboBox.inputMethodHints
        validator: comboBox.validator
        selectionColor: comboBox.palette.highlight
        selectedTextColor: comboBox.palette.highlightedText
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle {
        implicitWidth: 85
        implicitHeight: 29
        radius: 3
        visible: !comboBox.flat || comboBox.down

        border {
            color: "blue"
            width: (comboBox.hovered ? 2 : 1)
        }
    }

    popup: Popup {
        id: popup
        y: comboBox.height - 1
        implicitHeight: contentItem.implicitHeight
        width: comboBox.width
        height: comboBox.model.length < 4 ? inputField.height * comboBox.model.length : inputField.height * 4

        palette: comboBox.palette
        font: comboBox.font
        topPadding: 4
        leftPadding: 2
        rightPadding: 2
        bottomPadding: 4

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: comboBox.delegateModel
            currentIndex: comboBox.highlightedIndex
            highlightRangeMode: ListView.ApplyRange
            Template.ScrollBar.vertical: ScrollBar {}
        }

        background: Rectangle {
            color: comboBox.popup.palette.window
            border.color: "blue"
            border.width: 1
            radius: 3
        }
    }
}
