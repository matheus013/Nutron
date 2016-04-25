import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    id: rootFood
    Item{
        anchors.fill: parent
        Column{
            anchors.fill: parent
            Text {
                height:hpercent(parent,20); width: wpercent(parent,100);
                font { pixelSize: hpercent(this,33); bold:true }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text:"Foods"; color:"#9E9E9E"
            }
            Item {
                height: hpercent(parent,80)
                width: wpercent(parent,100)
                Column{
                    height: hpercent(parent,60)
                    width: wpercent(parent,100)
                    spacing: hpercent(this,5)

                    TextLine{
                        id: username
                        anchors.horizontalCenter: parent.horizontalCenter
                        placeholder: "Search"
                        height: hpercent(parent,12)
                        width: wpercent(parent,80)
                        event.onTextChanged:
                            (text.length > 0 ) ? model.applyFilter(text): model.reload();

                    }
                    Item {
                        height:hpercent(rootFood,15); width: wpercent(rootFood,100);
                        Row{
                            anchors.fill: parent
                            Item{
                                height: hpercent(parent,100)
                                width: wpercent(parent,50)
                                Text {
                                    anchors.centerIn: parent
                                    height:hpercent(parent,30); width: wpercent(parent,100);
                                    font { pixelSize: hpercent(this,80); }
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    text:"Name"; color:"#9E9E9E"
                                }
                            }
                            Item{
                                height: hpercent(parent,100)
                                width: wpercent(parent,50)
                                Text {
                                    anchors.centerIn: parent
                                    height:hpercent(parent,20); width: wpercent(parent,100);
                                    font { pixelSize: hpercent(this,70); }
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    text:"Calorific Value"; color:"#9E9E9E"
                                }
                            }
                        }
                    }
                    Item{
                        height:hpercent(parent,70); width: wpercent(parent,100);
                        ListView {
                            id: foodView
                            model: _console.foodList
                            focus: true
                            clip: true
                            anchors.fill: parent
                            delegate: Item {
                                height:hpercent(foodView,20); width: wpercent(parent,100);
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
                    }
                    BButton {
                        height: hpercent(parent,20) ; width: wpercent(parent,25)
                        color: "white"
                        text: "Register Food"
                        anchors.horizontalCenter: parent.horizontalCenter
                        action.onClicked: stackPages.push(registerFoodComponent)
                    }
                }
            }
        }
    }
}
