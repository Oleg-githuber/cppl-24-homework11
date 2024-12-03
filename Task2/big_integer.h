#pragma once

#include <iostream>
#include <string>
#include <exception>

#define DIGITAL_BOUND 48

class big_integer
{
private:
	std::string number{};	// ������ ��� �������� �������� �����

public:
	big_integer(std::string str);	// �����������, ����������� ������

	big_integer(big_integer&& other);	// ����������� �����������

	big_integer(big_integer& other);	// ����������� �����������

	big_integer& operator=(big_integer& other);	// �������� �����������

	big_integer& operator=(big_integer&& other);	// �������� �����������

	friend big_integer operator+(big_integer& other1, big_integer& other2);	// �������� ������� �����

	friend big_integer operator*(big_integer& other, int number);	// ��������� �������� ����� �� int

	friend big_integer operator*(int number, big_integer& other);	// ��������� int �� ������� �����

	friend std::ostream& operator<<(std::ostream& os, const big_integer& bi);	// ���������� ��������� <<
};

