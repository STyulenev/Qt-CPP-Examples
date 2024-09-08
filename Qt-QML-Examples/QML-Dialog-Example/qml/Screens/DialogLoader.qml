import QtQuick 2.15

Loader {
    id: loader

    property alias component: loader.sourceComponent

    asynchronous: true

    onLoaded: {
        item.open()

        loader.item.accepted.connect(loader.destroy)
        loader.item.rejected.connect(loader.destroy)
    }
}
