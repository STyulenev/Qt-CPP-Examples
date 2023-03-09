import QtQuick
import QtQml 2.15
import QtQuick.Controls 2.15

Item {
    id: main

    property string screenName: "Screen"

    signal exit
    signal next(Component screen)
    signal replace(Component screen)
    signal backTo(string name)
}
