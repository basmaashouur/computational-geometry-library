#include "Tools.h"

void Tools::wrongChoice(string cho)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << cho <<  "\n";
	cout << "Please enter a correct choice\n\n";

}

void Tools::clearScreen()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

}
void Tools::back(string shape)
{
	cout << "Back  --> enter any character\n";
	cin >> choice;
	if (true)
	{
		if (shape == "point")
		{
			clearScreen();
		}
		else if (shape == "line")
		{
			clearScreen();
		}
		else if (shape == "seg")
		{
			clearScreen();
		}
		else if (shape == "rec")
		{
			clearScreen();
		}
		else if (shape == "tri")
		{
			clearScreen();
		}
		else if (shape == "cir")
		{
			clearScreen();
		}
		else if (shape == "quad")
		{
			clearScreen();
		}
		else if (shape == "poly")
		{
			clearScreen();
		}
	}
}
