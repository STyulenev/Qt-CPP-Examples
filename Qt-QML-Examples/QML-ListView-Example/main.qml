import QtQuick
import QtQuick.Controls 2.15

// Import C ++ class
import ListModels 0.1 as CPPModels

// Import QML module
import Components 1.0 as Components
import Models 1.0 as QMLModels

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: "QML-ListView-Example"

    property QtObject cppListModel: CPPModels.ListModel { }
    property QtObject qmlListModel: QMLModels.QMLListModel { }
    property QtObject xmlListModel: QMLModels.QMLXmlListModel { }
    property QtObject jsonListModel: QMLModels.QMLJSONListModel { }
    property QtObject objectModel: QMLModels.QMLObjectModel { }

    CPPModels.DishListModel {
        id: cppAndQMLModel

        //data: [
            /*CPPModels.DishModel {
                name: "Hamburger"
                iconUrl: "qrc:/res/images/hamburger.png"
                description: "A hamburger, or simply burger, is a food consisting of fillings—usually a patty of ground meat, typically beef—placed inside a sliced bun or bread roll. Hamburgers are often served with cheese, lettuce, tomato, onion, pickles, bacon, or chilis; condiments such as ketchup, mustard, mayonnaise, relish, or a \"special sauce\"."
                status: true
            },*/
            CPPModels.DishModel {
                name: "Donut"
                iconUrl: "qrc:/res/images/donut.png"
                description: "A doughnut or donut is a type of food made from leavened fried dough. It is popular in many countries and is prepared in various forms as a sweet snack that can be homemade or purchased in bakeries, supermarkets, food stalls, and franchised specialty vendors. Doughnut is the traditional spelling, while donut is the simplified version; the terms are used interchangeably."
                status: false
            }//,
            CPPModels.DishModel {
                name: "Pizza"
                iconUrl: "qrc:/res/images/pizza.png"
                description: "Pizza is a dish of Italian origin consisting of a usually round, flat base of leavened wheat-based dough topped with tomatoes, cheese, and often various other ingredients (such as various types of sausage, anchovies, mushrooms, onions, olives, vegetables, meat, ham, etc.), which is then baked at a high temperature, traditionally in a wood-fired oven. A small pizza is sometimes called a pizzetta."
                status: true
            }//,
            CPPModels.DishModel {
                name: "Ice-cream"
                iconUrl: "qrc:/res/images/ice-cream.png"
                description: "Ice cream is a sweetened frozen food typically eaten as a snack or dessert. It may be made from milk or cream and is flavoured with a sweetener, either sugar or an alternative, and a spice, such as cocoa or vanilla, or with fruit such as strawberries or peaches. It can also be made by whisking a flavored cream base and liquid nitrogen together. Food coloring is sometimes added, in addition to stabilizers."
                status: false
            }
        //]
    }

    /*Components.ListViewData {
        id: listView

        anchors {
            fill: parent
            topMargin: 20
            bottomMargin: 20
            rightMargin: 10
            leftMargin: 10
        }

        model: cppListModel // or jsonModel.model or qmlListModel or xmlModel
    }*/

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

    Components.DishListViewData {
        id: listView

        anchors {
            fill: parent
            topMargin: 20
            bottomMargin: 20
            rightMargin: 10
            leftMargin: 10
        }

        model: cppAndQMLModel.data
    }
}
