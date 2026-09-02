import QtQuick

Rectangle {
    id: stackArea

    property var currentItem: null

    QtObject {
        id: internal

        property int currentZ: 0
        property var arrayObjects: []
    }

    function push(item) {
        var newItem = item.createObject(stackArea, {
                        parent: stackArea,
                        z: internal.currentZ
                    });

        newItem.next.connect(stackArea.push);
        newItem.exit.connect(stackArea.pop);
        // ...

        if (newItem === null) {
            console.log("Ошибка создания компонента");
        }

        internal.currentZ = internal.currentZ + 1;
        internal.arrayObjects.push(newItem);

        stackArea.currentItem = newItem;
    }

    function pop() {
        if (internal.arrayObjects.length > 0) {
            var lastItem = internal.arrayObjects[internal.currentZ - 1];
            lastItem.destroy();

            internal.arrayObjects.pop();
            internal.currentZ = internal.currentZ - 1;

            stackArea.currentItem = internal.arrayObjects[internal.currentZ - 1];
        }
    }
}
