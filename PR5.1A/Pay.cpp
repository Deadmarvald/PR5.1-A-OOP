#include "Pay.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Pay::SetFirst(double f)
{
	if (f < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		first = f;
	}
}

void Pay::SetSecond(int s)
{
	if (s < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		second = s;
	}
}

Pay::Pay()
{
	first = 0;
	second = 0;
}

Pay::Pay(double f = 0, int s = 0)
{
	if (f < 0 || s < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0!");
	}
	else
	{
		SetFirst(f);
		SetSecond(s);
	}
}

Pay::Pay(const Pay& x)
{
	first = x.first;
	second = x.second;
}

Pay::~Pay()
{ }

Pay& Pay::operator =(const Pay& x)
{
	first = x.first;
	second = x.second;

	return *this;
}

Pay::operator string () const
{
	stringstream ss;
	ss << " First = " << first << endl;
	ss << " Second = " << second << endl;

	return ss.str();
}

Pay operator +(const Pay& x, const Pay& y)
{
	return Pay(x.first + y.first, x.second + y.second);
}

Pay operator -(const Pay& x, const Pay& y)
{
	return Pay(x.first - y.first, x.second - y.second);
}

Pay operator *(const Pay& x, const Pay& y)
{
	return Pay(x.first * y.first, x.second * y.second);
}

Pay operator /(const Pay& x, const Pay& y)
{
	return Pay(x.first / y.first, x.second / y.second);
}

Pay operator ^(const Pay& x, const Pay& y)
{
	return Pay(pow(x.first, y.first), pow(x.second, y.second));
}

ostream& operator << (ostream& out, const Pay& x)
{
	out << string(x);

	return out;
}

istream& operator >> (istream& in, Pay& x)
{
	int f;
	double s;

	cout << " First = "; in >> f;
	cout << " Second = "; in >> s;

	if (f < 0 || s < 0)
	{
		throw MyException("Numbers must be bigger than 0!!!");
	}
	else
	{
		x.SetFirst(f);
		x.SetSecond(s);
	}
	cout << endl;

	return in;
}

Pay& Pay::operator ++()
{
	first++;

	return *this;
}

Pay& Pay::operator --()
{
	first--;

	return *this;
}

Pay Pay::operator ++(int)
{
	Pay t(*this);
	second++;

	return t;
}

Pay Pay::operator --(int)
{
	Pay t(*this);
	second--;
	return t;
}

double Pay::Summa(int s)
{
	return first / second * s;
}