import QtQuick 2.9
import QtQuick.Window 2.2
import QtPositioning 5.2
import QtLocation 5.9

Item  {
    visible: true
    width: 1280
    height: 720
    //    title: qsTr("Hello World")

    Map{
        id: map
        anchors.fill:parent
        plugin: Plugin{name: "amap"}
        center: QtPositioning.coordinate(40, 116)
    }
    MapQuickItem
    {
        id: transMarker
    }
    MapCircle
    {
        id: pos_marker
        radius: 10000
        border.width: 2
        color: 'red'
    }
//    MouseArea
//    {
//        anchors.fill: parent
//        onClicked: {
//            var coord = map.toCoordinate(Qt.point(mouse.x,mouse.y));
//            transMarker.coordinate = coord;
//            pos_marker.center=coord
//            map.addMapItem(pos_marker)
//            console.log(coord.latitude, coord.longitude)
//            m_win.dosomething()
//        }
//    }
    Connections
    {
        target: m_win
        onPushed_button:
        {
                console.log("triggered")
        }
        onNumber_emitted:
        {
            console.log("triggered parameter:",output)

        }

    }
}
