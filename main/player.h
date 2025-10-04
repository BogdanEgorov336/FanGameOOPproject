#pragma once
#include "animatronic.h"

class Player {

private:

	int energy;
	int score;
	string name;

public:

	Player();
	Player(int energy, int score, string name);
	~Player();

	int getEnergy();
	int getScore();
	string getName();

	void setEnergy(int energy);
	void setScore(int score);
	void setName(string name);

	string getCamera(Animatronic* animatronic, int size);
};