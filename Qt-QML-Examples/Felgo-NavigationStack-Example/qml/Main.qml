import Felgo
import QtQuick

App {
    id: app

    property int count: 0

    // main page
    NavigationStack {
        initialPage: FirstPage { }
    }
}

