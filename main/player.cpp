#include "player.h"

Player::Player() {

	energy = 0;
	score = 0;
	name = "Test";
}

Player::Player(int energy, int score, string name) : energy(energy), score(score), name(name) {};

Player::~Player() {}

int Player::getEnergy() {
	return energy;
}

int Player::getScore() {
	return score;
}

string Player::getName() {
	return name;
}

void Player::setEnergy(int energy) {
	this->energy = energy;
}

void Player::setScore(int score) {
	this->score = score;
}

void Player::setName(string name) {
	this->name = name;
}

string Player::getCamera(Animatronic*& animatronic, int size) {

	string info = "";

	for (int i = 0; i < size; i++) {

		info += animatronic[i].discriptPosition() + "\n";
	}

	return info;
}

string Player::getCamera(Animatronic& animatronic) {

	return animatronic.discriptPosition() + "\n";
}

bool Player::checkForAttack(Animatronic& animatronic) {

	return animatronic.getAttackPhase();
}

bool Player::checkForAttack(Animatronic*& animatronic, int size) {

	for (int i = 0; i < size; i++) {

		if (animatronic[i].getAttackPhase()) {

			return true;
		}
	}

	return false;
}

void Player::closeTheDoor(Animatronic*& animatronic, int size, bool& flag) {

	for (int i = 0; i < size; i++) {

		if (animatronic[i].getAttackPhase()) {

			animatronic[i].setAttackPhase(false);
			animatronic[i].setPosition(rand() % 10);
			flag = false;
		}
	}
}

void Player::closeTheDoor(Animatronic& animatronic, bool& flag) {

	if (animatronic.getAttackPhase()) {

		animatronic.setAttackPhase(false);
		animatronic.setPosition(rand() % 10);
		flag = false;
	}
}