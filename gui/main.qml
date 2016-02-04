import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    function hpercent(ref,percent) { return (ref.height/100)*percent; }
    function wpercent(ref,percent) { return (ref.width/100)*percent; }
    id: root
    height: 600 ; width: 450
    visible: true
    title: "Nutron"
    color: "#333"
    Item{
        anchors.fill: parent
        Text{
            height:hpercent(parent,20); width: wpercent(parent,100);
            font { pixelSize: hpercent(this,33); bold:true }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text:"Register"; color:"#9E9E9E"
        }

        Column{
            anchors.centerIn: parent
            height: hpercent(root,50)
            width: wpercent(root,55)
            spacing: hpercent(this,14)
            TextLine{
                placeholder: "Name"
                height: hpercent(parent,12)
                width: hpercent(parent,80)
            }
            TextLine{
                placeholder: "Username"
                validate: true
                height: hpercent(parent,12)
                width: hpercent(parent,80)
            }
            TextLine{
                placeholder: "Password"
                password: true
                height: hpercent(parent,12)
                width: hpercent(parent,80)
            }
            TextLine{
                placeholder: "Email"
                email: true
                height: hpercent(parent,12)
                width: hpercent(parent,80)
            }
        }
    }
}
