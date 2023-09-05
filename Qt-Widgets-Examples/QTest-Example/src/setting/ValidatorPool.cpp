#include "ValidatorPool.h"

#include <QRegularExpression>

namespace Setting {

ValidatorPool* ValidatorPool::self = 0;

const QStringList listOfRegularExpression =
                    {
                        "^[A-Za-z]{10}$", // reg exp for name
                        "^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$", // reg exp for ip
                        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+" // reg exp for email
                    };

typedef std::pair<QRegularExpressionValidator*, ValidatorPool::Expression> pairValidAndExp;
std::vector<pairValidAndExp> validators;

ValidatorPool::ValidatorPool()
{

}

ValidatorPool::~ValidatorPool()
{

}

auto ValidatorPool::getSelf() -> ValidatorPool*
{
    if (!self) {
        self = new ValidatorPool();
    }

    return self;
}

auto ValidatorPool::getValidator(Expression expression) -> QRegularExpressionValidator*
{
    for (size_t i = 0; i < validators.size(); ++i) {
        if (expression == validators[i].second) {
            return validators[i].first;
        }
    }

    validators.push_back(pairValidAndExp(new QRegularExpressionValidator(QRegularExpression(listOfRegularExpression[expression])), expression));

    return validators.back().first;
}

auto ValidatorPool::clearValidatorPool() -> void
{
    for (auto it = validators.begin(); it != validators.end(); ++it) {
        delete (*it).first;
    }

    validators.clear();
}

} // namespace Setting
