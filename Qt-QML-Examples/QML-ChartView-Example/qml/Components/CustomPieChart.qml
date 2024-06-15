import QtQuick 2.15

Item {
    id: root

    property var model

    Canvas {
        anchors.fill: parent

        onPaint: {
            if (!model) {
                return;
            }

            var contex = getContext("2d");
            contex.reset();

            const centerX = width / 2;
            const centerY = height / 2;

            var currentStartPoint = 0;
            var currentAngle = 0;

            for (var i = 0; i < model.length; ++i) {
                currentAngle = model[i].value * 2 * Math.PI + currentStartPoint;

                contex.beginPath();
                contex.fillStyle = model[i].color;
                contex.moveTo(centerX, centerY);
                contex.arc(centerX, centerY, width / 4, currentStartPoint, currentAngle, false);
                contex.lineTo(centerX, centerY);
                contex.fill();

                currentStartPoint = currentAngle;
            }
        }
    }
}
