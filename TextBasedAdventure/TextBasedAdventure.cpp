// TextBasedAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main() {
	cout << "Welcome to the arena\n";
	cout << "Press 1 to punch\n";

	int x; //declaration
	x = 5; //assignment
	int y = 6.2; //the .2 gets truncated
	int sum = x + y;

	cout << x << '\n';
	cout << y << '\n';
	cout << sum << '\n';

	double price = 10.99;

	cout << "Price: " << price << '\n';

	char grade = 'A'; //To store a single character, you use single quotes
	cout << grade << '\n';

	char initial = 'BC'; //The B gets removed.
	cout << initial << '\n';

	bool isReady = true;
	cout << isReady << '\n';


	string name = "Ravindu";
	cout << name << '\n';


	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
