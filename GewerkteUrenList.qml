import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import WorkedHours 1.0

ColumnLayout {
    Frame {
        Layout.fillWidth: true

        ListView {
            implicitWidth: 250
            implicitHeight: 250
            anchors.fill: parent
            clip: true

            model: WorkedHoursModel {
                list: workedHoursList
            }

            delegate: RowLayout {
                width: parent.width

                Label {
                    text: model.company
                }
                Label {
                    text: model.project
                }
                Label {
                    text: model.hours + " UUR"
                }
            }
        }
    }
}
