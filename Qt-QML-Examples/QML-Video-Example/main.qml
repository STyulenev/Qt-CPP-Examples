import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import QtMultimedia as QtMultimedia

ApplicationWindow {
    id: application

    width: 580
    height: 320
    visible: true
    title: qsTr("QML-Video-Example")

    QtObject {
        id: internal

        readonly property int buttonHeight: 50
        readonly property int buttonWidth: 50
    }

    function msToTime(duration) {
        var milliseconds = Math.floor((duration % 1000) / 100),
        seconds = Math.floor((duration / 1000) % 60),
        minutes = Math.floor((duration / (1000 * 60)) % 60),
        hours = Math.floor((duration / (1000 * 60 * 60)) % 24);

        hours = (hours < 10) ? "0" + hours : hours;
        minutes = (minutes < 10) ? "0" + minutes : minutes;
        seconds = (seconds < 10) ? "0" + seconds : seconds;

        return hours + ":" + minutes + ":" + seconds + "." + milliseconds;
    }

    QtMultimedia.Video {
        id: video

        anchors {
            top: parent.top
            right: parent.right
            left: parent.left
            bottom: bottomPanel.top
        }

        focus: true
        muted: false
        volume: 1.0
        source: "path ..."

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            onClicked: video.play()
        }

        Keys.onSpacePressed: {
            video.playbackState == QtMultimedia.MediaPlayer.PlayingState ? video.pause() : video.play()
        }

        Keys.onLeftPressed: {
            video.playbackState == QtMultimedia.MediaPlayer.PlayingState ? video.pause() : video.play()
        }
    }

    // Можно добавить FileDialog из примера Qt-QML-Examples/QML-Window-Example для выбора файла
    // Можно сделать скрывающуюся/раскрывающуюся панель из примера Qt-QML-Examples/QML-Drawer-Example
    Rectangle {
        id: bottomPanel

        height: 100

        color: "white"

        anchors {
            right: parent.right
            left: parent.left
            bottom: parent.bottom
        }

        ColumnLayout {

            anchors {
                fill: parent
                margins: 10
            }

            RowLayout {

                Layout.fillWidth: true
                Layout.preferredHeight: 30
                Layout.margins: 20

                Slider {
                    id: progressSlider

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    from: 0
                    to: video.duration
                    value: video.position

                    onValueChanged: {
                        video.position = progressSlider.value;
                    }

                    ToolTip {
                        parent: progressSlider.handle
                        visible: progressSlider.pressed
                        text: ("%1 / %2").arg(msToTime(video.position)).arg(msToTime(video.duration))
                    }
                }

                Slider {
                    id: volumeSlider

                    Layout.fillWidth: parent / 4
                    Layout.fillHeight: true

                    from: 0.0
                    to: 1.0
                    value: video.volume

                    onValueChanged: {
                        video.volume = volumeSlider.value;
                    }

                    ToolTip {
                        parent: volumeSlider.handle
                        visible: volumeSlider.pressed
                        text: ("%1%").arg(parseInt(video.volume * 100))
                    }
                }
            }

            RowLayout {
                id: menu

                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignCenter

                Button {
                    width: internal.buttonWidth
                    height: internal.buttonHeight

                    text: qsTr("Play")

                    onClicked: video.play()
                }

                Button {
                    width: internal.buttonWidth
                    height: internal.buttonHeight

                    text: qsTr("Stop")

                    onClicked: video.stop()
                }

                Button {
                    width: internal.buttonWidth
                    height: internal.buttonHeight

                    text: qsTr("Pause")

                    onClicked: video.pause();
                }
            }
        }
    }
}
