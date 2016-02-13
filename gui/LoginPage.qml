import QtQuick 2.5
import QtQuick.Controls 1.4

Item{
    state: _console.sessionOpen ? "online" : "offline"
    function openSession(){
        state = "online"
    }

    function closeSession(){
        state = "offline"
    }
    states: [
        State {
            name: "offline"
            PropertyChanges { target: login ; visible: true }
            PropertyChanges { target: userView ; visible: false }
        },
        State {
            name: "online"
            PropertyChanges { target: login ; visible: false }
            PropertyChanges { target: userView ; visible: true }
        }
    ]

    Item{
        id: userView
        anchors.fill: parent
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
                    height:hpercent(userView,10); width: wpercent(r,100);
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
                    height: hpercent(root,10)
                    width: wpercent(root,20)
                    radius: 10
                    text: "Add meal"
                    color: "#673AB7"
                    //                    action.onClicked: stackPages.pop()
                }
                BButton{
                    height: hpercent(root,10)
                    width: wpercent(root,20)
                    radius: 10
                    text: _console.sessionOpen ? "Logout" : "Back"
                    color: "#673AB7"
                    action.onClicked: {
                        if(_console.sessionOpen)
                            _console.logout()
                        closeSession()
                    }
                }
            }
        }
    }

    Item{
        id: login
        anchors.fill: parent
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
                width: wpercent(parent,100)
                KeyNavigation.tab: password
                KeyNavigation.backtab: password
            }
            TextLine{
                id: password
                placeholder: "Password"
                password: true
                height: hpercent(parent,12)
                width: wpercent(parent,100)
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
                            openSession()
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
    }
}
