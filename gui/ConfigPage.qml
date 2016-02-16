import QtQuick 2.5
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4

Item {
    id:configPageRoot
    property var online: _console.sessionOpen ? "Logout" : "Login"
    ListView {
        anchors { fill: parent; margins: hpercent(root,5) }
        spacing:hpercent(root,0.5)
        section.delegate: Rectangle {
            height: hpercent(root,10); width: wpercent(parent,100)
            color: "#09A"
            Text {
                anchors.centerIn: parent
                font.pixelSize: hpercent(parent,70)
                text:section
            }
        }
        section.property:"type"
        delegate: Rectangle {
            height: hpercent(configPageRoot,8); width: wpercent(parent,100)
            Text {
                id: textModel
                height: hpercent(parent,100)
                width: wpercent(parent,80)
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: hpercent(parent,30)
                text:title + ((title == "Log") ? (_console.sessionOpen  ? "out" : "in") : "")
            }
            Switch{
                enabled: isSwitch
                visible: isSwitch
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: textModel.right
            }
            MouseArea{
                enabled: !isSwitch
                anchors.fill: parent
                onClicked: {
                    switch (textModel.text) {
                    case "Edit Profile":
                        console.log(title)
                        break;
                    case "About Us":
                        console.log(1)
                        break;
                    case "Logout":
                        _console.logout()
                        break;
                    case "Login":
                        stackPages.push(loginComponent)
                        break;
                    }
                }
            }
        }
        model: ListModel {
            id:settingsModel
            ListElement { title:"Edit Profile"; type:"Settings" }
            ListElement { title:"Vibration"; type:"Settings"; isSwitch: true}
            ListElement { title:"Notifications"; type:"Settings"; isSwitch: true}
            ListElement { title:"About Us"; type:"Account" }
            ListElement { title: "Log"; type:"Account" }
        }
    }
}

