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
        ListElement{ text: "Electro"}
        ListElement{ text: "Midtempo"}
        ListElement{ text: "Bass House"}
        ListElement{ text: "Progressive"}
        ListElement{ text: "Synthwave"}
        ListElement{ text: "House Hits"}
        ListElement{ text: "Big Hits"}
        ListElement{ text: "Dream Dance"}
        ListElement{ text: "Darkside"}
        ListElement{ text: "Uplifting"}
        ListElement{ text: "House Classics"}
        ListElement{ text: "EDM Hits"}
        ListElement{ text: "Neurofunk"}
        ListElement{ text: "Tecktonik"}
        ListElement{ text: "2-step"}
        ListElement{ text: "Trance Hits"}
        ListElement{ text: "Rap Hits"}
        ListElement{ text: "Rap Classics"}
        ListElement{ text: "Cadillac"}
        ListElement{ text: "1980-е"}
        ListElement{ text: "Chill House"}
        ListElement{ text: "1970-е"}
        ListElement{ text: "Complextro"}
        ListElement{ text: "Groove Tribal"}
        ListElement{ text: "Russian Hits"}
        ListElement{ text: "Megamix"}
        ListElement{ text: "Jungle"}
        ListElement{ text: "Liquid Funk"}
        ListElement{ text: "Drum'n'Bass Hits"}
        ListElement{ text: "Russian Gold"}
        ListElement{ text: "Eurodance"}
        ListElement{ text: "Technopop"}
        ListElement{ text: "Disco Func"}
        ListElement{ text: "EDM"}
        ListElement{ text: "Tropical"}
        ListElement{ text: "GOA PSY"}
        ListElement{ text: "Future House"}
        ListElement{ text: "Trancemission"}
        ListElement{ text: "Chill-Out"}
        ListElement{ text: "Minimal Tech"}
        ListElement{ text: "Pirate Station"}
        ListElement{ text: "Russian Mix"}
        ListElement{ text: "Vip House"}
        ListElement{ text: "Дискотека 90"}
        ListElement{ text: "Moombahton"}
        ListElement{ text: "Trancehouse"}
        ListElement{ text: "Hypnotic"}
        ListElement{ text: "Breaks"}
        ListElement{ text: "Dubstep"}
        ListElement{ text: "Dancecore"}
        ListElement{ text: "Techno"}
        ListElement{ text: "Remix"}
        ListElement{ text: "Future Bass"}
        ListElement{ text: "Hardstyle"}
        ListElement{ text: "Hard Bass"}
        ListElement{ text: "Trap"}
        ListElement{ text: "Old School"}
        ListElement{ text: "Rock"}
        ListElement{ text: "Медляк FM"}
        ListElement{ text: "Гоп FM"}
        ListElement{ text: "Симфония FM"}
        ListElement{ text: "Black"}
        ListElement{ text: "Rave FM"}
        ListElement{ text: "Гастарбайтер FM"}
        ListElement{ text: "Нафталин FM"}
        ListElement{ text: "Аншлаг FM"}
    }

    GridView {
        id: view
        property int countColumns: Screen.width <= 400 ? 3 : Screen.width <= 700 ? 5 : 8
        anchors.margins: 10
        anchors.fill: parent
        cellHeight: (Screen.desktopAvailableWidth / countColumns) - (view.anchors.margins - (view.anchors.margins / 3))
        cellWidth: cellHeight
        currentIndex: -1;
        model: dataModel
        clip: true
        focus: true

        delegate: FocusScope {
            property var view: GridView.view
            property var isCurrent: GridView.isCurrentItem
            property bool isActive: false
            property bool isActiveKey: false

            height: view.cellHeight
            width: view.cellWidth

            Keys.onPressed: {
//                text.text = event.key
                if(event.key === Qt.Key_Return || event.key === Qt.Key_Enter)
                {
                    if(isActive) {
                        Chooser.stop()
                        isActive = false;
                    } else {
                        view.currentIndex = model.index
                        Chooser.setStation(model.text)
                        isActive = true;
                    }
                }
            }

            Rectangle {
                id : circle
                color: backgroundColor
                anchors.margins: 10
                height: parent.height * 0.75
                width: parent.width * 0.75
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
                        if(isActive) {
                            Chooser.stop()
                            view.currentIndex = -1;
                            isActive = false;
                        } else {
                            view.currentIndex = model.index
                            Chooser.setStation(model.text)
                            isActive = true;
                        }
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
                text: "%1".arg(model.text)
                color: isCurrent ? elementColor : activeColor
            }
        }
    }
}
