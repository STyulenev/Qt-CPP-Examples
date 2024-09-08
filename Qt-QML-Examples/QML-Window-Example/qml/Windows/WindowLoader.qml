import QtQuick 2.15

Loader {
    id: loader

    property alias window: loader.sourceComponent

    asynchronous: true

    onLoaded: {
        item.show();

        loader.item.closeWindow.connect(loader.destroy);
        loader.item.closing.connect(loader.destroy);

        // ...
    }
}
