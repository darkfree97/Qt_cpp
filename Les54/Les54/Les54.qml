import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.1

//Item {
//    id : stena
//    width: 360
//    height: 360
//    Rectangle{
//        id : redrect
//        x : 0
//        y : 0
//        width: stena.width/2
//        height: stena.height/2
//        gradient: Gradient {
//            GradientStop {
//                position: 0
//                color: "#ea2c2c"
//            }

//            GradientStop {
//                position: 1
//                color: "#400303"
//            }
//        }
//    }
//    Rectangle{
//        id : greenrect
//        x : redrect.width
//        y : redrect.height
//        width: redrect.width
//        height: redrect.height
//        gradient: Gradient {
//            GradientStop {
//                position: 0
//                color: "#27f727"
//            }

//            GradientStop {
//                position: 1
//                color: "#000000"
//            }
//        }
//    }
//}

//Item {
//    width: 200
//    height: 200
//    Item {
//        id: myelement
//        property string name: "My Element"
//        property int ver: 1
//        property real pi: 3.14159
//        property bool condition: true
//        property url link: "http://google.com"
//    }
//    Text {
//        id: viewItem
//        text: myelement.name + "<br>"+
//              myelement.ver + "<br>"+
//              myelement.pi + "<br>"+
//              myelement.condition + "<br>"+
//              myelement.link
//    }
//}

//ApplicationWindow {
//    width: 320
//    height: 240
//    visible: true
//    title: "One Button"
//    Button {
//        text: "&Quit"
//        width: parent.width
//        height: parent.height
//        onClicked: Qt.quit();
//    }
//}

//ApplicationWindow {
//    visible: true
//    width: 200
//    height: 75
//    title: "Controls"

//    menuBar: MenuBar {
//        Menu {
//            title: "&File"
//            MenuItem {
//                text: "&Quit"
//                onTriggered: Qt.quit()
//            }
//        }
//    }
//    ProgressBar {
//        x:0
//        y:0
//        width: parent.width
//        height: parent.height/2
//        value: slider.value
//    }
//    Slider {
//        id : slider
//        x:0
//        y:parent.height/2
//        width: parent.width
//        height: parent.height/2
//        value: 0.75
//        tickmarksEnabled: true
//        stepSize: 0.1
//    }
//}


ApplicationWindow {
    width: 200
    height: 100
    visible: true
    title: "Dialogs Demo"
    Button {
        width: parent.width
        height: parent.height
        text: "Click to &start a color dialog"
        onClicked: {
            messageDialog.visible = false;
            colorDialog.visible = true;
        }

    }

    ColorDialog {
        id : colorDialog
        color : "blue"
        onAccepted : {
            messageDialog.informativeText = "Selected color = "+ color
            messageDialog.visible = true
        }
    }
    MessageDialog {
        id : messageDialog
    }
}

