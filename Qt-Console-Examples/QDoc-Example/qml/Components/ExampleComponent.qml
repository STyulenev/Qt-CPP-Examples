import QtQuick 2.4
import QtQuick.Controls 2.2

/*!
   \qmltype ExampleComponent.qml
   \brief Пример простого QML компонента.

   ExampleComponent состоит из стандартного Rectangle с одним переопределенным полем myColor
   и создан только для примера документации QDoc.

   \qml
   import Components 1.0 as Components

    Components.ExampleComponent {
        id: exampleComponent

        anchors.centerIn: parent
    }
   \endqml
*/
Rectangle {
    id: root

    /*!
       Пример документирования поля
    */
    property alias myColor: root.color

    height: 200
    width: 200
}
