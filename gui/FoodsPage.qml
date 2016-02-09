import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    Item{
        anchors.fill: parent
        Column{
            anchors.fill: parent
            TextLine{
                id: username
                placeholder: "Username"
                height: hpercent(parent,12)
                width: wpercent(parent,80)
            }

            ListView{
                height:hpercent(parent,60); width: wpercent(parent,100);
                model: _console.userList
                delegate: Item {
                    height:hpercent(parent,10); width: wpercent(parent,100);
                    Row {
                        anchors.fill: parent
                        Text {
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,30) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text:name
                        }
                        Text {
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,30) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text:score
                        }
                    }
                }
            }
        }
    }
}
