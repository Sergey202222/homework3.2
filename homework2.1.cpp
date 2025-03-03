#include <iostream>

class Calculator
{
public:
    double add();
    double multiply();
    double subtract_1_2();
    double subtract_2_1();
    double divide_1_2();
    double divide_2_1();
    bool set_num1(double num1);
    bool set_num2(double num2);
private:
    double num1;
    double num2;
};

int main()
{
    setlocale(LC_ALL, "rus");
    Calculator calculator;
    double num1{}, num2{};
    while (true)
    {
        std::cout << "Введите num1: ";
        std::cin >> num1;
        std::cout << "Введите num2: ";
        std::cin >> num2;

        while (!(calculator.set_num1(num1) && calculator.set_num2(num2)))
        {
            if (!calculator.set_num1(num1) && calculator.set_num2(num2))
            {
                std::cout << "Неверный ввод!\n";
                std::cout << "Введите num1: ";
                std::cin >> num1;
            }
            else if (calculator.set_num1(num1) && !calculator.set_num2(num2))
            {
                std::cout << "Неверный ввод!\n";
                std::cout << "Введите num2: ";
                std::cin >> num2;
            }
            else if (!(calculator.set_num1(num1) && calculator.set_num2(num2)))
            {
                std::cout << "Неверный ввод!\n";
                std::cout << "Введите num1: ";
                std::cin >> num1;
                std::cout << "Введите num2: ";
                std::cin >> num2;
            }
        }
        
        std::cout << "num1 + num2 = " << calculator.add() << '\n';
        std::cout << "num1 - num2 = " << calculator.subtract_1_2() << '\n';
        std::cout << "num2 - num1 = " << calculator.subtract_2_1() << '\n';
        std::cout << "num1 * num2 = " << calculator.multiply() << '\n';
        std::cout << "num1 / num2 = " << calculator.divide_1_2() << '\n';
        std::cout << "num1 + num2 = " << calculator.divide_2_1() << '\n';
    }
    return EXIT_SUCCESS;
}

double Calculator::add()
{
    return num1 + num2;
}

double Calculator::multiply()
{
    return num1 * num2;
}

double Calculator::subtract_1_2()
{
    return num1 - num2;
}

double Calculator::subtract_2_1()
{
    return num2 - num1;
}

double Calculator::divide_1_2()
{
    return num1 / num2;
}

double Calculator::divide_2_1()
{
    return num2 / num1;
}

bool Calculator::set_num1(double num1)
{
    if (num1 != 0)
    {
        this->num1 = num1;
        return true;
    }
    return false;
}

bool Calculator::set_num2(double num2)
{
    if (num2 != 0)
    {
        this->num2 = num2;
        return true;
    }
    return false;
}