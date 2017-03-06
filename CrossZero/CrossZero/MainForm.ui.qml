import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Extras 1.4

Rectangle {
    id: rectangle1
    property alias image1: image1
    property alias image2: image2
    property alias image3: image3
    property alias image4: image4
    property alias image5: image5
    property alias image6: image6
    property alias image7: image7
    property alias image8: image8
    property alias image9: image9
    property alias button1: button1
    property alias button2: button2
    property alias button3: button3
    property alias button4: button4
    property alias button5: button5
    property alias button6: button6
    property alias button7: button7
    property alias button8: button8
    property alias button9: button9
    property alias button10: button10
    property alias button11: button11
    property alias f: statusIndicator1
    gradient: Gradient {
        GradientStop {
            position: 0.061
            color: "#990f55"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }

    Grid {
        id: grid1
        width: parent.height
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        Button {
            id: button1
            width: (grid1.width - 40)/3
            height: width
            text: qsTr("")
            clip: false
            enabled: false
            anchors.left: grid1.left
            anchors.leftMargin: 10
            anchors.top: grid1.top
            anchors.topMargin: 10

            Image {
                id: image1
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                z: 0
                source: "qrc:/qtquickplugin/images/template_image.png"
            }
        }

        Button {
            id: button2
            width: (grid1.width - 40)/3
            height: width
            enabled: false
            anchors.horizontalCenter: grid1.horizontalCenter
            anchors.top: grid1.top
            anchors.topMargin: 10

            Image {
                id: image2
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                source: "qrc:/qtquickplugin/images/template_image.png"
            }
        }

        Button {
            id: button3
            width: (grid1.width - 40)/3
            height: width
            enabled: false
            anchors.right: grid1.right
            anchors.rightMargin: 10
            anchors.top: grid1.top
            anchors.topMargin: 10

            Image {
                id: image3
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                source: "qrc:/qtquickplugin/images/template_image.png"
            }
        }

        Button {
            id: button4
            width: (grid1.width - 40)/3
            height: width
            enabled: false
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10

            Image {
                id: image4
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                source: "qrc:/qtquickplugin/images/template_image.png"
            }
        }

        Button {
            id: button5
            width: (grid1.width - 40)/3
            height: width
            enabled: false
            anchors.horizontalCenter: grid1.horizontalCenter
            anchors.verticalCenter: grid1.verticalCenter

            Image {
                id: image5
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                source: "qrc:/qtquickplugin/images/template_image.png"
            }
        }

        Button {
            id: button6
            width: (grid1.width - 40)/3
            height: width
            enabled: false
            anchors.right: grid1.right
            anchors.rightMargin: 10
            anchors.verticalCenter: grid1.verticalCenter

            Image {
                id: image6
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                source: "qrc:/qtquickplugin/images/template_image.png"
            }
        }

        Button {
            id: button7
            width: (grid1.width - 40)/3
            height: width
            enabled: false
            anchors.bottom: grid1.bottom
            anchors.bottomMargin: 10
            anchors.left: grid1.left
            anchors.leftMargin: 10

            Image {
                id: image7
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                source: "qrc:/qtquickplugin/images/template_image.png"
            }
        }

        Button {
            id: button8
            width: (grid1.width - 40)/3
            height: width
            enabled: false
            anchors.bottom: grid1.bottom
            anchors.bottomMargin: 10
            anchors.horizontalCenter: grid1.horizontalCenter

            Image {
                id: image8
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                source: "qrc:/qtquickplugin/images/template_image.png"
            }
        }

        Button {
            id: button9
            width: (grid1.width - 40)/3
            height: width
            enabled: false
            anchors.right: grid1.right
            anchors.rightMargin: 10
            anchors.bottom: grid1.bottom
            anchors.bottomMargin: 10

            Image {
                id: image9
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                source: "qrc:/qtquickplugin/images/template_image.png"
            }
        }

        Image {
            id: image0
            visible: true
            fillMode: Image.PreserveAspectCrop
            anchors.fill: parent
            z: -2
            source: "ubuntu_lucid-wallpaper-1366x768.jpg"
        }
    }

    Column {
        id: column1
        anchors.left: grid1.right
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

    }

    Button {
        id: button10
        x: 510
        text: qsTr("Грати")
        opacity: 0.8
        anchors.horizontalCenter: column1.horizontalCenter
        anchors.top: column1.top
        anchors.topMargin: 10
    }

    Button {
        id: button11
        x: 510
        y: 432
        text: qsTr("Вийти")
        opacity: 0.8
        anchors.bottom: column1.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: column1.horizontalCenter
    }

    StatusIndicator {
        id: statusIndicator1
        x: 547
        y: 227
        color: "#63ff00"
        anchors.verticalCenter: column1.verticalCenter
        anchors.horizontalCenter: column1.horizontalCenter
        active: true
    }
}
