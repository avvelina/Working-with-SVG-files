/*SVG Project created by Alexandra Velina
 *		   Informarics, 2020
 */

#include <iostream>
#include "Line.h"
using namespace std;

Line::Line(double x1C, double y1C, double x2C, double y2C)
	:x1(x1C), y1(y1C), x2(x2C), y2(y2C) {}


double Line::getX1() const
{
	return x1;
}
double Line::getY1() const
{
	return y1;
}
double Line::getX2() const
{
	return x2;
}
double Line::getY2() const
{
	return y2;
}

void Line::setX1(double x1)
{
	this->x1 = x1;
}
void Line::setY1(double y1)
{
	this->y1 = y1;
}
void Line::setX2(double x2)
{
	this->x2 = x2;
}
void Line::setY2(double y2)
{
	this->y2 = y2;
}

ostream& Line::Print(ostream& out) const
{
	Shape::Print(out);
	out << "line " << x1 << " " << y1 << " " << x2 << " " << y2;
	return out;
}

void Line::WriteFile(ofstream& of) const
{
	of << "  " << "<line x1=\"" << x1
		<< "\" y1=\"" << y1
		<< "\" x2=\"" << x2
		<< "\" y2=\"" << y2
		<< "\" />\n";
}

void Line::Translate(int v, int h)
{
	x1 += h;
	x2 += h;
	y1 += v;
	y2 += v;
}

bool Line::IsWithinCircle(double cx, double cy, double r) const
{
	// x1, y1, x2, y2, r -> koordinati na liniyata, koyato e suzdadena (create)
	// cx, cy, r -> ot opciyata Within
	if (((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) < r * r)
		&& ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r * r))
	{
		cout << *this << " is inside circle " << cx << " " << cy << " " << r << "!" << endl;
		return true;
	}
	return false;
}

bool Line::IsWithinRectangle(double x, double y, double width, double height) const
{
	// x1, y1, x2, y2, r -> koordinati na liniyata, koyato e suzdadena (create)
	// x, y, width, height -> ot opciyata Within
	if (((x1 > x && x1 < x + width) && (y1 > y && y1 < y + height))
		&& ((x2 > x && x2 < x + width) && (y2 > y && y2 < y + height)))
	{
		cout << *this << " is inside rectangle " << x << " "
			<< y << " " << width << " " << height << "!" << endl;
		return true;
	}
	return false;
}

Shape* Line::Clone() const
{
	return new Line(x1, y1, x2, y2);
}
