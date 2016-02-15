import QtQuick 2.5
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4

Item {
    id:configPageRoot
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
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: hpercent(parent,30)
                text:title
            }
            MouseArea{
                anchors.fill: parent
                onClicked: console.log(title)
            }
        }
        model: ListModel {
            id:settingsModel
            ListElement { title:"Edit Profile"; type:"Account" }
            ListElement { title:"Vibration"; type:"Account" }
            ListElement { title:"Notifications"; type:"Account" }
            ListElement { title:"About Us"; type:"settings" }
            ListElement { title:"Logout"; type:"settings" }
        }
    }
}

