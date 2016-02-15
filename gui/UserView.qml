import QtQuick 2.5
import QtQuick.Controls 1.4

Item{
    Column{
        anchors.fill: parent
        Text {
            id: myScore
            height:hpercent(parent,20); width: wpercent(parent,100);
            font { pixelSize: hpercent(this,33); bold:true }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color:"#9E9E9E" ; text: _console.sessionOpen ? _console.currentUser.score : ""

        }
        Text {
            height:hpercent(parent,10); width: wpercent(parent,100);
            font { pixelSize: hpercent(this,33); bold:true }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color:"#9E9E9E"
            text: "Name: " + (_console.sessionOpen ? _console.currentUser.name : "")
        }
        Text {
            height:hpercent(parent,10); width: wpercent(parent,100);
            font { pixelSize: hpercent(this,33); bold:true }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color:"#9E9E9E"
            text: "Age: " + (_console.sessionOpen ? _console.currentUser.age : "")
        }
        ListView {
            height:hpercent(parent,40); width: wpercent(parent,100);
            model: _console.lastMeals
            delegate: Item {
                height:hpercent(userView,10); width: wpercent(userView,100);
                Row {
                    anchors.fill: parent
                    Text {
                        height:hpercent(parent,100); width: wpercent(parent,50);
                        font { pixelSize: hpercent(this,30) }
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color:"#9E9E9E"
                        text: name
                    }
                    Text {
                        height:hpercent(parent,100); width: wpercent(parent,50);
                        font { pixelSize: hpercent(this,30) }
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color:"#9E9E9E"
                        text: calorificvalue
                    }
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: wpercent(root,8)
            BButton{
                height: hpercent(root,13)
                width: wpercent(root,25)
                color: "white"
                text: "Add meal"
                //                    action.onClicked: stackPages.pop()
            }
            BButton{
                height: hpercent(root,13)
                width: wpercent(root,25)
                color: "white"
                text: _console.sessionOpen ? "Logout" : "Back"
                action.onClicked: {
                    if(_console.sessionOpen)
                        _console.logout()
                    closeSession()
                }
            }
        }
    }
}
