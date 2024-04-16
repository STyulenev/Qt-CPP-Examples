import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import QtMultimedia as QtMultimedia

ApplicationWindow {
    id: application

    width: 480
    height: 320
    visible: true
    title: qsTr("QML-Video-Example")

    QtMultimedia.Video {
        id: video

        anchors.fill: parent
        focus: true
        source: "path ..."

        MouseArea {
            anchors.fill: parent
            onClicked: {
                video.play()
            }
        }

        Keys.onSpacePressed: {
            video.playbackState == QtMultimedia.MediaPlayer.PlayingState ? video.pause() : video.play()
        }

        Keys.onLeftPressed: {
            video.playbackState == QtMultimedia.MediaPlayer.PlayingState ? video.pause() : video.play()
        }
    }
}
