/*SVG Project created by Alexandra Velina
 *		   Informarics, 2020
 */

#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

/**
 * Abstract class, that represents a shape. It is used as a foundation for the other shapes.
 */
class Shape
{
public:

	/**
	 * An output operator.
	 */
	friend ostream& operator<<(ostream& os, const Shape& shape);

	/**
	 * A virtual function that helps us use the output operator in inherited classes as well.
	 */
	virtual ostream& Print(ostream& os) const;

	/**
	 * A virtual function that helps us save objects from inherited classes to a file.
	 */
	virtual void WriteFile(ofstream& of) const = 0;


	/*SHAPE-MANIPULATING FUNCTIONS*/

   /**
	* A virtual function that helps us translate objects of any inherited class.
	*/
	virtual void Translate(int v, int h) = 0;
	
	 /**
	  * A virtual function that helps us search for
	  * an object from any inherited class in a given circle.
	  */
	virtual bool IsWithinCircle(double cx, double cy, double r) const = 0;

	/**
	 * A virtual function that helps us search for an object
	 * of any inherited class in a given rectangle.
	 */
	virtual bool IsWithinRectangle(double x, double y, double width, double height) const = 0;

	/**
	 * A virtual function from Shape that returns a pointer to Shape,
	 * where a new object with the same data is created.
	 */
	virtual Shape* Clone() const = 0;

	/**
	 * Virtual destructor.
	 */
	virtual ~Shape();
};
#endif
