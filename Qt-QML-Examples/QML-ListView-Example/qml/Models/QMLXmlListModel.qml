import QtQuick
import QtQml.XmlListModel as XML

XML.XmlListModel {
    id: xmlModel

    source: "qrc:/res/xml/example.xml"
    query: "/body/listmodel/item"

    XML.XmlListModelRole {
        name: "DisplayRole"
        elementName: "DisplayRole"
    }

    XML.XmlListModelRole {
        name: "DecorationRole"
        elementName: "DecorationRole"
    }

    XML.XmlListModelRole {
        name: "ToolTipRole"
        elementName: "ToolTipRole"
    }

    XML.XmlListModelRole {
        name: "DescriptionRole"
        elementName: "DescriptionRole"
    }

    XML.XmlListModelRole {
        name: "StatusRole"
        elementName: "StatusRole"
    }
}
