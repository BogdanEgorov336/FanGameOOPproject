#include "player.h"
#include "initializer.h"

//void camera_check(int index, int energy) {
//
//	cout << "You check cameras..." << endl;
//
//	if (index <= 4) {
//		cout << "The animatronic is far.\n";
//	}
//	else if (index < 8) {
//		cout << "The animatronic is nearer to you.\n";
//	}
//	else if (index < 10) {
//		cout << "The animatronic is near!\n";
//	}
//	else {
//		cout << "The animatronic stands in your door!!!\n";
//	}
//}
//
//string get_score(int score) {
//
//	return "Score you got: " + to_string(score) + "\n";
//}
//
//string get_energy(int energy) {
//
//	return "Your current energy: " + to_string(energy) + "%\n";
//}
//
//string win_mas(int score) {
//
//	return "You won, your score: "
//		+ to_string(score);
//}
//
//int main()
//{
//	string select_bar = "Check cameras: 1,\nclose the door: 2,\ndo nothing: 3.\n";
//	string result2 = "You close the door.\n";
//	string result3 = "You just sit and nothing happens\n";
//	string kill_massage = "You've lost...\n";
//
//	int score = 0;
//	int place_index = 0;
//	int energy = 100;
//	bool attack_indicator = false;
//	int select;
//	bool victory_massage_tracker = true;
//
//	for (int i = 30; i >= 0; i--) {
//
//		place_index += rand() % 5;
//
//		cout << select_bar;
//		cin >> select;
//
//		if (select == 1) {
//
//			camera_check(place_index, energy);
//			energy -= 4;
//		}
//		else if (select == 2) {
//
//			if (place_index >= 10) {
//
//				place_index = rand() % 5;
//				attack_indicator = false;
//				cout << result2;
//			}
//		}
//		else {
//
//			cout << result3;
//		}
//
//		if (attack_indicator || energy < 0) {
//
//			cout << kill_massage;
//			victory_massage_tracker = false;
//			cout << get_score(score);
//			break;
//		}
//
//		score++;
//
//		if (place_index >= 10) {
//			attack_indicator = true;
//		}
//
//		cout << get_energy(energy);
//
//		cout << "<===========>" << endl;
//
//		cin >> select;
//		system("clear");
//
//	}
//
//	if (victory_massage_tracker) {
//		cout << win_mas(score);
//	}
//
//	return 0;
//}


void test01() {

	Player player;
	int size = 2;
	Animatronic* temp = new Animatronic[size];
	*temp = Animatronic("ASD", 4, false);
	*(temp + 1) = Animatronic("DASDAS", 10, false);

	cout << player.getCamera(temp, size) << endl;
}

void test02() {

	Animatronic* s = new Animatronic[2];
	Initializer in;
	in.init(s, 2);

	for (int i = 0; i < 2; i++) {

		cout << s[i].getName() << endl << s[i].getPosition()
			<< endl << s[i].getAttackPhase() << endl << endl;
	}
}


int main() {
	srand(time(0));

	


	system("pause");
	return 0;
}