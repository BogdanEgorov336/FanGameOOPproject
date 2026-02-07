#pragma once
#include "player.h"
#include "util.h"

void hold_screen() {

	cout << endl;
	system("pause");
	system("cls");
}

void play_night(Player player, int anim_num, int energy, int turn) {

	Animatronic* an = new Animatronic[anim_num];

	Util util;
	util.init(an, anim_num);

	string game_massages[6]{
		"You wait for a few minutes.\n",
		"Silence around is so loud.\n",
		"Clanking is heard somewhere.\n",
		"You close the door\n",
		"You lost...\n",
		"You won!\n"};
	int attack_flag = 0;
	bool defeat_flag = false;

	for (int i = 0; i < turn; i++) {

		//choice
		cout << "[ " << energy
			<< "% ] You're supposed to...\n[1]Check camera\n[2]Close the door\n[3]Do nothing\n>>";
		int temp;
		cin >> temp;
		system("cls");

		if (temp == 1) {

			cout << player.getCamera(an, anim_num, energy);
		}
		else if (temp == 2) {

			cout << game_massages[3];
			player.closeTheDoor(an, anim_num, attack_flag, energy);
		}
		else {

			cout << game_massages[rand() % 3];
			energy -= rand() % 2;
		}

		//checking
		if (attack_flag >= 2 || energy < 0) {
			defeat_flag = true;
			break;
		}

		if (player.checkForAttack(an, anim_num)) {
			attack_flag++;
		}

		for (int i = 0; i < anim_num; i++) {

			an[i].increasePosition(0, 5);
			an[i].checkPhase();
		}

		hold_screen();
	}

	//the game ends
	if (!defeat_flag) {
		cout << game_massages[5];
	}
	else {
		cout << game_massages[4];
	}

	delete[] an;
}
