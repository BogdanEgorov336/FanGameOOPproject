#include "player.h"
#include "util.h"

void test01() {

	Player player;
	int size = 2;
	int energy = 100;
	Animatronic* temp = new Animatronic[size];
	*temp = Animatronic("ASD", 4, false);
	*(temp + 1) = Animatronic("DASDAS", 10, false);

	cout << player.getCamera(temp, size, energy) << endl;
}

void test02() {

	Animatronic* s = new Animatronic[2];
	Util in;
	in.init(s, 2);

	for (int i = 0; i < 2; i++) {

		cout << s[i].getName() << endl << s[i].getPosition()
			<< endl << s[i].getAttackPhase() << endl << endl;
	}
}

void discript(Animatronic an) {

	cout << an.getName() << endl << an.getPosition()
		<< endl << (an.getAttackPhase() ? "yes" : "no") << endl << endl;
}

int main() {
	srand(time(NULL));

	Player player(100, 0, "Afton");

	int size = 2;
	Animatronic* an = new Animatronic[size];

	Util util;
	util.init(an, size);

	string game_massages[3]{ "You wait for a few minutes.\n",
		"Silence around is so loud.\n",
		"Clanking is heard somewhere.\n" };
	bool flag = false;
	int energy = 100;

	for (int i = 0; i < 10; i++) {

		//choice
		cout << "[ " << energy
			<< "% ] You're supposed to...\n[1]Check camera\n[2]Close the door\n[3]Do nothing\n>>";
		int temp;
		cin >> temp;
		system("cls");

		if (temp == 1) {

			cout << player.getCamera(an, size, energy);
		}
		else if (temp == 2) {

			cout << "You close the doors\n";
			player.closeTheDoor(an, size, flag, energy);
		}
		else {

			cout << game_massages[rand() % 3];
			energy -= rand() % 3;
		}

		//checking
		if (flag || energy < 0) {
			cout << "You lost\n";
			break;
		}

		if (player.checkForAttack(an, size)) {
			flag = true;
		}

		for (int i = 0; i < size; i++) {

			an[i].increasePosition(0, 5);
			an[i].checkPhase();
		}

		system("pause");
		system("cls");
	}

	delete[] an;
	system("pause");
	return 0;
}