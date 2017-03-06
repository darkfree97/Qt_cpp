import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 440
    height: 280
    title: qsTr("Рядок і цифри")
    FileDialog {
        id : file
    }
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }
    TextField {
        id:lineEdit
        anchors.right: parent.right
        anchors.rightMargin: 100
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left;
    }

    Button {
        id: button1
        height: 21
        text: qsTr("Гаразд")
        antialiasing: false
        clip: false
        anchors.left: lineEdit.right
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        onClicked: function (){
            var str = lineEdit.text.toString();
            var n = 0;
            for (var i=0;i<str.length;i++){
                if(str[i]>=0&&str[i]<=9)
                    n++;
            }
            textArea1.text = qsTr("В рядку ")+n+qsTr(" цифр!");
        }
    }

    TextArea {
        id: textArea1
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.top: lineEdit.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
    }
}
