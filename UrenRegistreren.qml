import QtQuick 2.4
import QtQuick.Controls 2.12

Page {
    id: page
    width: 640
    height: 480
    property alias spinBox: spinBox
    property alias btnAddHours: btnAddHours
    title: "Uren registreren"

    Button {
        id: btnAddHours
        text: qsTr("Voeg uren toe")
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenterOffset: 144
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        onClicked: urenHandler.addHours()

    }

    SpinBox {
        id: spinBox
        x: 130
        y: 134
        anchors.horizontalCenterOffset: -27
        to: 10
        anchors.verticalCenterOffset: 5
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        onValueChanged: urenHandler.hoursWorked = value
    }

    ComboBox {
        id: cbSelectProject
        x: 223
        y: 101
        width: 194
        height: 29
        currentIndex: 0
        textRole: "Project"
        model: ListModel {
            ListElement{
                text: "Project 1"
            }
            ListElement{
                text: "Project 2"
            }
        }
    }

    ComboBox {
        id: cbSelectKlant
        x: 223
        y: 159
        width: 194
        height: 30
        textRole: "Klant"
        model: ListModel {
            ListElement{
                text: "Klant 1"
            }
            ListElement{
                text: "Klant 2"
            }
        }
    }

    TextArea {
        id: textArea
        x: 223
        y: 276
        width: 194
        height: 72
        text: "Opmerkingen"
        placeholderText: qsTr("Text Area")
    }

    Label {
        id: label
        x: 223
        y: 71
        width: 194
        height: 24
        text: qsTr("Project")
        leftPadding: 0
        rightPadding: 0
        font.weight: Font.Light
        font.pointSize: 16
    }

    Label {
        id: label1
        x: 223
        y: 136
        width: 194
        height: 24
        text: qsTr("Klant")
        font.pointSize: 16
        rightPadding: 0
        leftPadding: 0
        font.weight: Font.Light
    }

    Label {
        id: label2
        x: 223
        y: 195
        width: 194
        height: 24
        text: qsTr("Uren")
        font.pointSize: 16
        rightPadding: 0
        leftPadding: 0
        font.weight: Font.Light
    }
}

