#include "Date.h"

void Date::printDate() {
	std::cout << this->day << ' ' << this->month << ' ' << this->year;

}

void Date::printDate(std::ofstream& fout) {
	fout << this->day << ' ' << this->month << ' ' << this->year;
}

void Date::printDate(std::fstream& fout) {
	fout << this->day << ' ' << this->month << ' ' << this->year;
}

bool Date::operator<(Date b) {
	if (this->year < b.year)
		return 1;

	else if (this->year == b.year) {
		if (this->month < b.month)
			return 1;

		else if (this->month == b.year) {
			if (this->day < b.day)
				return 1;
		}
	}

	return 0;
}

bool Date::operator>(Date b) {
	if (this->year > b.year)
		return 1;

	else if (this->year == b.year) {
		if (this->month > b.month)
			return 1;

		else if (this->month == b.year) {
			if (this->day > b.day)
				return 1;
		}
	}

	return 0;
}