#pragma once

#include <QDoubleValidator>

namespace Validators {

class CustomDoubleValidator : public QDoubleValidator
{
public:
    CustomDoubleValidator(double bottom, double top, int decimals, QObject* parent);
    ~CustomDoubleValidator();

    QValidator::State validate(QString& input, int& pos) const override;

    auto getDevider() const -> QChar;
    auto setDevider(const QChar& devider) -> void;

private:
    QChar devider;

};

} // namespace Validators
