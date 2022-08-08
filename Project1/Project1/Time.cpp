#include <iostream>
#include "timeHeader.h"
#include "harmonogramHeader.h"
#include <string>

void Time::timeSwap()
{
	if (data[0] >= 60)
	{
		data[1] += data[0] / 60;
		data[0] %= 60;
	}
	if (data[1] >= 60)
	{
		data[2] += data[1] / 60;
		data[1] %= 60;
	}
}

Time::Time()
{
	for (int i = 0; i < 3; i++)
	{
		data[i] = 0;
	}
}

Time::Time(int sec, int min, int hrs)
{
	data[0] = sec;
	data[1] = min;
	data[2] = hrs;
	timeSwap();
}

Time::Time(int sec, int min)
{
	data[0] = sec;
	data[1] = min;
	data[2] = 0;
	timeSwap();
}

Time::Time(int sec)
{
	data[0] = sec;
	data[1] = 0;
	data[2] = 0;
	timeSwap();
}

Time Time::operator+(Time& _time1)
{
	Time temp = _time1;
	temp.data[0] += data[0];
	temp.data[1] += data[1];
	temp.data[2] += data[2];
	timeSwap();
	return temp;
}

Time Time::operator+=(int _seconds)
{
	data[0] += _seconds;
	timeSwap();
	return *this;
}

bool Time::operator==(Time& _time1)
{
	if ((data[0] == _time1.data[0]) && (data[1] == _time1.data[1]) && (data[2] == _time1.data[2]))
		return true;
	else
		return false;
}

bool Time::operator!=(Time& _time1)
{
	if (Time::operator==(_time1) == true)
		return false;
	else
		return true;
}

bool Time::operator<(Time& _time1)
{
	if (data[2] < _time1.data[2])
		return true;
	else if(data[2] != _time1.data[2])
		return false;

	if (data[1] < _time1.data[1])
		return true;
	else if(data[1] != _time1.data[1])
		return false;

	if (data[0] < _time1.data[0])
		return true;
	else
		return false;
}

bool Time::operator>(Time& _time1)
{
	if (Time::operator<(_time1) == true)
		return false;
	else
		return true;
}

bool Time::operator<=(Time& _time1)
{
	if ((*this < _time1) || (*this == _time1))
		return true;
	else
		return false;
}

bool Time::operator>=(Time& _time1)
{
	if (Time::operator<=(_time1) == true)
		return false;
	else
		return true;
}

int charCheck(std::string input) //jesli zwraca -1, to znaczy ze wprowadzony string zawiera w sobie cos innego niz cyfry
{
	for (int i = 0; i < input[i] != '\0'; i++)
	{
		if (!isdigit(input[i]))
			return -1;
	}
	return 1;
}

void Time::setTime(int val[])
{
	for (int i = 0; i < 3; i++)
		data[i] = val[i];
}

void Time::viewTime()
{
	std::cout << "Czas (HRS:MIN:SEC): " << data[2] << ":" << data[1] << ":" << data[0] << std::endl;
}

void Time::timeInput(int inputType) //inputtype - 0 sec, min, hrs; 1 sec, mins; 2 sec
{
	int val[3] = { 0, 0, 0 }; // sekundy, minuty, godziny
	std::string sec, min, hrs;
	bool secChk = 0, minChk = 0, hrsChk = 0;
	while (secChk == 0)
	{
		std::cout << "Wprowadz sekundy: " << std::endl;
		std::cin >> sec;
		if (charCheck(sec) == 1)
		{
			val[0] = stoi(sec);
			secChk = 1;
		}
		else
			std::cout << "Wprowadzono niedozwolony znak." << std::endl;
	}
	while (minChk == 0 && inputType != 2)
	{
		std::cout << "Wprowadz minuty: " << std::endl;
		std::cin >> min;
		if (charCheck(min) == 1)
		{
			val[1] += stoi(min);
			minChk = 1;
		}

		else
			std::cout << "Wprowadzono niedozwolony znak." << std::endl;
	}
	while (hrsChk == 0 && inputType == 0) 
	{
		std::cout << "Wprowadz godziny: " << std::endl;
		std::cin >> hrs;
		if (charCheck(hrs) == 1)
		{
			val[2] += stoi(hrs);
			hrsChk = 1;
		}
		else
			std::cout << "Wprowadzono niedozwolony znak." << std::endl;
		timeSwap();
	}
	Time::setTime(val);
}