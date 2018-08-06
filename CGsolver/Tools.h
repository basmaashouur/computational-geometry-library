#pragma once
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9
#define PI acos(-1.0)

class Tools
{
public:
	string choice;
	// Function to handle wrong choices
	void wrongChoice(string cho);
	// Function to clear screen
	void clearScreen();
	void back(string shape);
};
