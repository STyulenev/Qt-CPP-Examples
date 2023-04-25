import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

LabelTemplate {
    id: labelAndTextField

    labelPosition: Qt.AlignLeft

    signal activateFocus
    signal accepted

    Connections {
        target: labelAndTextField

        function onActivateFocus() {
            textField.forceActiveFocus();
        }
    }

    property alias textFieldText: textField.text
    property alias textFieldFocus: textField.focus
    property alias textFieldActiveFocus: textField.activeFocus
    property alias textFieldMaximumLength: textField.maximumLength
    property alias textFieldFontFamily: textField.font.family
    property alias textFieldEchoMode: textField.echoMode
    property alias textFieldValidator: textField.validator
    property alias textFieldEnabled: textField.enabled
    property alias textFieldColor: textField.color
    property int   textFieldWidth: textField.implicitWidth

    widget: TextField {
        id: textField
        Layout.preferredWidth: labelAndTextField.textFieldWidth

        Connections {
            function onAccepted() {
                labelAndTextField.accepted();
            }
        }
    }
}
