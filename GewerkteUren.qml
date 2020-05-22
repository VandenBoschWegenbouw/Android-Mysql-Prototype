import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3


Page {
    id: page
    width: 640
    height: 480
    title: "Gewerkte uren"


    GewerkteUrenList {
        anchors.centerIn: parent
    }
}
