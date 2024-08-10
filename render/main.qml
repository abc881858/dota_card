import QtQuick
import QtQuick.Controls
import QtQuick.Window
import "data.js" as Data

Window {
    id: demo
    visible: true
    x: 0
    y: 0
    width: 1920
    height: 1080
    title: qsTr("Demo")

    visibility: Window.Windowed

    BoardItem {
    }

    MainMenu {
    }

    // Button {
    //     id: button28
    //     x: 2062
    //     y: 303
    //     text: qsTr("Blue Draw")
    //     onClicked: {
    //         console.log("blue draw");
    //         Data.blue_draw_card();
    //     }
    // }

    // Button {
    //     id: button29
    //     x: 2062
    //     y: 360
    //     text: qsTr("Red Draw")
    //     onClicked: {
    //         console.log("red draw");
    //         Data.red_draw_card();
    //     }
    // }

    // Button {
    //     id: button30
    //     x: 2062
    //     y: 410
    //     text: qsTr("redVerticalFaceupFront")
    //     onClicked: {
    //         Data.redVerticalFaceupFront(Number(indexOfHand.text));
    //         if(Data.oldSelectCard !== undefined) {
    //             Data.oldSelectCard.highlight = false;
    //         }
    //     }
    // }

    // Button {
    //     id: button32
    //     x: 2062
    //     y: 478
    //     text: qsTr("redHorizontalFacedownFront")
    //     onClicked: {
    //         Data.redHorizontalFacedownFront(Number(indexOfHand.text));
    //         if(Data.oldSelectCard !== undefined) {
    //             Data.oldSelectCard.highlight = false;
    //         }
    //     }
    // }

    // Text {
    //     id: element
    //     x: 2062
    //     y: 551
    //     width: 142
    //     height: 53
    //     text: qsTr("Index of Hand")
    //     font.pixelSize: 12
    // }

    // TextInput {
    //     id: indexOfHand
    //     x: 2062
    //     y: 610
    //     width: 112
    //     height: 77
    //     text: qsTr("0")
    //     font.pixelSize: 12
    //     horizontalAlignment: Text.AlignHCenter
    //     verticalAlignment: Text.AlignVCenter
    // }

    // Button {
    //     id: button
    //     x: 2026
    //     y: 207
    //     width: 128
    //     height: 65
    //     text: qsTr("start game")
    //     onClicked: {
    //         Data.start_game();
    //     }
    // }
}
