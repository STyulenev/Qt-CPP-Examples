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
    title: qsTr("QML-Audio-Example")

    QtObject {
        id: internal

        readonly property int buttonHeight: 40
        readonly property int buttonWidth: 80
    }

    QtMultimedia.MediaPlayer {
        id: audio

        source: "..." // audio path ...
        audioOutput: QtMultimedia.AudioOutput {
            volume: soundSlider.value
            muted: false
        }
        videoOutput: videoOutput

        onPositionChanged: {
            progressSlider.value = audio.position;
        }
    }

    QtMultimedia.VideoOutput {
        id: videoOutput

        anchors {
            top: parent.top
            left: parent.left
            bottom: progressSlider.top
            right: soundSlider.left
            margins: 10
        }
    }

    Slider {
        id: soundSlider

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            margins: 10
        }

        orientation: Qt.Vertical

        width: 25

        from: 0.
        to: 1.
        value: 0.5
    }

    Slider {
        id: progressSlider

        anchors {
            left: parent.left
            bottom: panel.top
            right: soundSlider.left
            margins: 10
        }

        orientation: Qt.Horizontal

        height: 25

        from: 0
        to: audio.duration

        onMoved: {
            audio.position = progressSlider.value;
        }
    }

    Item {
        id: panel

        anchors {
            bottom: parent.bottom
            right: soundSlider.left
            left: parent.left
            margins: 10
        }

        height: 50

        Row {
            id: menu

            anchors.centerIn: parent
            spacing: 10

            Button {
                width: internal.buttonWidth
                height: internal.buttonHeight

                text: qsTr("Play")

                onClicked: {
                    if (audio.mediaStatus === QtMultimedia.MediaPlayer.InvalidMedia) {
                        console.log("Error");
                    } else {
                        audio.play();
                    }
                }
            }

            Button {
                width: internal.buttonWidth
                height: internal.buttonHeight

                text: qsTr("Stop")

                onClicked: audio.stop()
            }

            Button {
                width: internal.buttonWidth
                height: internal.buttonHeight

                text: qsTr("Pause")

                onClicked: audio.pause();
            }
        }
    }
}
