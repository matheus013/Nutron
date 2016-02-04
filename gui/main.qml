import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    function hpercent(ref,percent) { return (ref.height/100)*percent; }
    function wpercent(ref,percent) { return (ref.width/100)*percent; }
    id: root
    height: 600 ; width: 450
    visible: true
    Column{
        anchors.fill: parent
        anchors.centerIn: parent
        spacing: hpercent(this,10)
        TextLine{
            placeholder: "username"
            validate: true
            height: hpercent(parent,10)
            width: hpercent(parent,50)
        }
        TextLine{
            placeholder: "password"
            password: true
            height: hpercent(parent,10)
            width: hpercent(parent,50)
        }
        TextLine{
            placeholder: "email"
            email: true
            height: hpercent(parent,10)
            width: hpercent(parent,50)
        }

    }
}
