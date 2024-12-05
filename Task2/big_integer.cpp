#include "big_integer.h"

// Конструктор, принимающий строку
big_integer::big_integer(std::string str): number{str}
{
	for (unsigned long long i = 0; i < number.length(); i++)
	{
		if ((number[i] < DIGITAL_BOUND) || (number[i] > (DIGITAL_BOUND + 9)))
		{
			throw std::exception("Incorrect parameter of big_integer!");
		}
	}
}

// Конструктор перемещения
big_integer::big_integer(big_integer&& other) noexcept
{
	std::swap(this->number, other.number);
}

// Конструктор копирования
big_integer::big_integer(big_integer& other) : big_integer{ other.number }
{}

// Оператор копирования
big_integer& big_integer::operator=(big_integer& other)
{
	if (this == &other)
	{
		return *this;
	}

	this->number = other.number;
	return *this;
}

// Оператор перемещения
big_integer& big_integer::operator=(big_integer&& other) noexcept
{
	std::swap(this->number, other.number);
	return *this;
}

// Сложение больших чисел
big_integer operator+(big_integer& other1, big_integer& other2)
{
	int len1{ static_cast<int>(other1.number.length()) };
	int len2{ static_cast<int>(other2.number.length()) };
	std::string str{};
	int tempNumber{};
	int length{};
	std::string str1{other1.number};
	std::string str2{other2.number};
	if (len1 > len2)
	{
		for (int i{}; i < (len1 - len2); ++i)
		{
			str2 = '0' + str2;
		}
		length = len1;
	}
	else if (len2 > len1)
	{
		for (int i{}; i < (len2 - len1); ++i)
		{
			str1 = '0' + str1;
		}
		length = len2;
	}
	for (int i{ static_cast<int>(length) - 1 }; i >= 0; --i)
	{
		int num{ static_cast<int>((str1[i]) - DIGITAL_BOUND) + static_cast<int>((str2[i]) - DIGITAL_BOUND) + tempNumber };
		if (num > 9)
		{
			tempNumber = num / 10;
			num %= 10;
		}
		else
		{
			tempNumber = 0;
		}
		str = std::to_string(num) + str;
	}
	if (tempNumber)
	{
		str = std::to_string(tempNumber) + str;
	}
	big_integer bi(str);
	return bi;
}

// Умножение большого числа на int
big_integer operator*(big_integer& other, int number)
{
	if (!number)
	{
		return { "0" };
	}
	if (number == 1)
	{
		return other;
	}
	int tempNumber{};
	std::string str{ other.number };
	unsigned long long length{ str.length() };
	std::string result{};

	for (unsigned long long i{length - 1}; i < length; --i)
	{
		int num{ number * static_cast<int>(str[i] - DIGITAL_BOUND) + tempNumber };
		if (num > 9)
		{
			tempNumber = num / 10;
			num %= 10;
		}
		else
		{
			tempNumber = 0;
		}
		result = std::to_string(num) + result;
	}
	if (tempNumber)
	{
		result	 = std::to_string(tempNumber) + result;
	}
	big_integer bi(result);
	return bi;
}

// Умножение int на большое число
big_integer operator*(int number, big_integer& other)
{
	return (other * number);
}

// Умножение больших чисел
big_integer operator*(big_integer& other1, big_integer& other2)
{
	big_integer result("0");
	std::string str1{ other1.number };
	//std::string str2{ other2.number };
	unsigned long long len1{ str1.length() };
	//unsigned long long len2{ str2.length() };
	//big_integer bi("0");
	for (unsigned long long i{len1 - 1}; i < len1; --i)
	{
		big_integer bi { static_cast<int>(str1[i] - DIGITAL_BOUND) * other2 };
		for (int j{}; j < (len1 - 1 - i); j++)
		{
			bi = bi * 10;
		}
		result = result + bi;
	}
	return result;
}

// Перегрузка оператора <<
std::ostream& operator<<(std::ostream& os, const big_integer& bi)
{
	return (os << bi.number);
}
