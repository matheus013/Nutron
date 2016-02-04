import QtQuick 2.0

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
            text:"Ranking"; color:"#242424"
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
                    text:"Name"; color:"#242424"
                }Text {
                    height:hpercent(parent,100); width: wpercent(parent,50);
                    font { pixelSize: hpercent(this,33); }
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text:"Score"; color:"#242424"
                }
            }
        }

        ListView {
            height:hpercent(parent,60); width: wpercent(parent,100);
            model: _console.userList
            delegate: Item {
                height:hpercent(rootRank,10); width: wpercent(parent,100);
                Row {
                    anchors.fill: parent
                    Text {
                        height:hpercent(parent,100); width: wpercent(parent,50);
                        font { pixelSize: hpercent(this,30) }
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:name
                    }
                    Text {
                        height:hpercent(parent,100); width: wpercent(parent,50);
                        font { pixelSize: hpercent(this,30) }
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:score
                    }
                }
            }
        }
    }
}
