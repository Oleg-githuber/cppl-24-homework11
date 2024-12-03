#pragma once

#include <iostream>
#include <string>
#include <exception>

#define DIGITAL_BOUND 48

class big_integer
{
private:
	std::string number{};	// Строка для хранения большого числа

public:
	big_integer(std::string str);	// Конструктор, принимающий строку

	big_integer(big_integer&& other);	// Конструктор перемещения

	big_integer(big_integer& other);	// Конструктор копирования

	big_integer& operator=(big_integer& other);	// Оператор копирования

	big_integer& operator=(big_integer&& other);	// Оператор перемещения

	friend big_integer operator+(big_integer& other1, big_integer& other2);	// Сложения больших чисел

	friend big_integer operator*(big_integer& other, int number);	// Умножение большого числа на int

	friend big_integer operator*(int number, big_integer& other);	// Умножение int на большое число

	friend std::ostream& operator<<(std::ostream& os, const big_integer& bi);	// Перегрузка оператора <<
};

