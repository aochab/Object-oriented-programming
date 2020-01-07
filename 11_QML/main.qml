import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import pl.ochab 1.0

Window {
    visible: true
    width: 640
    height: 480
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
        value: 0
        onChanged: function(value) {
            console.log("dis")
            speed.onDisplacementChange(value)
        }
    }

    Speed {
        id: speed
        onChanged: function(value) {
            console.log("speed")
            textArea1.text = value;
            acceleration.onSpeedChange(value);
        }
    }

    Acceleration {

        id: acceleration
        onChanged: function(value) {
            console.log("acc")
            textArea2.text = value;
        }
    }

    Button {
        id: button
        x: 247
        y: 405
        text: qsTr("Button")
        onClicked: function() {
            label1.text = textField.text;
            demo.doSomething();
        }
    }

    TextField {
        id: textField
        x: 421
        y: 405
        text: qsTr("Text Field")
    }

    Label {
        id: label
        x: 101
        y: 428
        text: textField.text + " " + demo.value;
    }

    Label {
        id: label1
        x: 353
        y: 417
        text: qsTr("Label")
    }

    Text {
        id: element
        x: 108
        y: 97
        width: 77
        height: 15
        text: qsTr("Displacement")
        font.pixelSize: 12
    }

    Button {
        id: button1
        x: 371
        y: 84
        text: qsTr("Change")
        onClicked: displacement.set(textInput.text)
    }

    TextArea {
        id: textArea1
        x: 190
        y: 153
        text: speed.getValue()
    }

    TextArea {
        id: textArea2
        x: 190
        y: 204
        text: acceleration.getValue()
    }

    Text {
        id: element1
        x: 125
        y: 160
        text: qsTr("Speed")
        font.pixelSize: 12
    }

    Text {
        id: element2
        x: 108
        y: 211
        text: qsTr("Acceleration")
        font.pixelSize: 12
    }

    TextInput {
        id: textInput
        x: 209
        y: 97
        width: 80
        height: 20

        font.pixelSize: 12
    }
}
