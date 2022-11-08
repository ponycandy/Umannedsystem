import QtQuick 2.9
import QtQuick.Window 2.2
import QtPositioning 5.2
import QtLocation 5.9

Item  {
    visible: true
    width: 1280
    height: 720

    Map{
        id: map
        anchors.fill:parent
        plugin: Plugin{name: "amap"}
        zoomLevel : 20
        center: QtPositioning.coordinate(39.95767687588489, 116.32143777823063)
        Text {
            id: map_text_lat
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 10
            font.pointSize: 20
            text: "lat:    "+ "\nlon:    "
            color: "red"
        }
        MouseArea
        {
            anchors.fill: parent
            hoverEnabled: true
            onPositionChanged: {
                var coord = map.toCoordinate(Qt.point(mouse.x,mouse.y));
                map_text_lat.text="lat:    "+coord.latitude+ "\nlon:    "+coord.longitude

            }
            onClicked: {
                var coord = map.toCoordinate(Qt.point(mouse.x,mouse.y));
                transMarker.coordinate = coord;
                pos_marker.center=coord
                map.addMapItem(pos_marker)
            }
        }
    }
    MapQuickItem
    {
        id: transMarker
    }
    MapCircle
    {
        id: pos_marker
        radius: 1
        border.width: 1
        color: 'red'
    }
}
