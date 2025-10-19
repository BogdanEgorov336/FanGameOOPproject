#include "util.h"

void Util::init(Animatronic& animatronic) {

	const int size = 28;

	string names[size]{ 
		//fnaf 1
		"Freddy", "Bonnie", "Chica", "Foxy", "Golden Freddy",
		//fnaf 2
		"Mangle", "The Marionette", "Endo-01", "Endo-02", "Toy Freddy",
		"Toy Bonnie", "Toy Chica", "Withered Freddy", "Withered Bonnie",
		"Withered Chica", "Withered Foxy",
		//fnaf 3
		"Springtrap", "Shadow Freddie", "Shadow Balloon Boy", "Shadow Marionette",
		"Shadow Foxy",
		//fnaf 4
		"Nightmare Freddy", "Nightmare Bonnie", "Nightmare Chica", "Nightmare Foxy",
		"Nightmare Mangle", "Nightmare Fredbear", "Plushtrap"
	};

	animatronic.setName(names[rand() % 28]);
	animatronic.setPosition(0);
	animatronic.setAttackPhase(false);
}

void Util::init(Animatronic*& animatronic, int size) {

	for (int i = 0; i < size; i++) {

		init(animatronic[i]);
	}
}