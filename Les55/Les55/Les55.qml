import QtQuick 2.6
import QtQuick.Window 2.2

//Window {
//    visible: true
//    Text {
//        text: qsTr("Center")
//        anchors.centerIn: parent
//    }
//}


//Rectangle {
//    id: rectangle1
//    width: 360
//    height: 360
//    radius: 10
//    gradient: Gradient {
//        GradientStop {
//            position: 0
//            color: "#63ec2e"
//        }

//        GradientStop {
//            position: 0.719
//            color: "#0f9ed5"
//        }

//        GradientStop {
//            position: 1
//            color: "#000000"
//        }

//    }
//    Text {
//        text: qsTr("Centered")
//        anchors.fill: parent
//    }
//}

//Item {
//    id: item1
//    width: 360
//    height: 360
//    Rectangle {
//        id: yellowrect
//        opacity: 0.5
//        color: "yellow"
//        anchors.right: parent.horizontalCenter
//        anchors.rightMargin: -90
//        anchors.bottom: parent.verticalCenter
//        anchors.bottomMargin: -90
//        anchors.top: parent.top
//        anchors.left: parent.left
//    }
//    Rectangle {
//        opacity: 0.5
//        color: "blue"
//        anchors.leftMargin: -90
//        anchors.topMargin: -90
//        anchors.right: parent.right
//        anchors.left: parent.horizontalCenter
//        anchors.bottom: parent.bottom
//        anchors.top: parent.verticalCenter
//    }
//}
//Window {
//    width: 320
//    height: 240
//    Row {
//        id: row1
//        x: 0
//        y: 0
//        width: parent.width
//        height: parent.height
//        layoutDirection: Qt.RightToLeft
//        spacing: 0

//        Rectangle {
//            id: rectangle1
//            width: parent.width/3
//            height: parent.height
//            color: "#f10505"
//        }

//        Rectangle {
//            id: rectangle2
//            width: parent.width/3
//            height: parent.height
//            color: "#f3f9f3"
//        }

//        Rectangle {
//            id: rectangle3
//            width: parent.width/3
//            height: parent.height
//            color: "#0f0fbe"
//        }
//    }

//}
import QtQuick.Controls 1.5
Window {
    width: 320
    height: 240
    Image {
        id: image1
        fillMode: Image.Stretch
        anchors.fill: parent
        source: "1 (10).jpg"
        BusyIndicator {
            id : busy
            anchors.fill: parent
            running: false
        }
        Switch {
            checked: false
            activeFocusOnPress: false
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            onCheckedChanged: {
                busy.running = busy.running.valueOf()?false : true
            }
        }

    }
}
