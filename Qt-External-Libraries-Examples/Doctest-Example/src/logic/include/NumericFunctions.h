#pragma once

namespace Logic {

class Numeric
{
private:
    int firstNumber;
    int secondNumber;

public:
    explicit Numeric(int firstNumber, int secondNumber);
    ~Numeric();

    int getFirstNumber() const;
    int getSecondNumber() const;

    void setFirstNumber(int newFirstNumber);
    void setSecondNumber(int newSecondNumber);

    int add();
    int sub();
    int div();
    int multi();

};

} // namespace Logic
