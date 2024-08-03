/*SVG Project created by Alexandra Velina , 2020 */

#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>

#include "Shape.h"

class Circle : public Shape
{
public:

	/* Constructor with parameters. */
	Circle(double c = 0, double y = 0, double radius = 0, const char* f = "none");

	/* Copy constructor. */
	Circle(const Circle& circle);

	/* Redefine an operator. */
	Circle& operator=(const Circle& circle);

	/* Virtual destructor. */
	virtual ~Circle();

	/* Get Function Declarations for private variables */
	double getCx()        const;
	double getCy()        const;
	double getR()         const;
	const char* getFill() const;

	/* Set Function Declarations for private variables */
	void setCx(double cx);
	void setCy(double cy);
	void setR(double r);
	void setFill(const char* f);

	/* An output operator that prints the circle. */
	virtual ostream& Print(ostream& out) const;

	/* A virtual function from Shape that returns a pointer to Shape, where a new object with the same data is created. */
	virtual Shape* Clone() const;

	/* Enters the information in the file. */
	virtual void WriteFile(ofstream& of) const;

	/* Translates the circle. */
	virtual void Translate(int v, int h);

	/* Virtual function checks if the circle contains a cirlce. */
	virtual bool IsWithinCircle(double c_x, double c_y, double r) const;

	/* Virtual function checks if the circle contains a rectangle. */
	virtual bool IsWithinRectangle(double x, double y, double width, double height) const;

private:

	double _x, _y, r;
	char* fill;

	void Copy(const Circle& circle);
};
#endif
