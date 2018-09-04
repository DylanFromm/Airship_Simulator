#pragma once
#include <vector>

#include "Deck.h"
#include "Gun.h"
class Main_Deck : private Deck
{
public:
	Main_Deck();
	~Main_Deck();

private:

	std::vector<Gun> guns_;
	double railing_height_;

};

