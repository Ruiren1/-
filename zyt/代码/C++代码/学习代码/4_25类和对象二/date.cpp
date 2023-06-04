#include"date.h"

Date::Date(int year, int month, int day)
{
	if (month > 0 && month < 13
		&& day > 0 && day <= Getmonthday(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "非法日期" << endl;
		assert(false);
	}
}

bool Date::operator<(const Date& x) const
{
	if (_year < x._year)
	{
		return true;
	}
	else if (_year == x._year && _month < x._month)
	{
		return true;
	}
	else if (_year == x._year && _month == x._month && _day < x._day)
	{
		return true;
	}

	return false;
}
bool Date::operator==(const Date& x) const
{
	return _year == x._year
		&& _month == x._month
		&& _day == x._day;
}

bool Date::operator<=(const Date& x) const
{
	return *this < x || *this == x;
}

bool Date::operator>(const Date& x) const
{
	return !(*this <= x);
}

bool Date::operator>=(const Date& x) const
{
	return !(*this < x);
}

bool Date::operator!=(const Date& x) const
{
	return !(*this == x);
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;
	while (_day > Getmonthday(_year, _month))
	{
		_day -= Getmonthday(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator+(int day)  const
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}

	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}

		_day += Getmonthday(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day) const
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;
}

ostream& operator<<(ostream& out,const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}
istream& operator>>(istream& in,Date& d)
{
	int year, month, day;
	in >> year >> month >> day;

	if (month > 0 && month < 13
		&& day > 0 && day <= d.Getmonthday(year, month))
	{
		d._year = year;
		d._month = month;
		d._day = day;
	}
	else
	{
		cout << "非法日期" << endl;
		assert(false);
	}
	return in;
}
