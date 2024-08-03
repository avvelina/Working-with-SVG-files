/*SVG Project created by Alexandra Velina, 2020 */

#include <iostream>
#include "Shape.h"
using namespace std;

ostream& operator<<(ostream& os, const Shape& shape)
{
	return shape.Print(os);
}

ostream& Shape::Print(ostream& os)const
{
	return os;
}

Shape::~Shape() {}
