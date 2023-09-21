#pragma once

#include <QRegularExpressionValidator>

namespace Setting {

class ValidatorPool
{
private:
    static ValidatorPool* self;

protected:
    explicit ValidatorPool();
    virtual ~ValidatorPool();

public:
    ValidatorPool(const ValidatorPool& other) = delete;
    ValidatorPool& operator=(const ValidatorPool& other) = delete;
    ValidatorPool(ValidatorPool&&) = delete;
    ValidatorPool& operator=(ValidatorPool&&) = delete;

    enum Expression {
        NAME = 0,
        IP,
        EMAIL
    };

    static auto getSelf() -> ValidatorPool*;
    static auto getValidator(Expression expression) -> QRegularExpressionValidator*;
    static auto clearValidatorPool() -> void;

};

} // namespace Setting
