import QtQuick 2.0

import Sailfish.Silica 1.0 as Silica

import "../dialogs" as Dialogs
import "../pickers" as Pickers

Silica.Page  {
    id: mainPage

    objectName: "mainPage"
    allowedOrientations: Silica.Orientation.All

    Silica.PageHeader {
        id: header

        objectName: "pageHeader"
        title: qsTr("Main page")

        extraContent.children: [
            // ...
        ]
    }

    QtObject {
        id: internal

        readonly property int buttonHeight: 100
        readonly property int buttonWidth: 500

        readonly property int columnSpacing: 10
    }

    Row {
        id: main

        anchors.centerIn: parent

        spacing: 20

        Column {
            id: pickersColumn

            spacing: internal.columnSpacing

            Silica.Button {
                id: toContentPicker

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select content")

                onClicked: {
                    var picker = pageStack.push(contentPickerPageComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("File name: ", picker.selectedContentProperties.fileName);
                        console.log("File path: ", picker.selectedContentProperties.filePath);
                        console.log("File title: ", picker.selectedContentProperties.title);
                        console.log("File mimeType: ", picker.selectedContentProperties.mimeType);
                    });
                }
            }

            Silica.Button {
                id: toDocumentPicker

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select document")

                onClicked: {
                    var picker = pageStack.push(documentPickerPageComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("File name: ", picker.selectedContentProperties.fileName);
                        console.log("File path: ", picker.selectedContentProperties.filePath);
                        console.log("File title: ", picker.selectedContentProperties.title);
                        console.log("File mimeType: ", picker.selectedContentProperties.mimeType);
                    });
                }
            }

            Silica.Button {
                id: toDownloadPicker

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select download")

                onClicked: {
                    var picker = pageStack.push(downloadPickerPageComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("File name: ", picker.selectedContentProperties.fileName);
                        console.log("File path: ", picker.selectedContentProperties.filePath);
                        console.log("File title: ", picker.selectedContentProperties.title);
                        console.log("File mimeType: ", picker.selectedContentProperties.mimeType);
                    });
                }
            }

            Silica.Button {
                id: toFilePicker

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select file")

                onClicked: {
                    var picker = pageStack.push(filePickerPageComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("File name: ", picker.selectedContentProperties.fileName);
                        console.log("File path: ", picker.selectedContentProperties.filePath);
                        console.log("File title: ", picker.selectedContentProperties.title);
                        console.log("File mimeType: ", picker.selectedContentProperties.mimeType);
                    });
                }
            }

            Silica.Button {
                id: toFolderPicker

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select folder")

                onClicked: {
                    var picker = pageStack.push(folderPickerPageComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("Folder path: ", picker.selectedPath);
                    });
                }
            }

            Silica.Button {
                id: toImagePicker

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select image")

                onClicked: {
                    var picker = pageStack.push(imagePickerPageComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("File name: ", picker.selectedContentProperties.fileName);
                        console.log("File path: ", picker.selectedContentProperties.filePath);
                        console.log("File title: ", picker.selectedContentProperties.title);
                        console.log("File mimeType: ", picker.selectedContentProperties.mimeType);
                    });
                }
            }

            Silica.Button {
                id: toMusicPicker

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select music")

                onClicked: {
                    var picker = pageStack.push(musicPickerPageComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("File name: ", picker.selectedContentProperties.fileName);
                        console.log("File path: ", picker.selectedContentProperties.filePath);
                        console.log("File title: ", picker.selectedContentProperties.title);
                        console.log("File mimeType: ", picker.selectedContentProperties.mimeType);
                    });
                }
            }

            Silica.Button {
                id: toPrinterPicker

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select printer")

                onClicked: {
                    var picker = pageStack.push(printerPickerPageComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("PrintPath name: ", picker.printPath);
                    });
                }
            }

            Silica.Button {
                id: toVideoPicker

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select video")

                onClicked: {
                    var picker = pageStack.push(videoPickerPageComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("File name: ", picker.selectedContentProperties.fileName);
                        console.log("File path: ", picker.selectedContentProperties.filePath);
                        console.log("File title: ", picker.selectedContentProperties.title);
                        console.log("File mimeType: ", picker.selectedContentProperties.mimeType);
                    });
                }
            }
        }

        Column {
            id: dialogsColumn

            spacing: internal.columnSpacing

            Silica.Button {
                id: toContentDialog

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select content")

                onClicked: {
                    var picker = pageStack.push(contentDialogComponent, {});

                    picker.startDestroy.connect(function() {
                        for (var i = 0; i < picker.selectedContent.count; i++) {
                            console.log("№", i);
                            console.log("File name: ", picker.selectedContent.get(i).fileName);
                            console.log("File path: ", picker.selectedContent.get(i).filePath);
                            console.log("File title: ", picker.selectedContent.get(i).title);
                            console.log("File mimeType: ", picker.selectedContent.get(i).mimeType);
                            console.log("");
                        }
                    });
                }
            }

            Silica.Button {
                id: toDocumentDialog

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select document")

                onClicked: {
                    var picker = pageStack.push(documentDialogComponent, {});

                    picker.startDestroy.connect(function() {
                        for (var i = 0; i < picker.selectedContent.count; i++) {
                            console.log("№", i);
                            console.log("File name: ", picker.selectedContent.get(i).fileName);
                            console.log("File path: ", picker.selectedContent.get(i).filePath);
                            console.log("File title: ", picker.selectedContent.get(i).title);
                            console.log("File mimeType: ", picker.selectedContent.get(i).mimeType);
                            console.log("");
                        }
                    });
                }
            }

            Silica.Button {
                id: toDownloadDialog

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select download")

                onClicked: {
                    var picker = pageStack.push(downloadDialogComponent, {});

                    picker.startDestroy.connect(function() {
                        for (var i = 0; i < picker.selectedContent.count; i++) {
                            console.log("№", i);
                            console.log("File name: ", picker.selectedContent.get(i).fileName);
                            console.log("File path: ", picker.selectedContent.get(i).filePath);
                            console.log("File title: ", picker.selectedContent.get(i).title);
                            console.log("File mimeType: ", picker.selectedContent.get(i).mimeType);
                            console.log("");
                        }
                    });
                }
            }

            Silica.Button {
                id: toFileDialog

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select file")

                onClicked: {
                    var picker = pageStack.push(fileDialogComponent, {});

                    picker.accepted.connect(function() {
                        for (var i = 0; i < picker.selectedContent.count; i++) {
                            console.log("№", i);
                            console.log("File name: ", picker.selectedContent.get(i).fileName);
                            console.log("File path: ", picker.selectedContent.get(i).filePath);
                            console.log("File title: ", picker.selectedContent.get(i).title);
                            console.log("File mimeType: ", picker.selectedContent.get(i).mimeType);
                            console.log("");
                        }
                    });
                }
            }

            Silica.Button {
                id: toFolderDialog

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select folder")

                onClicked: {
                    var picker = pageStack.push(folderDialogComponent, {});

                    picker.startDestroy.connect(function() {
                        console.log("Folder path: ", picker.selectedPath);
                    });
                }
            }

            Silica.Button {
                id: toImageDialog

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select image")

                onClicked: {
                    var picker = pageStack.push(imageDialogComponent, {});

                    picker.startDestroy.connect(function() {
                        for (var i = 0; i < picker.selectedContent.count; i++) {
                            console.log("№", i);
                            console.log("File name: ", picker.selectedContent.get(i).fileName);
                            console.log("File path: ", picker.selectedContent.get(i).filePath);
                            console.log("File title: ", picker.selectedContent.get(i).title);
                            console.log("File mimeType: ", picker.selectedContent.get(i).mimeType);
                            console.log("");
                        }
                    });
                }
            }

            Silica.Button {
                id: toMusicDialog

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select music")

                onClicked: {
                    var picker = pageStack.push(musicDialogComponent, {});

                    picker.startDestroy.connect(function() {
                        for (var i = 0; i < picker.selectedContent.count; i++) {
                            console.log("№", i);
                            console.log("File name: ", picker.selectedContent.get(i).fileName);
                            console.log("File path: ", picker.selectedContent.get(i).filePath);
                            console.log("File title: ", picker.selectedContent.get(i).title);
                            console.log("File mimeType: ", picker.selectedContent.get(i).mimeType);
                            console.log("");
                        }
                    });
                }
            }

            Silica.Button {
                id: toVideoDialog

                height: internal.buttonHeight
                width: internal.buttonWidth

                text: qsTr("Select video")

                onClicked: {
                    var picker = pageStack.push(videoDialogComponent, {});

                    picker.startDestroy.connect(function() {
                        for (var i = 0; i < picker.selectedContent.count; i++) {
                            console.log("№", i);
                            console.log("File name: ", picker.selectedContent.get(i).fileName);
                            console.log("File path: ", picker.selectedContent.get(i).filePath);
                            console.log("File title: ", picker.selectedContent.get(i).title);
                            console.log("File mimeType: ", picker.selectedContent.get(i).mimeType);
                            console.log("");
                        }
                    });
                }
            }
        }
    }

    // Pickers (страницы):
    // ContentPickerPage  - Данный тип группирует на одной странице специализированные средства выбора одного файла
    // DocumentPickerPage - Средство выбора одного файла документа
    // DownloadPickerPage - Средство выбора одного загруженного файла
    // FilePickerPage     - Средство выбора одного файла произвольного типа
    // FolderPickerPage   - Средство для выбора файла
    // ImagePickerPage    - Средство выбора одного файла изображения
    // MusicPickerPage    - Средство выбора одного файла с музыкой
    // PrinterPickerPage  - Средство выбора для принтера
    // VideoPickerPage    - Средство выбора одного видео-файла

    readonly property Component contentPickerPageComponent:  Pickers.ContentPicker {}
    readonly property Component documentPickerPageComponent: Pickers.DocumentPicker {}
    readonly property Component downloadPickerPageComponent: Pickers.DownloadPicker {}
    readonly property Component filePickerPageComponent:     Pickers.FilePicker {}
    readonly property Component folderPickerPageComponent:   Pickers.FolderPicker {}
    readonly property Component imagePickerPageComponent:    Pickers.ImagePicker {}
    readonly property Component musicPickerPageComponent:    Pickers.MusicPicker {}
    readonly property Component printerPickerPageComponent:  Pickers.PrinterPicker {}
    readonly property Component videoPickerPageComponent:    Pickers.VideoPicker {}

    // Dialogs (диалоги, в основном множественного выбора):
    // FolderPickerDialog        - Диалог для выбора пути к каталогу
    // MultiContentPickerDialog  - Данный тип группирует в одном диалоге специализированные средства выбора нескольких файлов
    // MultiDocumentPickerDialog - Средство выбора нескольких файлов документов
    // MultiDownloadPickerDialog - Средство выбора нескольких загруженных файлов
    // MultiFilePickerDialog     - Средство выбора нескольких файлов произвольного типа
    // MultiImagePickerDialog    - Средство выбора нескольких файлов изображений
    // MultiMusicPickerDialog    - Средство выбора нескольких файлов с музыкой
    // MultiVideoPickerDialog    - Средство выбора нескольких видео-файлов
    readonly property Component contentDialogComponent:  Dialogs.ContentDialog {}
    readonly property Component documentDialogComponent: Dialogs.DocumentDialog {}
    readonly property Component downloadDialogComponent: Dialogs.DownloadDialog {}
    readonly property Component fileDialogComponent:     Dialogs.FileDialog {}
    readonly property Component folderDialogComponent:   Dialogs.FolderDialog {}
    readonly property Component imageDialogComponent:    Dialogs.ImageDialog {}
    readonly property Component musicDialogComponent:    Dialogs.MusicDialog {}
    readonly property Component videoDialogComponent:    Dialogs.VideoDialog {}
}
