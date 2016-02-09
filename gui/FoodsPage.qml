import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    Item{
        anchors.fill: parent
        Text {
            height:hpercent(parent,20); width: wpercent(parent,100);
            font { pixelSize: hpercent(this,33); bold:true }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text:"Meals"; color:"#9E9E9E"
        }
        Column{
            anchors.centerIn: parent
            height: hpercent(root,50)
            width: wpercent(root,55)
            spacing: hpercent(this,5)

            TextLine{
                id: username
                placeholder: "Search"
                height: hpercent(parent,12)
                width: wpercent(parent,100)
                event.onTextChanged: {
                    if(text.length > 0 ) {
                        model.applyFilter(text);
                    } else {
                        model.reload();
                    }
                }
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
                        text:"Calorific Value"; color:"#9E9E9E"
                    }
                }
            }
            ListView{
                id: foodView
                height:hpercent(parent,50); width: wpercent(parent,100);
                model: _console.foodList
                focus: true
                delegate: Item {
                    height:hpercent(root,8); width: wpercent(parent,100);
                    Component.onCompleted: console.log(name)
                    Row {
                        anchors.fill: parent
                        Text {
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,40) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text:name
                        }
                        Text {
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,40) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text:calorificvalue
                        }
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            currentFood.selectFood = name
                            _console.selectFood(food_id)
                        }
                    }
                }
            }
            Text {
                id: currentFood
                property string selectFood: ""
                text: "Selected: " + selectFood
                height:hpercent(parent,30); width: wpercent(parent,100);
                font { pixelSize: hpercent(this,30) }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color:"#9E9E9E"
            }
        }
    }
}
