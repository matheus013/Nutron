import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Item{
    Column{
        anchors.fill: parent
        id: personModel
        spacing: hpercent(parent, 5)

        Column {
            width: wpercent(parent, 100)
            spacing: hpercent(parent, 8)
            TextLine {
                id: name
                anchors.horizontalCenter: parent.horizontalCenter
                placeholder: "Name"
                height:hpercent(personModel,10); width: wpercent(personModel,50);
                text: _console.currentUser.name
            }
            TextLine {
                id: age
                anchors.horizontalCenter: parent.horizontalCenter
                placeholder: "Age"
                height:hpercent(personModel,10); width: wpercent(personModel,50);
                text: _console.currentUser.age
            }
            TextLine {
                id: weight
                anchors.horizontalCenter: parent.horizontalCenter
                placeholder: "Weight"
                height:hpercent(personModel,10); width: wpercent(personModel,50);
                text: _console.currentUser.weight
            }
            TextLine {
                id: height
                anchors.horizontalCenter: parent.horizontalCenter
                placeholder: "Height"
                height:hpercent(personModel,10); width: wpercent(personModel,50);
                text: _console.currentUser.height
            }
        }
        Row{
            spacing: wpercent(parent,2)
            height: hpercent(root,8)
            anchors.horizontalCenter: parent.horizontalCenter
            BButton{
                height: hpercent(root,8)
                width: wpercent(root,25)
                color: "white"
                text: "Salvar"
                action.onClicked: {
                    _console.update(name.text,age.text,weight.text,height.text)
                    invalidRegisterPopUp("Sucess update!")

                    stackPages.pop()
                }
            }
        }
    }
}

