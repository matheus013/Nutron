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
                image.source: "qrc:/img/icons/home166.png"
            }
            ImageButton{
                height: hpercent(root,15)
                width: wpercent(root,20)
                color: allcolor
                image.source: "qrc:/img/icons/food7.png"
            }
            ImageButton{
                height: hpercent(root,15)
                width: wpercent(root,20)
                color: allcolor
                image.source: "qrc:/img/icons/profile29.png"
            }
            ImageButton{
                height: hpercent(root,15)
                width: wpercent(root,20)
                color: allcolor
                image.source: "qrc:/img/icons/exercise83.png"
            }
            ImageButton{
                height: hpercent(root,15)
                width: wpercent(root,20)
                color: allcolor
                image.source: "qrc:/img/icons/setting5.png"
            }
        }
    }

}
