import QtQuick 2.6
import QtQuick.Window 2.2
import "myfunction.js" as MyScripts

Rectangle {
    width: 320
    height: 240
    color: "#0cec57"
    gradient: Gradient {
        GradientStop {
            position: 0.02;
            color: "#0cec57";
        }
        GradientStop {
            position: 0.41;
            color: "#f8ff18";
        }
        GradientStop {
            position: 0.72;
            color: "#e8e799";
        }
        GradientStop {
            position: 0.95;
            color: "#ffffff";
        }
    }
    border.color: "#2512ee"
    Text {
        width: 70
        height: 16
        anchors.centerIn: parent
        text: qsTr("Hello QML")
        scale: 1
        anchors.verticalCenterOffset: -93
        anchors.horizontalCenterOffset: -106
        rotation: 0
        font.family: "Times New Roman"
        style: Text.Normal
        font.strikeout: false
        font.underline: false
        font.italic: true
        font.bold: true
    }
    MouseArea {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        onDoubleClicked:{
            Qt.quit();
        }
    }
}
