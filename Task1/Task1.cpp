// Вам нужно реализовать шаблонную функцию, которая перемещает содержимое одного std::vector в другой.
//

#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T>& sourceVector, std::vector<T>& targetVector)
{
    targetVector = std::move(sourceVector);
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two = {"one", "two"};

    auto myRef = &(two.front());    // Для проверки освобождения памяти
    std::cout << "String before move: " << *myRef << '\n';

    std::cout << "Address of one before move: " << &(one.front()) << '\n';    // Адрес ссылки на первый элемент вектора one
    std::cout << "Address of two before move: " << &(two.front()) << '\n';    // Адрес ссылки на первый элемент вектора two
    
    move_vectors(one, two);
    //std::cout << "Address of one: " << &(one.front()) << '\n';    // Адрес ссылки на первый элемент вектора one
    std::cout << "Address of two after move: " << &(two.front()) << '\n';    // Адрес ссылки на первый элемент вектора two
    std::cout << "String after move: " << *myRef << '\n';
}

