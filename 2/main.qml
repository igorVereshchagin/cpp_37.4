import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Styles 1.4

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Player")
    minimumWidth: 250
    RowLayout {
        id: layout
        spacing: 1
        anchors.bottom : parent.bottom
        Button {
            text: "▶️"
            Layout.preferredHeight: 40
            Layout.preferredWidth: 40
        }
        Button {
            text: "⏸️"
            Layout.preferredHeight: 40
            Layout.preferredWidth: 40
        }
        Button {
            text: "⏹"
            Layout.preferredHeight: 40
            Layout.preferredWidth: 40
        }
        Button {
            text: "⏪️"
            Layout.preferredHeight: 40
            Layout.preferredWidth: 40
        }
        Button {
            text: "⏩️"
            Layout.preferredHeight: 40
            Layout.preferredWidth: 40
        }
        ProgressBar {
            value: 0.5
            Layout.preferredWidth: parent.parent.width - x;
        }
    }
}
