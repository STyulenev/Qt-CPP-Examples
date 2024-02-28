import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

LabelTemplate {
    signal currentIndexChanged

    property alias comboBoxModel: comboBox.model
    property alias comboBoxIndex: comboBox.currentIndex
    property int   comboBoxWidth: comboBox.implicitWidth

    labelAlignment: Qt.AlignLeft

    widget: ComboBox {
        id: comboBox
        Layout.fillWidth: true
        Layout.preferredWidth: comboBoxWidth

        Connections {
            function onCurrentIndexChanged() {
                currentIndexChanged();
            }
        }
    }
}
