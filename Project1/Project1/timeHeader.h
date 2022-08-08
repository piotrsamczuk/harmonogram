#pragma once

class Time
{
	int data[3]; // 0- sekundy, 1- minuty, 2- godziny
public:
	void viewTime();
	void setTime(int val[]);
	void timeInput(int inputType = 0);
	void timeSwap();
	Time operator+(Time& _time1);
	Time operator+=(int _seconds);
	bool operator==(Time& _time1);
	bool operator!=(Time& _time1);
	bool operator<(Time& _time1);
	bool operator<=(Time& _time1);
	bool operator>(Time& _time1);
	bool operator>=(Time& _time1);
	Time();
	Time(int sec, int min, int hrs);
	Time(int sec, int min);
	Time(int sec);
};

