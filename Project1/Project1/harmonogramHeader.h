#pragma once

class Harmonogram
{
	Time* schedule;
	int maxCount;
	int count;
	void init(int start);
	void enlarge();
public:
	void addToSchedule(Time _time1);
	Time getTime(int i);
	Time sumSchedule();
	void viewSchedule();
	void nSchedules(int n);
	void rangeSchedule(Time _time1);
	Harmonogram operator=(Harmonogram& _schedule1);
	Harmonogram();
	~Harmonogram();
	Harmonogram(const Harmonogram& _schedule1);
	void addTime(int additive, int index);
};