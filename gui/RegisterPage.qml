import QtQuick 2.5
import QtQuick.Controls 1.4

Item{
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
        text:"Register"; color:"#9E9E9E"
    }

    Column{
        id: data
        anchors.centerIn: parent
        height: hpercent(root,50)
        width: wpercent(root,55)
        spacing: hpercent(this,14)
        TextLine{
            id: name
            placeholder: "Name"
            height: hpercent(parent,12)
            width: hpercent(parent,80)
        }
        TextLine{
            id: username
            placeholder: "Username"
            validate: true
            height: hpercent(parent,12)
            width: hpercent(parent,80)
        }
        TextLine{
            id: password
            placeholder: "Password"
            password: true
            height: hpercent(parent,12)
            width: hpercent(parent,80)
        }
        TextLine{
            id: email
            placeholder: "Email"
            email: true
            height: hpercent(parent,12)
            width: hpercent(parent,80)
        }
        Row{
            spacing: wpercent(parent,30)
            BButton{
                height: hpercent(root,13)
                width: height
                text: "Confirm"
                color: "#673AB7"
                radius: height/2
                action.onClicked: {
                    if(username.text == "" || password.text == "" || name.text == "" || email.text == "")
                        invalidRegisterPopUp("Empty fields.")
                    else {
                        if(username.isValid && email.isValid && username.text + password.text +
                                name.text + email.text != ""){
                            _console.insertUser(username.text, password.text, name.text, email.text)
                            stackPages.pop()
                        }
                        if(!_authenticate.usernameValid(username.text) &&
                                (!_authenticate.emailValid(email.text) ||
                                 !_authenticate.isEmailAddress(email.text)))
                            invalidRegisterPopUp("Invalid user and email.")
                        else if(!_authenticate.usernameValid(username.text))
                            invalidRegisterPopUp("Invalid user.")
                        else if(!_authenticate.emailValid(email.text))
                            invalidRegisterPopUp("Invalid email.")
                    }
                }
            }
            BButton{
                height: hpercent(root,13)
                width: height
                text: "Cancel"
                color: "#673AB7"
                radius: height/2
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
