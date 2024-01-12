import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQml.XmlListModel as XML
import QtQml.Models 2.15 as QmlModels

// Import C ++ class
import ListModels 0.1 as Models

// Import QML module
import Components 1.0 as Components
import External 1.0 as External

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-ListView-Example"

    property QtObject cppListModel: Models.ListModel { }

    ListModel {
        id: qmlListModel

        ListElement {
            DisplayRole: "Hamburger"
            DecorationRole: "qrc:/res/images/hamburger.png"
            ToolTipRole: "User status here\nYou can change it"
            DescriptionRole: "A hamburger, or simply burger, is a food consisting of fillings—usually a patty of ground meat,
            typically beef—placed inside a sliced bun or bread roll. Hamburgers are often served with cheese, lettuce, tomato, onion, pickles, bacon,
            or chilis; condiments such as ketchup, mustard, mayonnaise, relish, or a \"special sauce\"."
            StatusRole: true
        }

        ListElement {
            DisplayRole: "Donut"
            DecorationRole: "qrc:/res/images/donut.png"
            ToolTipRole: "User status here\nYou can change it"
            DescriptionRole: "A doughnut or donut is a type of food made from leavened fried dough. It is popular in many countries and
            is prepared in various forms as a sweet snack that can be homemade or purchased in bakeries, supermarkets, food stalls, and franchised
            specialty vendors. Doughnut is the traditional spelling, while donut is the simplified version; the terms are used interchangeably."
            StatusRole: false
        }

        ListElement {
            DisplayRole: "Pizza"
            DecorationRole: "qrc:/res/images/pizza.png"
            ToolTipRole: "User status here\nYou can change it"
            DescriptionRole: "Pizza is a dish of Italian origin consisting of a usually round, flat base of leavened wheat-based
            dough topped with tomatoes, cheese, and often various other ingredients (such as various types of sausage, anchovies, mushrooms, onions,
            olives, vegetables, meat, ham, etc.), which is then baked at a high temperature, traditionally in a wood-fired oven. A small pizza is
            sometimes called a pizzetta."
            StatusRole: true
        }

        ListElement {
            DisplayRole: "Ice-cream"
            DecorationRole: "qrc:/res/images/ice-cream.png"
            ToolTipRole: "User status here\nYou can change it"
            DescriptionRole: "Ice cream is a sweetened frozen food typically eaten as a snack or dessert. It may be made from
            milk or cream and is flavoured with a sweetener, either sugar or an alternative, and a spice, such as cocoa or vanilla, or with fruit
            such as strawberries or peaches. It can also be made by whisking a flavored cream base and liquid nitrogen together. Food coloring is
            sometimes added, in addition to stabilizers."
            StatusRole: false
        }
    }

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

    External.JSONListModel {
        id: jsonModel

        json: '[ \
            { \
                "DisplayRole": "Hamburger", \
                "DecorationRole": "qrc:/res/images/hamburger.png", \
                "ToolTipRole": "User status here\\nYou can change it", \
                "DescriptionRole": "A hamburger, or simply burger, is a food consisting of fillings—usually a patty of ground meat, \
typically beef—placed inside a sliced bun or bread roll. Hamburgers are often served with cheese, lettuce, tomato, onion, pickles, bacon, \
or chilis; condiments such as ketchup, mustard, mayonnaise, relish, or a \\"special sauce\\".", \
                "StatusRole": "true" \
            }, \
            { \
                "DisplayRole": "Donut", \
                "DecorationRole": "qrc:/res/images/donut.png", \
                "ToolTipRole": "User status here\\nYou can change it", \
                "DescriptionRole": "A doughnut or donut is a type of food made from leavened fried dough. It is popular in many countries and \
is prepared in various forms as a sweet snack that can be homemade or purchased in bakeries, supermarkets, food stalls, and franchised \
specialty vendors. Doughnut is the traditional spelling, while donut is the simplified version; the terms are used interchangeably.", \
                "StatusRole": "false" \
            }, \
            { \
                "DisplayRole": "Pizza", \
                "DecorationRole": "qrc:/res/images/pizza.png", \
                "ToolTipRole": "User status here\\nYou can change it", \
                "DescriptionRole": "Pizza is a dish of Italian origin consisting of a usually round, flat base of leavened wheat-based \
dough topped with tomatoes, cheese, and often various other ingredients (such as various types of sausage, anchovies, mushrooms, onions, \
olives, vegetables, meat, ham, etc.), which is then baked at a high temperature, traditionally in a wood-fired oven. A small pizza is \
sometimes called a pizzetta.", \
                "StatusRole": "true" \
            }, \
            { \
                "DisplayRole": "Ice-cream", \
                "DecorationRole": "qrc:/res/images/ice-cream.png", \
                "ToolTipRole": "User status here\\nYou can change it", \
                "DescriptionRole": "Ice cream is a sweetened frozen food typically eaten as a snack or dessert. It may be made from \
milk or cream and is flavoured with a sweetener, either sugar or an alternative, and a spice, such as cocoa or vanilla, or with fruit \
such as strawberries or peaches. It can also be made by whisking a flavored cream base and liquid nitrogen together. Food coloring is \
sometimes added, in addition to stabilizers.", \
                "StatusRole": "false" \
            } \
        ]'

        query: "$[*]"
    }

    QmlModels.ObjectModel {
        id: objectModel

        Components.CustomObject {
            displayRole: "Hamburger"
            decorationRole: "qrc:/res/images/hamburger.png"
            toolTipRole: "User status here\nYou can change it"
            descriptionRole: "A hamburger, or simply burger, is a food consisting of fillings—usually a patty of ground meat,
typically beef—placed inside a sliced bun or bread roll. Hamburgers are often served with cheese, lettuce, tomato, onion, pickles, bacon,
or chilis; condiments such as ketchup, mustard, mayonnaise, relish, or a \"special sauce\"."
            statusRole: true
        }

        Components.CustomObject {
            displayRole: "Donut"
            decorationRole: "qrc:/res/images/donut.png"
            toolTipRole: "User status here\nYou can change it"
            descriptionRole: "A doughnut or donut is a type of food made from leavened fried dough. It is popular in many countries and
is prepared in various forms as a sweet snack that can be homemade or purchased in bakeries, supermarkets, food stalls, and franchised
specialty vendors. Doughnut is the traditional spelling, while donut is the simplified version; the terms are used interchangeably."
            statusRole: false
        }

        Components.CustomObject {
            displayRole: "Pizza"
            decorationRole: "qrc:/res/images/pizza.png"
            toolTipRole: "User status here\nYou can change it"
            descriptionRole: "Pizza is a dish of Italian origin consisting of a usually round, flat base of leavened wheat-based
dough topped with tomatoes, cheese, and often various other ingredients (such as various types of sausage, anchovies, mushrooms, onions,
olives, vegetables, meat, ham, etc.), which is then baked at a high temperature, traditionally in a wood-fired oven. A small pizza is
sometimes called a pizzetta."
            statusRole: true
        }

        Components.CustomObject {
            displayRole: "Ice-cream"
            decorationRole: "qrc:/res/images/ice-cream.png"
            toolTipRole: "User status here\nYou can change it"
            descriptionRole: "Ice cream is a sweetened frozen food typically eaten as a snack or dessert. It may be made from
milk or cream and is flavoured with a sweetener, either sugar or an alternative, and a spice, such as cocoa or vanilla, or with fruit
such as strawberries or peaches. It can also be made by whisking a flavored cream base and liquid nitrogen together. Food coloring is
sometimes added, in addition to stabilizers."
            statusRole: false
        }

    }

    Components.ListViewData {
        id: listView

        anchors {
            fill: parent
            topMargin: 20
            bottomMargin: 20
            rightMargin: 10
            leftMargin: 10
        }

        model: cppListModel // or jsonModel.model or qmlListModel or xmlModel
    }

    /*ListView {
        id: listView

        anchors {
            fill: parent
            topMargin: 20
            bottomMargin: 20
            rightMargin: 10
            leftMargin: 10
        }

        model: objectModel
    }*/
}
