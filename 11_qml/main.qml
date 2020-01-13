import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

import pl.gwizdz 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Displacement {
        id: displacement
    }

    Speed {
        id: speed
    }

    Acceleration {
        id: acceleration
    }

    GridLayout {

        anchors.fill: parent

        columns: 3
        rows: 3

        anchors.leftMargin: 10

        Label {
            Layout.row: 0
            Layout.column: 0
            text: qsTr("Displacement")
        }

        TextField {
            Layout.row: 0
            Layout.column: 1
            id: textField
            text: displacement.value
            focus: true
        }

        Button {
            Layout.row: 0
            Layout.column: 2
            text: "Change..."
            onClicked: displacement.value = textField.text
        }

        Label {
            Layout.row: 1
            Layout.column: 0
            text: qsTr("Speed")
        }

        Label {
            Layout.row: 1
            Layout.column: 1
            text: speed.value
            font.bold: true
        }

        Label {
            Layout.row: 2
            Layout.column: 0
            text: qsTr("Acceleration")
        }

        Label {
            Layout.row: 2
            Layout.column: 1
            text: acceleration.value
            font.bold: true
        }
    }
}
