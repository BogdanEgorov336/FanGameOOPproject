#pragma once
#include "animatronic.h"

class Player {

private:

	int score;
	string name;
	int energy;

public:

	Player();
	Player(int energy, int score, string name);
	Player(int score, string name);
	~Player();

	int getEnergy();
	int getScore();
	string getName();

	void setEnergy(int energy);
	void setScore(int score);
	void setName(string name);

	bool checkForAttack(Animatronic& animatronic);
	bool checkForAttack(Animatronic*& animatronic, int size);
	string getCamera(Animatronic*& animatronic, int size, int& energy);
	string getCamera(Animatronic& animatronic, int& energy);
	void closeTheDoor(Animatronic*& animatronic, int size, int& flag, int& energy);
	void closeTheDoor(Animatronic& animatronic, int& flag, int& energy);
};