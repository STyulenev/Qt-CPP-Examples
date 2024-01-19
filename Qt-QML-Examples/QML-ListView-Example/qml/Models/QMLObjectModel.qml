import QtQuick
import QtQml.Models 2.15 as QmlModels

// Import QML module
import Components 1.0 as Components

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
