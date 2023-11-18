import QtQuick 2.15

Loader {
    id: loader

    property alias component: loader.sourceComponent

    signal closing()

    asynchronous: true

    onLoaded: {
        item.show()

        loader.item.closing.connect(loader.destroy)
    }
}
