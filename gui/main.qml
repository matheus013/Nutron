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

    StackView {
        id: stackPages
        anchors.fill: parent
//        initialItem: LoginPage{}
        initialItem: FoodsPage{}
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
