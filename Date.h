#pragma once
#include <iostream>
#include <fstream>

class Date {
public:
	int day, month, year;
	void printDate();
	void printDate(std::ofstream& fout);
	void printDate(std::fstream& fout);

	bool operator<(Date b);
	bool operator>(Date b);
};

