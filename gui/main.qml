import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    function hpercent(ref,percent) { return (ref.height/100)*percent; }
    function wpercent(ref,percent) { return (ref.width/100)*percent; }
    function invalidLoginPopUp(){
        timePopUpLogin.start()
        popUpLogin.open()
    }

    id: root
    minimumHeight: 600 ; minimumWidth: 450
    visible: true
    title: "Nutron"
    color: "#333"
    Column{
        anchors.fill: parent
        StackView {
            id: stackPages
            height: hpercent(root,85)
            width: wpercent(root,100)
            initialItem: loginComponent
            onCurrentItemChanged: {
                if(_console.sessionOpen){
                    //                stackPages.push(userComponent)
                }
            }
        }
        DownBar{
            height: hpercent(root,15)
            width: wpercent(root,100)
        }
    }
    Component{
        id: loginComponent
        LoginPage{}
    }
    Component{
        id: registerComponent
        RegisterPage{}
    }
    PopUpWindow{
        id:popUpLogin
        rectHeight: hpercent(root,8)
        color: "#333"
        text: "Password or user invalid."
    }
    Timer {
        id: timePopUpLogin
        interval: 2500
        onTriggered: popUpLogin.closed()

    }
}
