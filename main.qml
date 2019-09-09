import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0

ApplicationWindow {
    property var backgroundColor: "#151414"
    property var elementColor: "#e3601e"
    property var activeColor: "#636361"

    visible: true
    x:0; y:0;
    width: 920
    height: 708
    title: qsTr("Radio Record")
    color: backgroundColor

    ListModel {
        id: dataModel

        ListElement{ text: "Radio Record" }
        ListElement{ text: "Deep" }
        ListElement{ text: "Веснушка FM" }
        ListElement{ text: "Gold" }
        ListElement{ text: "Innocence" }
        ListElement{ text: "Маятник Фуко" }
    }

    GridView {
        id: view
        property int countColumns: Screen.width >= 920 ? 8 : 3
        anchors.margins: 10
        anchors.fill: parent
        cellHeight: (Screen.desktopAvailableWidth / countColumns) - (view.anchors.margins - (view.anchors.margins / 3))
        cellWidth: cellHeight
        model: dataModel
        clip: true

        delegate: SwipeDelegate {
            property var view: GridView.view
            property var isCurrent: GridView.isCurrentItem

            height: view.cellHeight
            width: view.cellWidth
            background: Rectangle{color: backgroundColor}

            Rectangle {
                id : circle
                color: backgroundColor
                anchors.margins: 10
                height: parent.height * 0.8
                width: parent.width * 0.8
                anchors.horizontalCenter: parent.horizontalCenter
                radius: parent.width
                border {
                    color: isCurrent ? elementColor : activeColor
                    width: 3
                }

                Image {
                    id: img
                    sourceSize.width: parent.width
                    sourceSize.height: parent.height
                    source: "qrc:/icons/%1.svg".arg(model.text)
                }

                ColorOverlay {
                    anchors.fill: img
                    source: img
                    color: isCurrent ? elementColor : activeColor  // make image like it lays under red glass
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        view.currentIndex = model.index
                        Chooser.setStation(model.text)
                    }
                }
            }

            Text {
                id: text
                anchors.top: circle.bottom
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                font.pointSize: 16
                horizontalAlignment: Text.AlignHCenter
                renderType: Text.NativeRendering
                //  text: "%1%2".arg(model.text).arg(isCurrent ? " * " : "")
                text: "%1".arg(model.text)
                color: isCurrent ? elementColor : activeColor
            }
        }
    }
}