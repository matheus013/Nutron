import QtQuick 2.5
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4

Item {
    function invalidRegisterPopUp(message){
        popUpRegister.text = message
        popUpRegister.open()
        timePopUpRegister.start()

    }

    Text{
        height:hpercent(parent,20); width: wpercent(parent,100);
        font { pixelSize: hpercent(this,33); bold:true }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text:"Register Food"; color:"#9E9E9E"
    }

    Column{
        id: data
        anchors.centerIn: parent
        height: hpercent(root,50)
        width: wpercent(root,55)
        spacing: hpercent(this,10)
        TextLine{
            id: name
            placeholder: "Name"
            height: hpercent(parent,10)
            width: hpercent(parent,80)
        }
        TextLine{
            id: calorificvalue
            placeholder: "Calorific Value"
            height: hpercent(parent,10)
            width: hpercent(parent,80)
        }
        Row{
            height: hpercent(parent,20)
            width: wpercent(parent,100)
            Item {
                CheckBox{}
            }
            Item {
                CheckBox{}
            }
        }
        Row{
            spacing: wpercent(parent,8)
            BButton{
                height: hpercent(root,13)
                width: wpercent(root,25)
                color: "white"
                text: "Confirm"
                action.onClicked: {
                    _console.insertFood(name.text,calorificvalue.text)
                    invalidRegisterPopUp("Successfully registered food")
                    stackPages.pop()
                }
            }
            BButton{
                height: hpercent(root,13)
                width: wpercent(root,25)
                color: "white"
                text: "Cancel"
                action.onClicked: stackPages.pop()
            }
        }
    }
    PopUpWindow{
        id:popUpRegister
        rectHeight: hpercent(root,8)
        color: "#333"
    }
    Timer{
        id: timePopUpRegister
        interval: 2500
        onTriggered: popUpRegister.closed()
    }

}

