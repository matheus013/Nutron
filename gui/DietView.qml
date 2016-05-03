import QtQuick 2.0

Item {
    Item {
        id: rootDiet
        anchors.fill: parent
        Column{
            anchors.fill: parent
            Row {
                width: wpercent(parent,100)
                height: hpercent(parent,10)
                Item {
                    height:hpercent(rootDiet,10); width: wpercent(parent,100/7);
                    Item{
                        anchors.fill: parent
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,15) ; bold: true}
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: "Sunday"
                        }
                    }
                }
                Item {
                    height:hpercent(rootDiet,10); width: wpercent(parent,100/7);
                    Item{
                        anchors.fill: parent
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,15) ; bold: true}
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: "Monday"
                        }
                    }
                }
                Item {
                    height:hpercent(rootDiet,10); width: wpercent(parent,100/7);
                    Item{
                        anchors.fill: parent
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,15) ; bold: true}
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: "Tuesday"
                        }
                    }
                }
                Item {
                    height:hpercent(rootDiet,10); width: wpercent(parent,100/7);
                    Item{
                        anchors.fill: parent
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,15) ; bold: true}
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: "Wednesday"
                        }
                    }
                }
                Item {
                    height:hpercent(rootDiet,10); width: wpercent(parent,100/7);
                    Item{
                        anchors.fill: parent
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,15) ; bold: true}
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: "Thursday"
                        }
                    }
                }
                Item {
                    height:hpercent(rootDiet,10); width: wpercent(parent,100/7);
                    Item{
                        anchors.fill: parent
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,15) ; bold: true}
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: "Friday"
                        }
                    }
                }
                Item {
                    height:hpercent(rootDiet,10); width: wpercent(parent,100/7);
                    Item{
                        anchors.fill: parent
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,15) ; bold: true}
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: "Saturday"
                        }
                    }
                }






            }

            Row {
                width: wpercent(parent,100)
                height: hpercent(parent,80)
                anchors.horizontalCenter: parent.horizontalCenter
                ListView {
                    height:hpercent(parent,100); width: wpercent(parent,100/7);
                    model: _console.diet.sunday
                    delegate: Item {
                        height:hpercent(rootDiet,10); width: wpercent(parent,100);
                        Item{
                            anchors.fill: parent
                            Text {
                                anchors.centerIn: parent
                                height:hpercent(parent,100); width: wpercent(parent,50);
                                font { pixelSize: hpercent(this,20) }
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color:"#9E9E9E"
                                text: name
                            }
                        }
                    }
                }
                ListView {
                    height:hpercent(parent,100); width: wpercent(parent,100/7);
                    model: _console.diet.monday
                    delegate: Item {
                        height:hpercent(rootDiet,10); width: wpercent(parent,100);
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,20) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: name
                        }
                    }
                }
                ListView {
                    height:hpercent(parent,100); width: wpercent(parent,100/7);
                    model: _console.diet.tuesday
                    delegate: Item {
                        height:hpercent(rootDiet,10); width: wpercent(parent,100);
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,20) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: name
                        }
                    }
                }
                ListView {
                    height:hpercent(parent,100); width: wpercent(parent,100/7);
                    model: _console.diet.wednesday
                    delegate: Item {
                        height:hpercent(rootDiet,10); width: wpercent(parent,100);
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,20) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: name
                        }
                    }
                }
                ListView {
                    height:hpercent(parent,100); width: wpercent(parent,100/7);
                    model: _console.diet.thursday
                    delegate: Item {
                        height:hpercent(rootDiet,10); width: wpercent(parent,100);
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,20) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: name
                        }
                    }
                }
                ListView {
                    height:hpercent(parent,100); width: wpercent(parent,100/7);
                    model: _console.diet.friday
                    delegate: Item {
                        height:hpercent(rootDiet,10); width: wpercent(parent,100);
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,20) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: name
                        }
                    }
                }
                ListView {
                    height:hpercent(parent,100); width: wpercent(parent,100/7);
                    model: _console.diet.saturday
                    delegate: Item {
                        height:hpercent(rootDiet,10); width: wpercent(parent,100);
                        Text {
                            anchors.centerIn: parent
                            height:hpercent(parent,100); width: wpercent(parent,50);
                            font { pixelSize: hpercent(this,20) }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color:"#9E9E9E"
                            text: name
                        }
                    }
                }

            }

            Row {
                width: wpercent(parent,100)
                height: hpercent(parent,10)
                spacing: wpercent(parent,2)
                Item {
                    height: hpercent(parent,100)
                    width: wpercent(parent,50)
                    BButton {
                        anchors.centerIn: parent
                        height: hpercent(parent,80)
                        width: wpercent(parent,40)
                        color: "white"
                        text: "Build Diet"
                        action.onClicked: {
                            _console.buildDiet()
                        }
                    }
                }
                Item {
                    height: hpercent(parent,100)
                    width: wpercent(parent,50)
                    BButton {
                        anchors.centerIn: parent
                        height: hpercent(parent,80)
                        width: wpercent(parent,40)
                        color: "white"
                        text: "Back"
                        action.onClicked: {
                            stackPages.pop()
                        }
                    }
                }
            }
        }
    }
}
