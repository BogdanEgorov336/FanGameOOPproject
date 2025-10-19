#include "animatronic.h"

Animatronic::Animatronic() {

	name = "Empty";
	position = 0;
	attackPhase = false;
}

Animatronic::Animatronic(string name, int pos, bool phase)
	: name(name), position(pos), attackPhase(phase) {}

Animatronic::~Animatronic() {}

string Animatronic::getName() {
	return name;
}

int Animatronic::getPosition() {
	return position;
}

bool Animatronic::getAttackPhase() {
	return attackPhase;
}

void Animatronic::setName(string name) {
	this->name = name;
}

void Animatronic::setPosition(int position) {

	position = position >= 0 ? position : -position;

	this->position = position;
}

void Animatronic::setAttackPhase(bool attack_phase) {
	this->attackPhase = attack_phase;
}

string Animatronic::discriptPosition() {

	string info;

	if (getPosition() < 6) {
		info = getName() + " is far...";
	}
	else if (getPosition() < 10)  {
		info = getName() + " is approaching..";
	}
	else if (getPosition() < 16) {
		info = getName() + " is near.";
	}
	else if (getPosition() < 20) {
		info = getName() + " is next to your room!";
	}
	else {
		info = getName() + " is in the doorway!!!";
	}

	return info;
}

void Animatronic::increasePosition() {

	setPosition(getPosition() + rand() % 21);
}

void Animatronic::increasePosition(int a, int b) {

	if (a > b) {
		swap(a, b);
	}

	setPosition(getPosition() + rand() % (b - a) + a + 1);
}

void Animatronic::checkPhase() {

	if (getPosition() >= 20) {

		setAttackPhase(true);
	}
}