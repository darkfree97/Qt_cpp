import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    color: "yellow"
    width: 320
    height: 240
    title: "Hello World"
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        text: qsTr("This application use QML and C++")
        anchors.centerIn: parent
    }
}
