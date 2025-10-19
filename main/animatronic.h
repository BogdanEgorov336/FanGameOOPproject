#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animatronic {

private:

	string name;
	int position;
	bool attackPhase;

public:

	Animatronic();
	Animatronic(string name, int pos, bool phase);
	~Animatronic();

	string getName();
	int getPosition();
	bool getAttackPhase();

	void setName(string name);
	void setPosition(int position);
	void setAttackPhase(bool attack_phase);

	string discriptPosition();
	void increasePosition();
	void checkPhase();
};