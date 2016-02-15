import QtQuick 2.5
import QtQuick.Controls 1.4

Item{
    function openSession(){ stackViews.push(userViewComponent) }
    function closeSession(){ stackViews.pop() }
    StackView {
        id:stackViews
        clip: true
        anchors.fill: parent
        initialItem: loginViewComponent
        delegate:StackViewDelegate {
            function getTransition(properties) {
                return (properties.enterItem.Stack.index % 2) ? horizontalTransition : verticalTransition
            }
            function transitionFinished(properties) {
                properties.exitItem.x = 0
                properties.exitItem.y = 0
            }
            property Component horizontalTransition: StackViewTransition {
                PropertyAnimation {
                    target: enterItem
                    property: "x"
                    from: target.width
                    to: 0
                    duration: 300
                }
                PropertyAnimation {
                    target: exitItem
                    property: "x"
                    from: 0
                    to: target.width
                    duration: 300
                }
            }
            property Component verticalTransition: StackViewTransition {
                PropertyAnimation {
                    target: enterItem
                    property: "y"
                    from: target.height
                    to: 0
                    duration: 300
                }
                PropertyAnimation {
                    target: exitItem
                    property: "y"
                    from: 0
                    to: target.height
                    duration: 300
                }
            }
        }
    }
    Component {
        id:loginViewComponent
        LoginView {}
    }
    Component {
        id:userViewComponent
        UserView {}
    }
}
