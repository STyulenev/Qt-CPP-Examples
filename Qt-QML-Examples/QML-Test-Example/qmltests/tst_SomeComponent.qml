import QtQuick 2.15
import QtTest 1.1

import Components 1.0 as Components

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

    function test_checkComponent() {
        if (testComponent) {
            compare(testComponent.objectName, "SomeComponent", "Checking the objectName property");
        } else {
            fail("testComponent not created");
        }
    }

    function test_click() {
        compare(testComponent.value, 0, "Checking the value")
        testComponent.clicked();
        compare(testComponent.value, 1, "Checking the change of the value")
    }

    function test_color() {
        compare(testComponent.color, "#d3d3d3", "Checking the base color")
        testComponent.color = "#008000";
        compare(testComponent.color, "#008000", "Checking the change of the main color")
    }

    function test_size() {
        compare(testComponent.width, 250, "Checking width")
        compare(testComponent.height, 250, "Checking height")
    }

    function test_label() {
        var label = testComponent.children.find(({ objectName }) => objectName === "label");

        compare(label.font.pixelSize, 24, "Checking font.pixelSize");
        label.font.pixelSize = 44;
        compare(label.font.pixelSize, 44, "Checking the change of the font.pixelSize");
    }
}
