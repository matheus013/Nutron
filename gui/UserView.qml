import QtQuick 2.5
import QtQuick.Controls 1.4

Item{
    Column{
        anchors.fill: parent
        id: personModel
        Row {
            spacing: wpercent(parent,2)
            Image {
                id: name
                source: "https://image.freepik.com/icones-gratis/usuario-masculino-imagem-no-perfil_318-37825.jpg"
                height: hpercent(root,30)
                width: wpercent(root,30)
            }
            Column {
                anchors.verticalCenter: parent.verticalCenter
                Text {
                    height:hpercent(personModel,10); width: wpercent(personModel,50);
                    font { pixelSize: hpercent(this,33); bold:true }
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color:"#9E9E9E"
                    text: _console.currentUser.name
                }
                Text {
                    height:hpercent(personModel,10); width: wpercent(personModel,50);
                    font { pixelSize: hpercent(this,20); bold:true }
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color:"#9E9E9E"
                    text: "Score"
                }
                Text {
                    height:hpercent(personModel,10); width: wpercent(personModel,50);
                    font { pixelSize: hpercent(this,33) }
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignTop
                    color:"#9E9E9E"
                    text: _console.currentUser.score
                }
            }
        }
        ListView {
            height:hpercent(parent,40); width: wpercent(parent,100);
            model: _console.lastMeals
            delegate: Item {
                height:hpercent(userView,10); width: wpercent(userView,100);
                Row {
                    anchors.fill: parent
                    Text {
                        height:hpercent(parent,100); width: wpercent(parent,50);
                        font { pixelSize: hpercent(this,30) }
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color:"#9E9E9E"
                        text: name
                    }
                    Text {
                        height:hpercent(parent,100); width: wpercent(parent,50);
                        font { pixelSize: hpercent(this,30) }
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color:"#9E9E9E"
                        text: calorificvalue
                    }
                }
            }
        }
        Row{
            spacing: wpercent(parent,2)
            height: hpercent(root,8)
            anchors.horizontalCenter: parent.horizontalCenter
            BButton{
                height: hpercent(root,12)
                width: wpercent(root,30)
                color: "white"
                text: "Add meal"
            }
            BButton{
                height: hpercent(root,12)
                width: wpercent(root,30)
                color: "white"
                text: "Disease"
            }
        }
    }
}

