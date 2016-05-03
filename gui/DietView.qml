import QtQuick 2.0

Item {
    Item {
        anchors.fill: parent

        Row {
            width: wpercent(root,100)
            height: hpercent(root,10)
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
