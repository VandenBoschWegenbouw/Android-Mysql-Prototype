import QtQuick 2.14
import QtQuick.Controls 2.14

ApplicationWindow {
    id: wndMain
    visible: true
    width: 640
    height: 480
    property alias svItems: svItems
    title: qsTr("Stack")

    Component.onCompleted: {
        header.visible = false;
        drawer.visible = false;
    }

    header: ToolBar {
        id: header
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: svItems.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (svItems.depth > 1) {
                    svItems.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: svItems.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: wndMain.width * 0.66
        height: wndMain.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Gewerkte uren")
                width: parent.width
                onClicked: {
                    svItems.replace("GewerkteUren.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Uren registreren")
                width: parent.width
                onClicked: {
                    svItems.replace("UrenRegistreren.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: svItems
        anchors.fill: parent
        anchors.bottom: parent.bottom
        initialItem: "Login.qml"
        focus: true
    }

    Connections {
        target: loginHandler
        onLogUserIn: {
            svItems.replace("GewerkteUren.qml")
            header.visible = true;

        }
    }

}
