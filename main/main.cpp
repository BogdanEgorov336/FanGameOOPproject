#include "player.h"
#include "util.h"

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
	srand(time(0));

	Player player(100, 0, "Afton");

	int size = 1;
	Animatronic* an = new Animatronic[size];

	Util util;
	util.init(an, size);

	string game_massages[3]{ "You wait for a few minutes.\n",
		"Silence around is so loud.\n",
		"Clanking is heard somewhere." };
	bool flag = false;
	int temp;

	for (int i = 0; i < 5; i++) {

		//choice
		cout << "You're supposed to...\n[1]Check camera\n[2]Close the door\n[3]Do nothing\n>>";
		cin >> temp;

		if (temp == 1) {

			cout << player.getCamera(an, 1);
		}
		else if (temp == 2) {

			cout << "You close the doors\n";
			player.closeTheDoor(an, 1, flag);
		}
		else {

			cout << game_massages[rand() % 3];
		}

		//checking
		if (flag) {
			cout << "You lost\n";
			break;
		}

		if (player.checkForAttack(an, size)) {
			flag = true;
		}

		for (int i = 0; i < size; i++) {

			an[i].increasePosition();
			an[i].checkPhase();
		}

	}

	delete[] an;
	system("pause");
	return 0;
}