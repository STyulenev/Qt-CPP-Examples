pragma Singleton

import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

QtObject {
    property QtObject nameValidator: RegularExpressionValidator {
        regularExpression: /^[a-z ,.'-]+$/
    }

    property QtObject ageValidator: RegularExpressionValidator {
        regularExpression: /^([1-9]\d?|1[0-4]\d|150)$/
    }
}
