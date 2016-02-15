import QtQuick 2.5
import QtQuick.Controls 1.4

Item{
    id: login
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
        spacing: hpercent(this,30)
        Column{
            spacing: hpercent(this,30)
            TextLine{
                id: username
                placeholder: "Username"
                height: hpercent(parent.parent,12); width: wpercent(parent.parent,100)
                KeyNavigation.tab: password
                KeyNavigation.backtab: password
            }
            TextLine{
                id: password
                placeholder: "Password"
                password: true
                height: hpercent(parent.parent,12); width: wpercent(parent.parent,100)
                KeyNavigation.tab: username
                KeyNavigation.backtab: username
            }
        }
        Row{
            spacing: wpercent(parent,10)
            BButton{
                height: hpercent(root,13)
                width: wpercent(root,25)
                color: "white"
                text: "Login"
                action.onClicked: {
                    if(_console.login(username.text,password.text)) openSession()
                    else invalidLoginPopUp()
                }
            }
            BButton{
                height: hpercent(root,13)
                width: wpercent(root,25)
                color: "white"
                text: "Register"
                action.onClicked: stackPages.push(registerComponent)
            }
        }
    }
}

