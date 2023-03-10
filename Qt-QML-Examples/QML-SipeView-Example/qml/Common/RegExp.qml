pragma Singleton

import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

QtObject {
    property QtObject name: RegularExpressionValidator {
        regularExpression: /^[a-z ,.'-]+$/
    }
}
