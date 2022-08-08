#include <iostream>
#include "timeHeader.h"
#include "harmonogramHeader.h"
#include <string>

Harmonogram::Harmonogram()
{
	maxCount = 5;
	count = 0;
	schedule = new Time[maxCount];
}

Harmonogram::~Harmonogram()
{
	delete[] schedule;
}

Harmonogram::Harmonogram(const Harmonogram& _schedule1)
{
	maxCount = _schedule1.maxCount;
	count = _schedule1.count;
	schedule = new Time[maxCount];
	for (size_t i = 0; i < maxCount; i++)
	{
		schedule[i] = _schedule1.schedule[i];
	}
}

Harmonogram Harmonogram::operator=(Harmonogram& _schedule1)
{
	maxCount = _schedule1.maxCount;
	count = _schedule1.count;
	schedule = new Time[maxCount];
	for (size_t i = 0; i < maxCount; i++)
	{
		schedule[i] = _schedule1.schedule[i];
	}
	return *this;
}

void Harmonogram::init(int start)
{
	for (size_t i = start; i < maxCount; i++)
	{
		schedule[i] = 0;
	}
}

void Harmonogram::enlarge()
{
	maxCount *= 2;
	Time* temp = new Time[maxCount];
	for (size_t i = 0; i < count; i++)
	{
		temp[i] = schedule[i];
	}
	delete[] schedule;
	schedule = temp;
	init(count);
}

void Harmonogram::addToSchedule(Time _time1)
{
	if (count >= maxCount)
		enlarge();
	schedule[count++] = _time1;
}

Time Harmonogram::getTime(int i) // return -1 : wybrano zly indeks albo na indeksie nie ma zapisanego czasu
{
	if (i < 0 || i >= count)
		return -1;
	return schedule[i];
}

void Harmonogram::viewSchedule()
{
	for (size_t i = 0; i < count; i++)
	{
		std::cout << i + 1 << ")";
		getTime(i).viewTime();
	}
}

Time Harmonogram::sumSchedule()
{
	Time sum;
	for (size_t i = 0; i < count; i++)
	{
		sum = sum + schedule[i];
	}
	return sum;
}

void Harmonogram::nSchedules(int n)
{
	const int temp = count;
	if (temp < count)
	{
		return;
	}
	for (int i = 0; i < temp - n; i++)
	{
		if (maxCount > 0)
		{
			schedule[count - 1] = 0;
			count--;
		}
	}
}

void Harmonogram::rangeSchedule(Time _time1)
{
	while (sumSchedule() > _time1)
	{
		if (maxCount > 0)
		{
			schedule[count - 1] = 0;
			count--;
		}
	}
}

void Harmonogram::addTime(int additive, int index)
{
	schedule[index] += additive;
}