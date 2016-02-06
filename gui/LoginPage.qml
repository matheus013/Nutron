import QtQuick 2.5
import QtQuick.Controls 1.4

Item{
    Text{
        height:hpercent(parent,20); width: wpercent(parent,100);
        font { pixelSize: hpercent(this,33); bold:true }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text:"Login"; color:"#9E9E9E"
    }

    Column{
        id: data
        anchors.centerIn: parent
        height: hpercent(root,50)
        width: wpercent(root,55)
        spacing: hpercent(this,14)
        TextLine{
            id: username
            placeholder: "Username"
            height: hpercent(parent,12)
            width: hpercent(parent,80)
            KeyNavigation.tab: password
            KeyNavigation.backtab: password
        }
        TextLine{
            id: password
            placeholder: "Password"
            password: true
            height: hpercent(parent,12)
            width: hpercent(parent,80)
            KeyNavigation.tab: username
            KeyNavigation.backtab: username
        }
        Row{
            spacing: wpercent(parent,30)
            BButton{
                height: hpercent(root,13)
                width: height
                text: "Login"
                color: "#673AB7"
                radius: height/2
                action.onClicked: {
                    if(_console.login(username.text,password.text)){
                        stackPages.push(userComponent)
                    }else
                        invalidLoginPopUp()
                }
            }
            BButton{
                height: hpercent(root,13)
                width: height
                text: "Register"
                color: "#673AB7"
                radius: height/2
                action.onClicked: stackPages.push(registerComponent)
            }
        }
    }

    Component{
        id: registerComponent

        RegisterPage{}
    }
    Component{
        id: userComponent
        CurrPage{}
    }
}
