import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import pl.ochab 1.0

Window {
    width: 640
    height: 270
    visible: true
    title: qsTr("Hello World")

    Demo {
        id: demo
        value: 10.2
        onTest: function() {

            console.log("It works...")
            textField.clear()
        }
    }

    Displacement {
        id: displacement
        onChanged: function(value) {
            speed.onDisplacementChange(value)
        }
    }

    Speed {
        id: speed
        onChanged: function(value) {
            textSpeed.text = value;
            acceleration.onSpeedChange(value);
        }
    }

    Acceleration {

        id: acceleration
        onChanged: function(value) {
            textAcc.text = value;
        }
    }

    Text {
        id: displacementText
        x: 114
        y: 65
        width: 77
        height: 18
        text: qsTr("Displacement")
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 391
        y: 115
        text: qsTr("Change")
        onClicked: displacement.set(textEdit.text)
    }

    TextArea {
        id: textSpeed
        x: 239
        y: 121
        text: qsTr('Speed')
    }

    TextArea {
        id: textAcc
        x: 248
        y: 172
        text: qsTr('Acc')
    }

    Text {
        id: speedText
        x: 131
        y: 128
        text: qsTr("Speed")
        font.pixelSize: 12
    }

    Text {
        id: accelerationText
        x: 114
        y: 179
        text: qsTr("Acceleration")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit
        x: 228
        y: 65
        width: 126
        height: 20
        text: qsTr("Input displacement")
        font.capitalization: Font.AllUppercase
        font.weight: Font.Light
        font.pixelSize: 12
    }
}
