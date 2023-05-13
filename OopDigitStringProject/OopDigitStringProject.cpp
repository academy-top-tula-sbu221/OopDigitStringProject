#include <iostream>

enum class Sign
{
    Empty,
    Plus,
    Minus
};

char* StringFromNumber(int number);
int NumberFromString(char* str);

int main()
{
    //char* s = StringFromNumber(2000);
    //std::cout << s << " = " << NumberFromString(s) << "\n";

    for (int i = 0; i < pow(3, 8); i++)
    {
        char* str = StringFromNumber(i);
        int amount = NumberFromString(str);
        if(amount == 351)
            std::cout << str << " = " << amount << "\n";
        
    }
}

char* StringFromNumber(int number)
{
    char* str = new char[18] {};
    
    char digit = '2';
    str[0] = '1';
    
    int position{ 1 };

    while (number)
    {
        switch (number % 3)
        {
        case 0:
            break;
        case 1:
            str[position++] = '-';
            break;
        case 2:
            str[position++] = '+';
            break;
        }
        str[position++] = digit++;
        number /= 3;
    }

    while (digit <= '9')
        str[position++] = digit++;
    
    str[position] = '\0';
    return str;
}

int NumberFromString(char* str)
{
    int result{};
    char sign{ '+' };
    int position{};

    int operandRight{};

    while (str[position])
    {
        if (str[position] != '-' && str[position] != '+')
            operandRight = operandRight * 10 + str[position] - '0';
        else
        {
            if (sign == '-')
                result -= operandRight;
            else
                result += operandRight;
            operandRight = 0;
            sign = str[position];
        }
        position++;
    }
    if (sign == '-')
        result -= operandRight;
    else
        result += operandRight;

    return result;
}