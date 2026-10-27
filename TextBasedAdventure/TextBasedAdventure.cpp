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

struct Player {
	int x;
	int y;
};

struct GameState {
	int treasuresCollected = 0;
	bool isRunning = true;
	bool hasWon = false;
};

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

void DrawDungeon(const DungeonMap& map, const Player& player) {
	for (int y = 0; y < MapHeight; ++y) {
		for (int x = 0; x < MapWidth; ++x) {
			if (x == player.x && y == player.y) {
				cout << '@';
			}
			else {
				cout << GetTileChar(map[y][x]);
			}
		}
		cout << '\n';
	}
}


Player SpawnPlayer() {
	return Player{ 2,2 };
}

bool isWalkable(const DungeonMap& map, const int& x, const int& y) {
	//checking bounds first
	if (x < 0 || x >= MapWidth || y < 0 || y > MapHeight) {
		return false;
	}
	else {
		return map[y][x] != Tile::Wall;
	}
}

void ProcessCurrentTile(DungeonMap& map, const Player& player, GameState& gamestate) {
	Tile& tile = map[player.y][player.x];
	if (tile == Tile::Treasure) {
		cout << "Collected Treasure! \n";
		++gamestate.treasuresCollected;
		tile = Tile::Floor;
	}
	if (tile == Tile::Exit) {
		cout << "You found the exit, You win! \n";
		gamestate.hasWon = true;
		gamestate.isRunning = false;
	}
}

bool MovePlayer(Player& player, const DungeonMap& map, char command) {
	int newX = player.x;
	int newY = player.y;

	switch (command) {
	case 'w':
	case 'W':
		--newY;
		break;
	case 's':
	case 'S':
		++newY;
		break;
	case 'd':
	case 'D':
		++newX;
		break;
	case 'a':
	case 'A':
		--newX;
		break;
	default:
		return false;
	}

	if (!isWalkable(map, newX, newY)) {
		cout << "You cannot move there! \n";
		return false;
	}

	player.x = newX;
	player.y = newY;

	return true;
}

int main() {
	GameState gamestate;
	DungeonMap dungeon = CreateDungeon();
	Player player = SpawnPlayer();
	char command;

	while (gamestate.isRunning) {
		DrawDungeon(dungeon, player);
		std::cout << "\nMove with W/A/S/D, or Q to quit: ";

		if (!(std::cin >> command)) {
			break;
		}
		if (command == 'q' || command == 'Q') {
			break;
		}

		const bool moved = MovePlayer(player, dungeon, command);
		if(moved)ProcessCurrentTile(dungeon, player, gamestate);
		std::cout << "\n\n";
	}
	std::cout << "Final treasure count: " << gamestate.treasuresCollected << '\n';
	std::cout << "Thanks for playing! \n";
	return 0;
}
/*
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
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
