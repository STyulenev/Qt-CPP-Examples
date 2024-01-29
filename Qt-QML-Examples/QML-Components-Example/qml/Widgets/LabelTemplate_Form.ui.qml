import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

GridLayout {
    id: labelTemplate

    property int    labelPosition: Qt.AlignTop
    property alias  labelText: label.text
    property alias  labelFont: label.font
    property int    labelWidth: label.implicitWidth
    property bool   labelFillWidth: false
    property bool   labelFillHeight: false
    property int    labelAlignment: Text.AlignLeft
    property int    labelTextHorizontalAlignment: Text.AlignLeft

    property alias widget: container.children
    property alias widgetParent: container
    property alias widgetGridColumnCount: container.columns
    property alias widgetGridRowSpacing: container.rowSpacing
    property int   widgetAlignment: Qt.AlignLeft

    Label {
        id: label
        wrapMode: Text.Wrap
        horizontalAlignment: labelTemplate.labelTextHorizontalAlignment

        Layout.fillWidth: labelTemplate.labelFillWidth
        Layout.fillHeight: labelTemplate.labelFillHeight
        Layout.preferredWidth: labelTemplate.labelWidth

        Layout.alignment: labelTemplate.labelAlignment
    }

    GridLayout {
        id: container

        Layout.alignment: labelTemplate.widgetAlignment
    }

    states: [
        State {
            when: labelTemplate.labelPosition === Qt.AlignTop
            PropertyChanges {
                target: labelTemplate
                rows: 2
                columns: 1
            }
            PropertyChanges {
                target: label
                Layout.row: 0
                Layout.column: 0
            }
            PropertyChanges {
                target: container
                Layout.row: 1
                Layout.column: 0
            }
        },
        State {
            when: labelTemplate.labelPosition === Qt.AlignBottom
            PropertyChanges {
                target: labelTemplate
                rows: 2
                columns: 1
            }
            PropertyChanges {
                target: label
                Layout.row: 1
                Layout.column: 0
            }
            PropertyChanges {
                target: container
                Layout.row: 0
                Layout.column: 0
            }
        },
        State {
            when: labelTemplate.labelPosition === Qt.AlignLeft
            PropertyChanges {
                target: labelTemplate
                rows: 1
                columns: 2
            }
            PropertyChanges {
                target: label
                Layout.row: 0
                Layout.column: 0
            }
            PropertyChanges {
                target: container
                Layout.row: 0
                Layout.column: 1
            }
        },
        State {
            when: labelTemplate.labelPosition === Qt.AlignRight
            PropertyChanges {
                target: labelTemplate
                rows: 1
                columns: 2
            }
            PropertyChanges {
                target: label
                Layout.row: 0
                Layout.column: 1
            }
            PropertyChanges {
                target: container
                Layout.row: 0
                Layout.column: 0
            }
        }
    ]
}
