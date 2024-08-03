/*SVG Project created by Alexandra Velina, 2020 */

#pragma once
#ifndef SHAPEARR_H
#define SHAPEARR_H

#include <iostream>
#include "Shape.h"

 /* A class that is an array of pointers to objects from classes inherited by Shape.
  * The container should generally be able to do the following things:
  * - add a shape
  * - access a shape
  * - print them
  * - saves them to a file.
  * - remove a shape
  * - translate a shape
  * - within circle/rectangle */
class ShapeContainer
{
public:

	/* Default constructor. */
	ShapeContainer();

	/* Copy constructor. */
	ShapeContainer(const ShapeContainer& other);

	/* Redefine an operator. */
	ShapeContainer& operator=(const ShapeContainer& e);

	/* Destructor. */
	~ShapeContainer();

	/* Function adding an element to the array. */
	void Add(Shape* newshape);

	/* Function removes an element from an array by a given index. ("Erase" command) */
	bool RemoveElement(int index);

	/* Saves the elements of the array to a file. */
	void WriteFile(ofstream& outf) const;

	/* Translates the elements of the array. ("Translate" option) */
	void Translate(int v, int h);

	/* Find which elements of the array are contained entirely in a given circle. */
	void IsWithinCircle(double cx, double cy, double r) const;

	/* Search for which elements of the array are contained entirely in a given rectangle. */
	void IsWithinRectangle(double x, double y, double width, double height) const;

	/* Prints the array on the screen. */
	friend ostream& operator<<(ostream& out, const ShapeContainer& other);

private:

	Shape** shape;
	int capacity, size;

	/* Methods */
	void Resize();

	void Copy(const ShapeContainer& e);
};
#endif
