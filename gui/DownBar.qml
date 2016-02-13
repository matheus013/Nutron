import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    property color allcolor: "#333"
    property int elevation : 10
    Rectangle {
        anchors.fill:parent
        color: allcolor
        Row{
            ImageButton{
                height: hpercent(root,15)
                width: wpercent(root,20)
                color: allcolor
                image.source: "qrc:/img/icons/home153.png"
            }
            ImageButton{
                height: hpercent(root,15)
                width: wpercent(root,20)
                color: allcolor
                image.source: "qrc:/img/icons/home153.png"
            }
            ImageButton{
                height: hpercent(root,15)
                width: wpercent(root,20)
                color: allcolor
                image.source: "qrc:/img/icons/profile27.png"
            }
            ImageButton{
                height: hpercent(root,15)
                width: wpercent(root,20)
                color: allcolor
                image.source: "qrc:/img/icons/home153.png"
            }
            ImageButton{
                height: hpercent(root,15)
                width: wpercent(root,20)
                color: allcolor
                image.source: "qrc:/img/icons/home153.png"
            }
        }
    }

}
