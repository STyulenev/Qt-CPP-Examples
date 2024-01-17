import QtQuick 2.11
import QtQuick.Controls 2.4

Rectangle {
    id: root

    property int size: 150
    property int lineWidth: 7
    property int textSize: 32
    property int maximumValue: 100

    property int value: 0
    readonly property int degreeShift: 30

    property int animationDuration: 0 // 1000

    color: "transparent"

    width: size
    height: size
    radius: size / 2

    onValueChanged: {
        if ((root.value <= root.maximumValue) && (root.value >= 0)) {
            canvas.degree = (((360 - degreeShift * 2) * (root.value / root.maximumValue)) * Math.PI / 180);
            speedometer.text = root.value; // ("%1 %2").arg(root.value).arg("км/ч");
        }
    }

    Canvas {
        id: canvas
        z: 1

        property real degree: 0
        readonly property real shift: (30 * Math.PI) / 180
        readonly property real margins: 20

        anchors.fill: parent
        antialiasing: true

        onDegreeChanged: {
            requestPaint();
        }

        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();

            var centreX = root.size / 2
            var centreY = root.size / 2
            var radius = root.size / 2 - canvas.margins
            var startangle = Math.PI * 0.5 + shift
            var endangle = - Math.PI * 0.5;

            ctx.lineCap = 'round';
            ctx.lineWidth = root.lineWidth;

            ctx.beginPath();
            ctx.arc(centreX, centreY, radius, Math.PI * 0.5 + shift, Math.PI * 0.5 - shift);
            ctx.strokeStyle = "grey";
            ctx.stroke();

            // tags
            for (var i = 0; i < 11; i++) {
                ctx.beginPath();
                ctx.save();
                ctx.translate(root.radius, root.radius);
                ctx.rotate(i * (300 / 10) * Math.PI / 180 + canvas.shift);
                ctx.moveTo(0, root.radius - 20);
                ctx.lineTo(0, root.radius - 5);
                ctx.stroke();
                ctx.restore();
                ctx.closePath();
            }

            if ((root.value <= root.maximumValue) && (root.value > 0)) {
                ctx.beginPath();
                ctx.arc(centreX, centreY, radius, Math.PI * 0.5 + shift, Math.PI * 0.5 + canvas.degree + shift);
                ctx.strokeStyle = "green"
                ctx.stroke();
            }
        }

        Behavior on degree {
            NumberAnimation {
                duration: root.animationDuration
            }
        }
    }

    Label {
        id: speedometer
        z: 2
        anchors.centerIn: parent
        font.pixelSize: root.textSize

        text: "0"
    }
}

