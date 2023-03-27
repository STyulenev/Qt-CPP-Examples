import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as T

import Common 1.0 as Common

T.ComboBox {
    id: comboBox

    implicitWidth: implicitBackgroundWidth
    implicitHeight: implicitBackgroundHeight

    font.pixelSize : Common.Fonts.pixelSize

    delegate: MenuItem {
        id: menuItem
        width: ListView.view ? ListView.view.width : 0
        text: comboBox.textRole ? (Array.isArray(comboBox.model) ? modelData[comboBox.textRole] : model[comboBox.textRole]) : modelData
        highlighted: comboBox.highlightedIndex === index
        hoverEnabled: comboBox.hoverEnabled

        Canvas {
            id: dot
            x: menuItem.width - width + 2 * Common.Consts.xCoord
            y: menuItem.topPadding + (menuItem.availableHeight - height) / 2
            width: menuItem.height
            height: menuItem.height

            visible: menuItem.hovered

            onPaint: {
                var context = getContext("2d");
                context.reset();
                context.arc(height / 2, height / 2, 7, 0 * Math.PI, 2 * Math.PI);
                context.fillStyle = "#4280d6";
                context.fill();
            }
        }
    }

    indicator: Canvas {
        id: canvas
        x: comboBox.width - width - 5 * Common.Consts.xCoord
        y: comboBox.topPadding + (comboBox.availableHeight - height) / 2
        width: comboBox.height * (comboBox.hovered ? 0.65 : 0.6)
        height: comboBox.height * (comboBox.hovered ? 0.55 : 0.5)
        contextType: "2d"

        Connections {
            target: comboBox

            function onPressedChanged() {
                canvas.requestPaint();
            }
        }

        rotation: popup.opened ? 90 : 0

        onPaint: {
            context.reset();
            context.moveTo(0, 0);
            context.lineTo(width, 0);
            context.lineTo(width / 2, height);
            context.closePath();
            context.fillStyle = "#4280d6";
            context.fill();
        }
    }

    contentItem: T.TextField {
        id: inputField
        leftPadding: 6 * Common.Consts.xCoord
        rightPadding: 6 * Common.Consts.xCoord - comboBox.padding
        topPadding: 0
        bottomPadding: 0
        
        font {
            family: Common.Fonts.family
            pixelSize: comboBox.hovered ? Common.Fonts.pixelSize + 5 : Common.Fonts.pixelSize
            bold: false
        }

        text: comboBox.displayText
        enabled: comboBox.editable
        autoScroll: comboBox.editable
        readOnly: comboBox.down
        inputMethodHints: comboBox.inputMethodHints
        validator: comboBox.validator

        color: "black"
        selectionColor: comboBox.palette.highlight
        selectedTextColor: comboBox.palette.highlightedText
        verticalAlignment: Text.AlignVCenter

    }

    background: Rectangle {
        implicitWidth: 85 * Common.Consts.xCoord
        implicitHeight: 29 * Common.Consts.yCoord

        border.color: "#4280d6" //comboBox.pressed ? "#17a81a" : "#21be2b"
        border.width: comboBox.hovered ? 4 : 2
        radius: 5

        visible: !comboBox.flat || comboBox.down
    }

    popup: T.Popup {
        id: popup
        y: comboBox.height - 1
        implicitHeight: contentItem.implicitHeight
        width: comboBox.width
        height: comboBox.model.length < 4 ? inputField.height * comboBox.model.length : inputField.height * 4

        palette: comboBox.palette
        font: comboBox.font
        topPadding: 4
        leftPadding: 4 //* Common.Consts.xCoord
        rightPadding: 4
        bottomPadding: 4

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: comboBox.delegateModel
            currentIndex: comboBox.highlightedIndex
            highlightRangeMode: ListView.ApplyRange
            T.ScrollBar.vertical: ScrollBar {}
        }

        background: Rectangle {
            color: comboBox.popup.palette.window

            border.color: "#4280d6"
            border.width: 2
            radius: 5
        }
    }
}
