/*SVG Project created by Alexandra Velina
 *		   Informarics, 2020
 */

#include <iostream>
#include "ShapeContainer.h"
using namespace std;

ShapeContainer::ShapeContainer() : capacity(16), size(0) // size = 16 -> by default
{
	shape = new Shape * [capacity];
}

ShapeContainer::ShapeContainer(const ShapeContainer& other)
{
	Copy(other);
}

void ShapeContainer::Copy(const ShapeContainer& other)
{
	capacity = other.capacity;
	size = other.size;
	shape = new Shape * [other.capacity]; // makes array of new shapes
	for (int i = 0; i < size; ++i)
	{
		shape[i] = other.shape[i]->Clone(); // redirects the current shape to another 
	}
}

ShapeContainer& ShapeContainer::operator=(const ShapeContainer& other)
{
	if (this == &other)
	{
		return *this;
	}

	for (int i = size - 1; i >= 0; --i)
	{
		RemoveElement(i);
	}
	Copy(other);
	return *this;
}

ShapeContainer::~ShapeContainer()
{
	for (int i = 0; i < size; ++i)
	{
		delete shape[i]; // iztriva kum koeto se sochi
	}
	delete[] shape;  // iztriva masiva
}

// Add a new figure. Create option.
void ShapeContainer::Add(Shape* newshape)
{
	if (capacity == size)
	{
		Resize();
	}
	shape[size] = newshape->Clone();
	++size;
}

// Resize the array. We don't have to clone the shapes because we work "inside".
void ShapeContainer::Resize()
{
	Shape** newshape = new Shape * [capacity*2];
	capacity *= 2;
	for (int i = 0; i < capacity; ++i)
	{
		shape[i] = newshape[i];
	}
	delete[] shape;
	shape = newshape;
}

// Erase option.
bool ShapeContainer::RemoveElement(int index)
{
	if (index < 0 || index >= size)
	{
		cout << " > There is no figure number " << index + 1 << "!\n";
		std::cout << "-----------------------------------------------------------\n";
		return false;
	}
	--size;
	for (int i = index; i < size; ++i)
	{
		Shape* newshape = shape[i];
		shape[i] = shape[i + 1]->Clone();
		delete newshape;
	}
	return true;
}

// Print option.
ostream& operator<<(ostream& out, const ShapeContainer& other)
{
	for (int i = 0; i < other.size; ++i)
	{
		out << " > " << (i + 1) << ". " << *other.shape[i] << "\n";
	}
	return out;
}

// Prints the information into the file.
void ShapeContainer::WriteFile(ofstream& of)const
{
	for (int i = 0; i < size; ++i)
	{
		shape[i]->WriteFile(of);
	}
}

// Translate option.
void ShapeContainer::Translate(int v, int h)
{
	for (int i = 0; i < size; ++i)
	{
		shape[i]->Translate(v, h);
	}
	cout << " > Translated all figures.\n";
}

// Within Circle option.
void ShapeContainer::IsWithinCircle(double cx, double cy, double r) const
{
	bool found = false;
	for (int i = 0; i < size; ++i)
	{
		if (shape[i]->IsWithinCircle(cx, cy, r))
		{
			found = true;
		}
	}
	if (found == false)
	{
		cout << " > No figures are located within circle "
			<< cx << " " << cy << " " << r << ".\n";
		std::cout << "-----------------------------------------------------------";
	}
}

// Within Rectangle option.
void ShapeContainer::IsWithinRectangle(double x, double y, double width, double height) const
{
	bool found = false;
	for (int i = 0; i < size; ++i)
	{
		if (shape[i]->IsWithinRectangle(x, y, width, height))
		{
			found = true;
		}
	}
	if (found == false)
	{
		cout << " > No figures are located within rectangle "
			<< x << " " << y << " " << width << " " << height << ".\n";
		std::cout << "-----------------------------------------------------------";
	}
}