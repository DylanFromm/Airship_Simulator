#pragma once
#include "Deck.h"
class Hold : private Deck
{
public:
	Hold();
	~Hold();

private:

	double water_tank_width_;
	double coal_storage_width_;
	double steerage_;
};

