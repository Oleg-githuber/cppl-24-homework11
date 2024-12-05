/*
Вам нужно реализовать класс для работы с большими числами, которые не помещаются в стандартные типы данных.

Для этого класса нужно определить методы:

конструктор перемещения;
перемещающий оператор присваивания;
оператор сложения двух больших чисел;
оператор умножения на число.
Для реализации этого класса можно воспользоваться std::string или std::vector.
*/
#include <iostream>
#include "big_integer.h"

int main()
{
    // Проверка перегруженых конструкторов и операторов
    big_integer bi1("1111111111");
    big_integer bi2(bi1);
    big_integer bi3(std::move(bi2));
    big_integer bi4 = bi1;
    big_integer bi5{ "2222222222" };
    bi5 = bi4;
    big_integer bi6 = std::move(bi5);
    big_integer bi7("44");
    bi7 = std::move(bi6);
    big_integer bi8(std::move(bi7));
    
    // Сложение и умножение
    big_integer num1("999");
    big_integer num2("2");
    big_integer sum = (num1 + num2);
    std::cout << num1 << " + " << num2 << " = " << sum << '\n';
    big_integer mul = num1 * 2;
    std::cout << num1 << " x 2 = " << mul << '\n';
    big_integer mul2 = 25 * num1;
    std::cout << "25 x " << num1 << " = " << mul2 << '\n';
    big_integer num3{ "333" };
    big_integer mul3 = num1 * num3;
    std::cout << num1 << " x " << num3 << " = " << mul3 << '\n';

    // Проверка создания объекта с некорректным параметром
    try
    {
        big_integer bi9{ "22u" };
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}
