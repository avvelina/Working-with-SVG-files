/*SVG Project created by Alexandra Velina, 2020 */

#pragma once
#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <fstream>

#include "Shape.h"

class Line : public Shape
{
public:

	/* Constructor with parameters. */
	Line(double x1C = 0, double y1C = 0, double x2C = 0, double y2C = 0);

	/* Get Function Declarations for private variables */
	double getX1() const;
	double getY1() const;
	double getX2() const;
	double getY2() const;

	/**
	 * Set Function Declarations for private variables
	 */
	void setX1(double x1);
	void setY1(double y1);
	void setX2(double x2);
	void setY2(double y2);

	/* An output operator that prints the circle. */
	virtual ostream& Print(ostream& out) const;

	/* Enters the information in the file. */
	virtual void WriteFile(ofstream& of) const;

	/* A virtual function from Shape that returns a pointer to Shape, where a new object with the same data is created. */
	virtual Shape* Clone() const;

	/* Translates the line. */
	virtual void Translate(int v, int h);

	/* Virtual function checks if the line contains a circle. */
	virtual bool IsWithinCircle(double cx, double cy, double r) const;

	/* Virtual function checks if the line contains a rectangle. */
	virtual bool IsWithinRectangle(double x, double y, double width, double height) const;

private:

	double x1, y1, x2, y2;
};
#endif 
