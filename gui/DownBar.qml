import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    property int elevation : 10
    Item {
        id:backRect
        height: hpercent(parent,90)
        width: wpercent(parent,98)
        anchors.centerIn: parent
        Row{
            spacing: wpercent(backRect,6.25)
            ImageButton{
                height: hpercent(backRect,90)
                width: wpercent(backRect,15)
                radius: 10
                color: "#FFF"
                image.source: "qrc:/img/icons/home166.png"
                action.onClicked: stackPages.push(rankPageComponent)
            }
            ImageButton{
                height: hpercent(backRect,90)
                width: wpercent(backRect,15)
                radius: 10
                color: "#FFF"
                image.source: "qrc:/img/icons/food7.png"
                action.onClicked: stackPages.push(foodComponent)
            }
            ImageButton{
                height: hpercent(backRect,90)
                width: wpercent(backRect,15)
                radius: 10
                color: "#FFF"
                image.source: "qrc:/img/icons/profile29.png"
                action.onClicked: {
                    stackPages.push(loginComponent)
                }
            }
            ImageButton{
                height: hpercent(backRect,90)
                width: wpercent(backRect,15)
                radius: 10
                color: "#FFF"
                image.source: "qrc:/img/icons/body-parts71.png"
            }
            ImageButton{
                height: hpercent(backRect,90)
                width: wpercent(backRect,15)
                radius: 10
                color: "#FFF"
                image.source: "qrc:/img/icons/setting5.png"
                action.onClicked: stackPages.push(configComponent)
            }
        }
    }

}
