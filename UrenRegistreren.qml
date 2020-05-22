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
        anchors.verticalCenterOffset: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        onClicked: urenHandler.addHours()
    }

    SpinBox {
        id: spinBox
        x: 130
        y: 134
        to: 10
        anchors.verticalCenterOffset: -50
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        onValueChanged: urenHandler.hoursWorked = value
    }
}

