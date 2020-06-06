/*SVG Project created by Alexandra Velina
 *		   Informarics, 2020
 */

#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <fstream>

#include "Shape.h"

class Rectangle : public Shape
{
public:

	/**
	 * Constructor with parameters.
	 */
	Rectangle(double xC = 0, double yC = 0, double w = 0, double h = 0, const char* f = "none");

	/**
	 * Copy constructor.
	 */
	Rectangle(const Rectangle& rect);

	/**
	 * Redefine an operator.
	 */
	Rectangle& operator= (const Rectangle& rect);

	/**
	 * Virtual destructor.
	 */
	virtual ~Rectangle();

	/**
	 * Get Function Declarations for private variables
	 */
	double getX()         const;
	double getY()         const;
	double getWidth()     const;
	double getHeight()    const;
	const char* getFill() const;

	/**
	 * Set Function Declarations for private variables
	 */
	void setX(double x);
	void setY(double y);
	void setWidth(double width);
	void setHeight(double height);
	void setFill(const char* f);

	/**
	 * An output operator that prints the circle.
	 */
	virtual ostream& Print(ostream& out) const;

	/**
	 * Enters the information in the file.
	 */
	virtual void WriteFile(ofstream& of) const;

	/**
	 * A virtual function from Shape that returns a pointer to Shape,
	 * where a new object with the same data is created.
	 */
	virtual Shape* Clone() const;

	/**
	 * Translates the circle.
	 */
	virtual void Translate(int v, int h);

	/**
	 * Virtual function checks if the rectangle contains a cirlce.
	 */
	virtual bool IsWithinCircle(double cx, double cy, double r) const;

	/**
	 * Virtual function checks if the rectangle contains a rectangle.
	 */
	virtual bool IsWithinRectangle(double x, double y, double width, double height) const;

private:

	double x, y, width, height;
	char* fill;

	void Copy(const Rectangle& rect);
};
#endif