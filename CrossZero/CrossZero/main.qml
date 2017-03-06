import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Window {
    id:window
    visible: true
    width: 640
    height: 480
    minimumHeight: 350
    minimumWidth: 480
    title: qsTr("CrossZero")

    MainForm {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        function checkWinner(player){
            if(button1.text === player){
                if(button2.text === player){
                    if(button3.text === player){
                        return true
                    }
                }
                if(button5.text === player){
                    if(button9.text === player){
                        return true
                    }
                }
                if(button4.text === player){
                    if(button7.text === player){
                        return true
                    }
                }
            }
            if(button3.text === player){
                if(button6.text === player){
                    if(button9.text === player){
                        return true
                    }
                }
                if(button5.text === player){
                    if(button7.text === player){
                        return true
                    }
                }
            }
            if(button5.text === player){
                if(button2.text === player){
                    if(button8.text === player){
                        return true
                    }
                }
                if(button4.text === player){
                    if(button6.text === player){
                        return true
                    }
                }
            }
            if(button7.text === player){
                if(button8.text === player){
                    if(button9.text === player){
                        return true
                    }
                }
            }
            if(button1.enabled === false){
                if(button2.enabled === false){
                    if(button3.enabled === false){
                        if(button4.enabled === false){
                            if(button5.enabled === false){
                                if(button6.enabled === false){
                                    if(button7.enabled === false){
                                        if(button8.enabled === false){
                                            if(button9.enabled === false){
                                                messageDialog.text = "No more winers)))"
                                                messageDialog.visible = true
                                                butActivator(false)
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return false
        }
        function butClear(){
            button1.text = ""
            button2.text = ""
            button3.text = ""
            button4.text = ""
            button5.text = ""
            button6.text = ""
            button7.text = ""
            button8.text = ""
            button9.text = ""
            image1.source = "qrc:/qtquickplugin/images/template_image.png"
            image2.source = "qrc:/qtquickplugin/images/template_image.png"
            image3.source = "qrc:/qtquickplugin/images/template_image.png"
            image4.source = "qrc:/qtquickplugin/images/template_image.png"
            image5.source = "qrc:/qtquickplugin/images/template_image.png"
            image6.source = "qrc:/qtquickplugin/images/template_image.png"
            image7.source = "qrc:/qtquickplugin/images/template_image.png"
            image8.source = "qrc:/qtquickplugin/images/template_image.png"
            image9.source = "qrc:/qtquickplugin/images/template_image.png"
        }
        function butActivator(activator){
            button1.enabled = activator
            button2.enabled = activator
            button3.enabled = activator
            button4.enabled = activator
            button5.enabled = activator
            button6.enabled = activator
            button7.enabled = activator
            button8.enabled = activator
            button9.enabled = activator
            button10.enabled = !activator
        }
        function checkStatus(){
            if(checkWinner("X")){
                messageDialog.text = "Winner X"
                messageDialog.visible = true
                butActivator(false)
            }
            else if(checkWinner("O")){
                messageDialog.text = "Winner O"
                messageDialog.visible = true
                butActivator(false)
            }
        }
        function setMove(button,image){
            if(f.active){
                button.text = "X"
                image.source = "X.png";
            }
            else{
                button.text = "O"
                image.source = "O.png";
            }
            button.enabled = false
            f.active = !f.active
            checkStatus()
        }

        button1.onClicked: function(){
            setMove(button1,image1);

        }
        button2.onClicked: function(){
            setMove(button2,image2);
        }
        button3.onClicked: function(){
            setMove(button3,image3);
        }
        button4.onClicked: function(){
            setMove(button4,image4);
        }
        button5.onClicked: function(){
            setMove(button5,image5);
        }
        button6.onClicked: function(){
            setMove(button6,image6);
        }
        button7.onClicked: function(){
            setMove(button7,image7);
        }
        button8.onClicked: function(){
            setMove(button8,image8);
        }
        button9.onClicked: function(){
           setMove(button9,image9);
        }
        button10.onClicked: function(){
            butClear()
            butActivator(true)
        }
        button11.onClicked: function(){
            window.close()
        }

        MessageDialog{
            id:messageDialog
            visible: false
            title: "Ура!!!"
        }
    }
}
