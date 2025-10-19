#pragma once
#include "animatronic.h"

class Util {

public:

	void init(Animatronic &animatronic);
	virtual void init(Animatronic* &animatronic, int size);
};