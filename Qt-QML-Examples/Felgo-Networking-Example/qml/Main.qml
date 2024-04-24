import Felgo as Felgo

import QtQuick
import QtQuick.Layouts

import Controllers 1.0 as Controllers

Felgo.App {
    id: app

    property QtObject customHttpClient: Controllers.CustomHttpClient { }

    Felgo.AppTextEdit {
        id: textOutput

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }

        height: parent.height * 3 / 4
    }

    GridLayout {
        id: buttons

        anchors {
            top: textOutput.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        columns: 2
        rows: 2

        Felgo.AppButton {
            Layout.fillHeight: true
            Layout.fillWidth: true

            text: qsTr("Get Server time")

            onClicked: {
                textOutput.clear();

                // Felgo Http client
                /*Felgo.HttpRequest
                .get("http://127.0.0.1:8000/time")
                .timeout(5000)
                .then(function(result) {
                    textOutput.text = JSON.stringify(result.body, null, 4);
                })
                .catch(function(error) {
                    textOutput.text = ("Felgo.HttpRequest error: %1").arg(error.code);
                });*/

                // Custom Http client
                customHttpClient.get("http://127.0.0.1:8000/time")
                .then(function(request, result) {
                    textOutput.text += ("request: %1, result %2").arg(request).arg(result);
                })
                .then(function(request, result) {
                    textOutput.text += ("\nrequest: %1, result %2").arg(request).arg(result);
                })
                .clean(function() {
                    textOutput.text += ("\nclean");
                })
            }
        }

        Felgo.AppButton {
            Layout.fillHeight: true
            Layout.fillWidth: true

            text: qsTr("Get User List")

            onClicked: {
                textOutput.clear();

                // Felgo Http client
                /*Felgo.HttpRequest
                .get("http://127.0.0.1:8000/users")
                .timeout(5000)
                .then(function(result) {
                    textOutput.text = JSON.stringify(result.body, null, 4);
                })
                .catch(function(error) {
                    textOutput.text = ("Felgo.HttpRequest error: %1").arg(error.code);
                });*/

                // Custom Http client
                customHttpClient.get("http://127.0.0.1:8000/users")
                .then(function(request, result) {
                    textOutput.text += ("request: %1, result %2").arg(request).arg(result);
                })
                .then(function(request, result) {
                    textOutput.text += ("\nrequest: %1, result %2").arg(request).arg(result);
                })
                .clean(function() {
                    textOutput.text += ("\nclean");
                })
            }
        }

        Felgo.AppButton {
            Layout.fillHeight: true
            Layout.fillWidth: true

            text: qsTr("Post New User")

            onClicked: {
                textOutput.clear();

                // Некоторые дополнительные данные, если нужны
                let someData = {
                    data: "some data",

                    toString() {
                        return `{ "data": "${this.data}"}`;
                    }
                };

                // Felgo Http client
                /*Felgo.HttpRequest
                .post("http://127.0.0.1:8000/users?name=John&sex=male&age=19", someData.toString())
                .timeout(5000)
                .then(function(result) {
                    textOutput.text = JSON.stringify(result.body, null, 4);
                })
                .catch(function(error) {
                    textOutput.text = ("Felgo.HttpRequest error: %1").arg(error.code);
                });*/

                // Custom Http client
                customHttpClient.post("http...")
                .then(function(request, result) {
                    textOutput.text += ("request: %1, result %2").arg(request).arg(result);
                })
                .then(function(request, result) {
                    textOutput.text +=("\nrequest: %1, result %2").arg(request).arg(result);
                })
                .clean(function() {
                    textOutput.text += ("\nclean");
                })
            }
        }

        Felgo.AppButton {
            Layout.fillHeight: true
            Layout.fillWidth: true

            text: qsTr("Delete User [0]")

            onClicked: {
                textOutput.clear();

                // Felgo Http client
                /*Felgo.HttpRequest
                .del("http://127.0.0.1:8000/users/0")
                .timeout(5000)
                .then(function(result) {
                    textOutput.text = JSON.stringify(result.body, null, 4);
                })
                .catch(function(error) {
                    textOutput.text = ("Felgo.HttpRequest error: %1").arg(error.code);
                });*/

                // Custom Http client
                customHttpClient.del("http...")
                .then(function(request, result) {
                    textOutput.text += ("request: %1, result %2").arg(request).arg(result);
                })
                .then(function(request, result) {
                    textOutput.text += ("\nrequest: %1, result %2").arg(request).arg(result);
                })
                .clean(function() {
                    textOutput.text += ("\nclean");
                })
            }
        }
    }
}
