/*SVG Project created by Alexandra Velina
 *		   Informarics, 2020
 */

#include <cstring>
#include <cmath>
#include <iostream>

#include "Circle.h"
using namespace std;

Circle::Circle(double c, double y, double radius, const char* f)
	:_x(c), _y(y), r(radius)
{
	fill = new char[strlen(f) + 1];
	strcpy(fill, f);
}

Circle::Circle(const Circle& circle) : Shape(circle)
{
	Copy(circle);
}

Circle& Circle::operator=(const Circle& circle)
{
	if (this == &circle)
	{
		return *this;
	}
	Shape::operator=(circle);
	delete[] fill;
	Copy(circle);
	return *this;
}

Circle::~Circle()
{
	delete[] fill;
}

double Circle::getCx()	      const
{
	return _x;
}
double Circle::getCy()		  const
{
	return _y;
}
double Circle::getR()         const
{
	return r;
}
const char* Circle::getFill() const
{
	return fill;
}

void Circle::setCx(double _x)
{
	this->_x = _x;
}
void Circle::setCy(double _y)
{
	this->_y = _y;
}
void Circle::setR(double r)
{
	this->r = r;
}
void Circle::setFill(const char* f)
{
	delete[] fill;
	fill = new char[strlen(f) + 1];
	strcpy(fill, f);
}

ostream& Circle::Print(ostream& out)const
{
	Shape::Print(out);
	out << "circle " << _x << " " << _y << " " << r << " " << fill;
	return out;
}

void Circle::Copy(const Circle& circle)
{
	_x = circle._x;
	_y = circle._y;
	r = circle.r;
	fill = new char[strlen(circle.fill) + 1];
	strcpy(fill, circle.fill);
}

void Circle::WriteFile(ofstream& of) const
{
	of << "  " << "<circle cx=\"" << _x
		<< "\" cy=\"" << _y
		<< "\" r=\"" << r
		<< "\" fill=\"" << fill
		<< "\" />\n";
}

void Circle::Translate(int v, int h)
{
	_x += h;
	_y += v;
}

bool Circle::IsWithinCircle(double x, double y, double r) const
{
	double d = sqrt((this->_x - x) * (this->_x - x) + (this->_y - y) * (this->_y - y));
	if ((d + this->r) < r)
	{
		cout << *this << " is inside circle " << x << " " << y << " " << r << "!\n";
		return true;
	}
	return false;
}

bool Circle::IsWithinRectangle(double x, double y, double width, double height) const
{
	if (((_x > x && _x < x + width) && (_y > y && _y < y + height)) &&
		((_x + r > x && _x + r < x + width) && (_y > y && _y < y + height)) &&
		((_x - r > x && x - r < x + width) && (y > y && y < y + height)) &&
		((_x > x && x < x + width) && (y + r > y && y + r < y + height)) &&
		((_x > x && x < x + width) && (y - r > y && y - r < y + height)))
	{
		cout << *this << " is inside rectangle " << x << " " << y
			<< " " << width << " " << height << "!\n";
		return true;
	}
	return false;
}

Shape* Circle::Clone() const
{
	return new Circle(_x, _y, r, fill);
}