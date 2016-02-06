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

    StackView {
        id: stackPages
        anchors.fill: parent
        initialItem: LoginPage{}
    }
}
