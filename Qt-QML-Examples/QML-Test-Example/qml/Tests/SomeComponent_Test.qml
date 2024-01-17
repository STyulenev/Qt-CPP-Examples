import QtQuick 2.15
import QtTest 1.1

import "../Components" 1.0 as Components

TestCase {
    id: root
    name: "SomeComponentTests"

    property var testComponent

    Component {
        id: componentSomeComponent

        Components.SomeComponent {
            width: 250
            height: 250
        }
    }

    function init() {
        testComponent = createTemporaryObject(componentSomeComponent, root);
    }

    function test_click() {
        compare(testComponent.value, 0)
        testComponent.clicked();
        compare(testComponent.value, 1)
    }

    function test_color() {
        compare(testComponent.color, "#d3d3d3")
        testComponent.color = "#008000";
        compare(testComponent.color, "#008000")
    }

    function test_size() {
        compare(testComponent.width, 250)
        compare(testComponent.height, 250)
    }

    function test_label() {
        var label = testComponent.children.find(({ objectName }) => objectName === "label");

        compare(label.font.pixelSize, 24);
        label.font.pixelSize = 44;
        compare(label.font.pixelSize, 44);
    }
}
