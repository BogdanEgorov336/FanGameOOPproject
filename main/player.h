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

	bool checkForAttack(Animatronic& animatronic);
	bool checkForAttack(Animatronic*& animatronic, int size);
	string getCamera(Animatronic*& animatronic, int size);
	string getCamera(Animatronic& animatronic);
	void closeTheDoor(Animatronic*& animatronic, int size, bool& flag);
	void closeTheDoor(Animatronic& animatronic, bool& flag);
};