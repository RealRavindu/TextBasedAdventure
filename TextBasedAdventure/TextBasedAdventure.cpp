// TextBasedAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <array>
#include <iostream>

using namespace std;

enum class Tile {
	Floor,
	Wall,
	Treasure,
	Exit
};

constexpr int MapWidth = 12;
constexpr int MapHeight = 8;

using DungeonMap =
array<array<Tile, MapWidth>, MapHeight>;

DungeonMap CreateDungeon() {
	DungeonMap map{};

	//creating outer walls
	for (int y = 0; y < MapHeight; ++y) {
		for (int x = 0; x < MapWidth; ++x) {
			if (x == 0 || y == 0 || x == MapWidth - 1 || y == MapHeight - 1) {
				map[y][x] = Tile::Wall;
			}
		}
	}

	//adding a few interior walls
	map[2][3] = Tile::Wall;
	map[4][2] = Tile::Wall;
	map[3][5] = Tile::Wall;
	map[2][10] = Tile::Wall;
	map[7][3] = Tile::Wall;
	map[6][6] = Tile::Wall;
	map[5][6] = Tile::Wall;

	//placing treasure and exit
	map[5][4] = Tile::Treasure;
	map[6][3] = Tile::Exit;

	return map;
}

char GetTileChar(Tile tile) {

	switch (tile) {
	case Tile::Treasure: return 'T';
	case Tile::Wall: return '#';
	case Tile::Exit: return 'E';
	case Tile::Floor: return '.';
	}
	return '?';
}

void DrawDungeon(const DungeonMap& map) {
	for (int y = 0; y < MapHeight; ++y) {
		for (int x = 0; x < MapWidth; ++x) {
			cout << GetTileChar(map[y][x]);
		}
		cout << '\n';
	}
}

int main() {
	DungeonMap dungeon = CreateDungeon();
	DrawDungeon(dungeon);
	return 0;
}

int Notes() {
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
