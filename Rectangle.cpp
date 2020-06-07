/*SVG Project created by Alexandra Velina
 *		   Informarics, 2020
 */

#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(double xC, double yC, double w, double h, const char* f)
	:x(xC), y(yC), width(w), height(h)
{
	fill = new char[strlen(f) + 1];
	strcpy(fill, f);
}
Rectangle::Rectangle(const Rectangle& rect) : Shape(rect)
{
	Copy(rect);
}
Rectangle& Rectangle::operator= (const Rectangle& rect)
{
	if (this == &rect)
	{
		return *this;
	}
	Shape::operator=(rect);
	delete[] fill;
	Copy(rect);
	return *this;
}
Rectangle::~Rectangle()
{
	delete[] fill;
}

double Rectangle::getX()		 const
{
	return x;
}
double Rectangle::getY()		 const
{
	return y;
}
double Rectangle::getWidth()	 const
{
	return width;
}
double Rectangle::getHeight()	 const
{
	return height;
}
const char* Rectangle::getFill() const
{
	return fill;
}

void Rectangle::setX(double x)
{
	this->x = x;
}
void Rectangle::setY(double y)
{
	this->y = y;
}
void Rectangle::setHeight(double height)
{
	this->height = height;
}
void Rectangle::setWidth(double width)
{
	this->width = width;
}
void Rectangle::setFill(const char* f)
{
	delete[] fill;
	fill = new char[strlen(f) + 1];
	strcpy(fill, f);
}

ostream& Rectangle::Print(ostream& out) const
{
	Shape::Print(out);
	out << "rectangle " << x << " " << y << " " << width << " " << height << " " << fill;
	return out;
}

void Rectangle::Copy(const Rectangle& rect)
{
	x = rect.x;
	y = rect.y;
	width = rect.width;
	height = rect.height;
	fill = new char[strlen(rect.fill) + 1];
	strcpy(fill, rect.fill);
}

void Rectangle::WriteFile(ofstream& of) const
{
	of << "  " << "<rect x=\"" << x
		<< "\" y=\"" << y
		<< "\" width=\"" << width
		<< "\" height=\"" << height
		<< "\" fill=\"" << fill
		<< "\" />\n";
}

void Rectangle::Translate(int v, int h)
{
	x += h;
	y += v;
}

bool Rectangle::IsWithinCircle(double cx, double cy, double r) const
{
	// x, y, width, height -> koordinati na pravougulnika, koito e suzdaden (create)
	// cx, cy, r -> ot opciyata Within
	if (((x - cx) * (x - cx) + (y - cy) * (y - cy) < r * r)
		&& (((x + width) - cx) * ((x + width) - cx) +
			((y + height) - cy) * ((y + height) - cy) < r * r))
	{
		cout << *this << " is inside circle " << cx << " " << cy << " " << r << "!" << endl;
		return true;
	}
	return false;
}
bool Rectangle::IsWithinRectangle(double x, double y, double width, double height) const
{
	// this->x, this->y, this->width, this->height -> koordinati na pravougulnika, koito e suzdaden (create)
	// x, y, width, height -> ot opciyata Within
	if (((this->x + this->width) < (x + width)) && (this->x > x)
		&& (this->y > y) && ((this->y + this->height) < (y + height)))
	{
		cout << *this << " is inside rectangle " << x << " "
			<< y << " " << width << " " << height << "!" << endl;
		return true;
	}
	return false;
}

Shape* Rectangle::Clone() const
{
	return new Rectangle(x, y, width, height, fill);
}
