#include "CustomDoubleValidator.h"

namespace Validators {

CustomDoubleValidator::CustomDoubleValidator(double bottom, double top, int decimals, QObject* parent) :
    QDoubleValidator(bottom, top, decimals, parent),
    devider('.')
{

}

CustomDoubleValidator::~CustomDoubleValidator()
{

}

auto CustomDoubleValidator::validate(QString& input, int& pos) const -> QValidator::State
{
    if (input.isEmpty() || input == "-") {
        return QValidator::Intermediate;
    }

    int charsAfterPoint = input.length() - input.indexOf(devider) -1;

    if (charsAfterPoint > decimals() && input.indexOf(devider) != -1) {
        return QValidator::Invalid;
    }

    bool isOk = false;
    double currentNumber = input.toDouble(&isOk);

    return (isOk && currentNumber >= bottom() && currentNumber <= top()) ? QValidator::Acceptable: QValidator::Invalid;
}

auto CustomDoubleValidator::getDevider() const -> QChar
{
    return devider;
}

auto CustomDoubleValidator::setDevider(const QChar& devider) -> void
{
    this->devider = devider;
}

} // namespace Validators
