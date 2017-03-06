import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

//Rectangle {
//    width: 320
//    height: 240
//    color: mousearea.containsMouse ? "lightgreen" : "yellow"
//    Text {
//        anchors.centerIn: parent
//        text: "<h1><center>Click Me!<br>(use left or right mouse button)</center></h1>"
//    }
//    MouseArea {
//        id: mousearea
//        hoverEnabled: true
//        anchors.fill: parent
//        acceptedButtons: Qt.LeftButton | Qt.RightButton
//        onPressed: {
//            if(mouse.button == Qt.RightButton){
//                parent.color = "red"
//            }
//            else {
//                parent.color = "blue"
//            }
//        }
//        onReleased: {
//            parent.color = "lightgreen"
//        }
//    }
//}

//Rectangle {
//    width: 300
//    height: 150

//    signal mousePositionChanged(real x,real y)

//    onMousePositionChanged: {
//        txt.text = "<h1>X = "+x+"<br>Y = "+y+"</h1>"
//    }
//    Text {
//        id: txt
//        text: qsTr("Move the mouse!")
//        anchors.centerIn: parent
//    }
//    MouseArea {
//        anchors.fill: parent
//        hoverEnabled: true
//        onMouseXChanged: parent.mousePositionChanged(mouseX,mouseY)
//        onMouseYChanged: parent.mousePositionChanged(mouseX,mouseY)
//    }

//}

//Item {
//    id: item
//    width: 150
//    height: 100
//    Button {
//        anchors.fill: parent
//        text: "Please click me"
//        onClicked:
//            text = "Clicked!"
//    }
//}

ApplicationWindow {
    height: 240
    width: 320
    visible: true
}
