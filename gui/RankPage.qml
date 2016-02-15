import QtQuick 2.5
import QtQuick.Controls 1.4
Item{
    Item {
        id:rootRank
        anchors.fill: parent
        Column {
            anchors.fill: parent
            Text {
                height:hpercent(parent,20); width: wpercent(parent,100);
                font { pixelSize: hpercent(this,33); bold:true }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text:"Ranking"; color:"#9E9E9E"
            }
            Item{
                height:hpercent(parent,20); width: wpercent(parent,100);
                Row{
                    anchors.fill: parent
                    Text {
                        height:hpercent(parent,100); width: wpercent(parent,50);
                        font { pixelSize: hpercent(this,33); }
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:"Name"; color:"#9E9E9E"
                    }Text {
                        height:hpercent(parent,100); width: wpercent(parent,50);
                        font { pixelSize: hpercent(this,33); }
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:"Score"; color:"#9E9E9E"
                    }
                }
            }

            ListView {
                height:hpercent(parent,60); width: wpercent(parent,100);
                model: _console.topTenUsers
                delegate: Item {
                    height:hpercent(rootRank,10); width: wpercent(parent,100);
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
