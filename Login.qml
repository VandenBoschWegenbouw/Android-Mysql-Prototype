import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Window 2.13
import QtQuick.Layouts 1.3

Page {
    id: wndLogin
    visible: true
    width: 640
    height: 480
    title: qsTr("Login")

    anchors.centerIn: parent

    TextField {
        id: tfUsername
        x: 100
        y: 153
        anchors.verticalCenterOffset: -50
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        placeholderText: qsTr("Gebruikersnaam")
        onTextChanged: loginHandler.username = text
    }


    TextField {
        id: tfPassword
        x: 100
        y: 157
        echoMode: TextInput.Password
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenterOffset: 0
        placeholderText: qsTr("Wachtwoord")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        onTextChanged: loginHandler.password = text
    }

    Button {
        id: btnLogin
        width: 200
        text: qsTr("Login")
        anchors.verticalCenterOffset: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        onClicked: loginHandler.login();
    }



}


