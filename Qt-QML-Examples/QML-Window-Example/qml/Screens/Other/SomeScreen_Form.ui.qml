import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: formSomeScreen

    signal buttonCustomMessageBoxClicked
    signal buttonFileDialogClicked
    signal buttonMessageDialogClicked
    signal buttonColorDialogClicked
    signal buttonFolderDialogClicked

    QtObject {
        id: internal

        readonly property int buttonHeight: 50
        readonly property int buttonWidth: 250
    }

    Column {
        anchors.centerIn: parent

        Button {
            id: buttonCustomMessageBox

            height: internal.buttonHeight
            width: internal.buttonWidth

            text: qsTr("Open custom MessageBox")

            Connections {
                target: buttonCustomMessageBox

                function onClicked() {
                    formSomeScreen.buttonCustomMessageBoxClicked()
                }
            }
        }

        Button {
            id: buttonFileDialog

            height: internal.buttonHeight
            width: internal.buttonWidth

            text: qsTr("Open standart File Dialog")

            Connections {
                target: buttonFileDialog

                function onClicked() {
                    formSomeScreen.buttonFileDialogClicked()
                }
            }
        }

        Button {
            id: buttonMessageDialog

            height: internal.buttonHeight
            width: internal.buttonWidth

            text: qsTr("Open standart Message Dialog")

            Connections {
                target: buttonMessageDialog

                function onClicked() {
                    formSomeScreen.buttonMessageDialogClicked()
                }
            }
        }

        Button {
            id: buttonColorDialog

            height: internal.buttonHeight
            width: internal.buttonWidth

            text: qsTr("Open standart Color Dialog")

            Connections {
                target: buttonColorDialog

                function onClicked() {
                    formSomeScreen.buttonColorDialogClicked()
                }
            }
        }

        Button {
            id: buttonFolderDialog

            height: internal.buttonHeight
            width: internal.buttonWidth

            text: qsTr("Open standart Folder Dialog")

            Connections {
                target: buttonFolderDialog

                function onClicked() {
                    formSomeScreen.buttonFolderDialogClicked()
                }
            }
        }
    }
}
