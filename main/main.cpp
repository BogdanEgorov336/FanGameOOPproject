#include "utilP.h"

int main() {
	srand(time(NULL));
	
	//character creating
	int energy;
	cout << "Energy you have [100 for classic]: ";
	cin >> energy;

	string player_name;
	cout << "Your name: ";
	cin >> player_name;
	hold_screen();

	Player player(energy, 0, player_name);

	//game
	play_night(player, 4, energy, 30);

	system("pause");
	return 0;
}