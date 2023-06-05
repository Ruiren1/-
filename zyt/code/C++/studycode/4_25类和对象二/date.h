#pragma once
#include <iostream>
#include<assert.h>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);

	friend istream& operator>>(istream& in, Date& d);

private:
	int _year;
	int _month;
	int _day;

public:


	int  Get_day()
	{
		return _day;
	}
	int Get_month()
	{
		return _month;
	}
	int Get_year()
	{
		return _year;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	int Getmonthday(int year,int month)
	{
		static int monthday[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
		{
			return monthday[month];
		}
	}
	Date(){}
	Date(int year, int month, int day);
	Date(const Date& B)
	{
		
		_day = B._day;
		_month = B._month;
		_year = B._year;
	}

	bool operator<(const Date& x) const;
	bool operator==(const Date& x) const;
	bool operator<=(const Date& x) const;
	bool operator>(const Date& x) const;
	bool operator>=(const Date& x) const;
	bool operator!=(const Date& x) const;
	Date& operator+=(int day);
	Date operator+(int day) const;

	Date& operator-=(int day);
	Date operator-(int day) const;
	int operator-(const Date& d) const;
	Date& operator=(const Date& d)
	{
		if (!(this == &d))
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}

	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}
	Date operator--(int)
	{
		Date temp = *this;
		_day -= 1;
		return temp;
	}


};