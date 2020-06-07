/*SVG Project created by Alexandra Velina
 *		   Informarics, 2020
 */

#include <iostream>
#include <fstream>
#include <string>

#include "Commands.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "ShapeContainer.h"

using namespace std;

const unsigned MAX_OPTION_SIZE = 11;
const unsigned MAX_FUGIRE_SIZE = 11;
const unsigned MAX_SHAPE_SIZE = 11;
const unsigned MAX_FILL_SIZE = 26;


void Commands::PrintMenu()
{
	std::cout << "-----------------------------------------------------------\n";
	std::cout << "		     SVG PROJECT									 \n";
	std::cout << "-----------------------------------------------------------\n";
	std::cout << "		  Avaiable commands:								 \n";
	std::cout << "			> Open											 \n";
	std::cout << "			> Close											 \n";
	std::cout << "			> Save											 \n";
	std::cout << "			> Saveas										 \n";
	std::cout << "			> Help											 \n";
	std::cout << "			> Exit											 \n";
	std::cout << "-----------------------------------------------------------\n";
}

void Commands::UserMenu()
{
	ShapeContainer shape;
	do
	{
		char option[MAX_OPTION_SIZE];
		cout << "Enter your option > "; cin >> option;
	
		// Function to open a file.
		if (!strcmp(option, "Open"))
		{
			ifstream file("figure.svg", ios::_Nocreate);
			if (!file.is_open())
			{
				std::cout << " > Can't open file for reading...\n";
				std::cout << "-----------------------------------------------------------\n";
			}
			else
			{
				std::cout << " > Successfully opened figure.svg!\n";
				std::cout << "-----------------------------------------------------------\n";
			}
			continue;
		}

		// Function to close a file.
		else if (!strcmp(option, "Close"))
		{
			ofstream file;
			file.open("figure.svg", ios::in);
			std::cout << " > File successfully closed!\n";
			std::cout << "-----------------------------------------------------------\n";
			file.close();
		}

		// Function that saves the changes in the program.
		else if (!strcmp(option, "Save"))
		{
			ofstream file;
			file.open("figure.svg", ios::out);
			file << "<?xml version=\"1.0\" standalone=\"no\"?>" << "\n"
				<< "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << "\n"
				<< "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << "\n"
				<< "<svg>" << "\n";

			shape.WriteFile(file);
			file << "</svg>";

			std::cout << " > File successfully saved!\n";
			std::cout << "-----------------------------------------------------------\n";
		}

		// Function that saves the changes to another user - defined file.
		else if (!strcmp(option, "Saveas"))
		{
			string NameToSaveAs;
			cout << "Save as (give name for file): "; cin >> NameToSaveAs;
			ofstream file;
			file.open(NameToSaveAs, ios::app);
			//NameToSaveAs += ".svg";
			file << "<?xml version=\"1.0\" standalone=\"no\"?>" << "\n"
				<< "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << "\n"
				<< "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << "\n"
				<< "<svg>" << "\n";

			shape.WriteFile(file);
			file << "</svg>";
			std::cout << " > File successfully saved as " << NameToSaveAs << "!\n";
			std::cout << "-----------------------------------------------------------\n";
		}

		// Function that displays brief information about the commands supported by the program.
		else if (!strcmp(option, "Help"))
		{
			cout << "-----------------------------------------------------------\n";
			cout << "	>> The following commands are supported: <<			    \n";
			cout << "-----------------------------------------------------------\n";
			cout << "	> Open	   opens file.									\n";
			cout << "	> Close	   closes currently opened file.				\n";
			cout << "	> Save	   saves the currently open file.				\n";
			cout << "	> Saveas   saves the currently open file in <file>.		\n";
			cout << "	> Help	   prints this information.						\n";
			cout << "	> Exit	   exists the program.							\n";
			cout << "-----------------------------------------------------------\n";
			cout << "		>> SVG Commands: <<									\n";
			cout << "-----------------------------------------------------------\n";
			cout << "	> Print	     prints all figures.						\n";
			cout << "	> Create     creates a new figure.						\n";
			cout << "	> Erase      remove figure with sequence number.		\n";
			cout << "	> Translate  translates all figures.					\n";
			cout << "-----------------------------------------------------------\n";
		}

		// Function that terminates the program.
		else if (!strcmp(option, "Exit"))
		{
			std::cout << " > Exiting program...\n";
			std::cout << "-----------------------------------------------------------\n";
			return;
		}

		// Function that prints the shapes.
		else if (!strcmp(option, "Print"))
		{
			std::cout << shape;
			std::cout << "-----------------------------------------------------------\n";
		}

		// Function that creates new shapes.
		else if (!strcmp(option, "Create"))
		{
			char figure[MAX_SHAPE_SIZE];
			std::cout << "> What shape do you what to create <rectangle>, <circle> or <line>? \n";
			std::cout << "> Type the shape you want to create: "; cin >> figure;
			if (!strcmp(figure, "Line"))
			{
				double x1, y1, x2, y2;
				std::cout << " > Enter x1 coordinates: "; cin >> x1; x1 = fabs(x1);
				std::cout << " > Enter x2 coordinates: "; cin >> x2; x2 = fabs(x2);
				std::cout << " > Enter y1 coordinates: "; cin >> y1; y1 = fabs(y1);
				std::cout << " > Enter y2 coordinates: "; cin >> y2; y2 = fabs(y2);
				Line* line = new Line(x1, y1, x2, y2); 
				shape.Add(line);
				delete line;
				std::cout << "> Successfully created line!\n";
				std::cout << "-----------------------------------------------------------\n";
				continue;
			}
			else if (!strcmp(figure, "Circle"))
			{
				char fill[MAX_FILL_SIZE];
				double cx, cy, r;
				std::cout << " > Enter x coordinates: "; cin >> cx;   cx = fabs(cx);
				std::cout << " > Enter y coordinates: "; cin >> cy;   cy = fabs(cy);
				std::cout << " > Enter radious: ";       cin >> r;    r  = fabs(r);
				std::cout << " > Enter fill: ";          cin >> fill;
				Circle* circle = new Circle(cx, cy, r, fill);
				shape.Add(circle);
				delete circle;
				std::cout << "> Successfully created circle!\n";
				std::cout << "-----------------------------------------------------------\n";
				continue;
			}
			else if (!strcmp(figure, "Rectangle"))
			{
				char fill[MAX_FILL_SIZE];
				double x, y, width, height;
				std::cout << " > Enter x coordinates: "; cin >> x;      x = fabs(x);
				std::cout << " > Enter y coordinates: "; cin >> y;      y = fabs(y);
				std::cout << " > Enter width: ";         cin >> width;  width = fabs(width);
				std::cout << " > Enter heigth: ";        cin >> height; height = fabs(height);
				std::cout << " > Enter fill: ";          cin >> fill;
				Rectangle* rect = new Rectangle(x, y, width, height, fill);
				shape.Add(rect);
				delete rect;
				std::cout << "> Successfully created rectangle!\n";
				std::cout << "-----------------------------------------------------------\n";
				continue;
			}
			else if (figure!= "Circle" && figure != "Rectangle" && figure != "Line")
			{
				std::cout << "> Wrong input! Type again!\n";
				std::cout << "-----------------------------------------------------------\n";
				continue;
			}
		}

		// Function that erases shape with id.
		else if (!strcmp(option, "Erase"))
		{
			int id;
			std::cout << "> Enter id of the figure: "; cin >> id;
			if (shape.RemoveElement(id - 1))
			{
				std::cout << " > Erased figure " << id << ".\n";
				std::cout << "-----------------------------------------------------------\n";
			}
		}

		// Function that translates all the figures.
		else if (!strcmp(option, "Translate"))
		{
			int h, v;
			std::cout << "> Enter vertical: ";	 cin >> v;
			std::cout << "> Enter horizontal: "; cin >> h;
			shape.Translate(v, h);
			std::cout << "-----------------------------------------------------------\n";
		}

		// Function that checks if a figure is completely contained in a region.
		else if (!strcmp(option, "Within"))
		{
			{
				char figures[MAX_FUGIRE_SIZE];
				std::cout << "> Which figure do you want to within: "; cin >> figures;
				if (!strcmp(figures, "Circle"))
				{
					double cx, cy, r;
					std::cout << " > cx: "; cin >> cx;
					std::cout << " > cy: "; cin >> cy;
					std::cout << " > r: ";  cin >> r;
					shape.IsWithinCircle(cx, cy, r);
				}
				if (!strcmp(figures, "Rectangle"))
				{
					double x, y, width, height;
					std::cout << " > x: ";      cin >> x;
					std::cout << " > y: ";	    cin >> y;
					std::cout << " > width: ";  cin >> width;
					std::cout << " > height: "; cin >> height;
					shape.IsWithinRectangle(x, y, width, height);
				}
			}
			std::cout << "\n";
		}

	} while (true);
};
