#include <iostream>
using namespace std;

class Date {
public:
	Date(int d = 1, int m = 1, int y = 1900);
	Date(const Date& oth);
	~Date();
	void setDate(int d = 1, int m = 1, int y = 1800);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay() const {
		return day;
	}
	int getMonth() const {
		return month;
	}
	int getYear() const {
		return year;
	}
	void increaseDay();
	void compareDate(const Date& othDate);
	void displayDate();
private:
	int year, month, day;
	const int monthDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const string monthStrings[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
};

Date::Date(int d, int m, int y) {
	setDate(d, m, y);
}

Date::~Date() {
	cout << "Date Destroyed" << endl;
}

Date::Date(const Date& oth) {
	day = oth.day;
	month = oth.month;
	year = oth.year;
	cout << "Date Copied to target" << endl;
}

void Date::setDay(int d) {
	if (d >= 1 && d <= monthDays[month - 1])
		day = d;
	else
		day = 1;
}

void Date::setMonth(int m) {
	if (m >= 1 && m <= 12)
		month = m;
	else
		month = 1;
}

void Date::setYear(int y) {
	if (y >= 1900)
		year = y;
	else
		year = 1900;
}

void Date::setDate(int d, int m, int y) {
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::displayDate() {
	cout << day << " " << monthStrings[month - 1] << " " << year << endl;
}

void Date::increaseDay() {
	if (day < monthDays[month - 1])
		day++;
	else {
		day = 1;
		if (month == 12) {
			month = 1;
			year++;
		}
		else if (month < 12) {
			month++;
		}
	}
}

void Date::compareDate(const Date& othDate) {
	long firstDay;
	long secondDay;

	firstDay = year * 365 + month * 30 + day;
	secondDay = othDate.year * 365 + othDate.month * 30 + othDate.day;

	if (firstDay > secondDay)
		cout << "Firt Day is greater" << endl;
	else if(firstDay < secondDay)
		cout << "Second Day is greater" << endl;
	else
		cout << "Equal" << endl;
}