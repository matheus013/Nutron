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
    height: 800
    width: 480
    visible: true
    title: "Nutron"
    color: "#333"
    Column{
        anchors.fill: parent
        StackView {
            id: stackPages
            height: hpercent(root,85)
            width: wpercent(root,100)
//            initialItem: loginComponent
            initialItem: dietComponent
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
    Component{
        id: foodComponent
        FoodsPage{}
    }
    Component{
        id: rankPageComponent
        RankPage{}
    }
    Component{
        id: configComponent
        ConfigPage{}
    }
    Component{
        id: registerFoodComponent
        NewFoodPage{}
    }
    Component {
        id: dietComponent
        DietView{}
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
