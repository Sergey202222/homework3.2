#include <iostream>
#include <Windows.h>

class Counter
{
public:
    Counter();
    Counter(int);
    void add();
    void subtract();
    int equals();
private:
    int counter;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string answer{};
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> answer;
    int startCounter{};
    if (answer == "да")
    {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> startCounter;
    }

    Counter counter = (answer == "да")?Counter() : Counter(startCounter);
    char simbol{};
    while (simbol != 'x')
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> simbol;

        switch (simbol)
        {
        case '+':
            counter.add();
            break;
        case '-':
            counter.subtract();
            break;
        case '=':
            std::cout << counter.equals() << '\n';
            break;
        case 'x':
            std::cout << "До свидания!";
            break;
        }
    }
    return EXIT_SUCCESS;
}

Counter::Counter()
{
    counter = 1;
}

Counter::Counter(int counter)
{
    this->counter = counter;
}

void Counter::add()
{
    ++counter;
}

void Counter::subtract()
{
    --counter;
}

int Counter::equals()
{
    return counter;
}