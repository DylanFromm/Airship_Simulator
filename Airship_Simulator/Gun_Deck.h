#pragma once
#include <vector>

#include "Deck.h"
#include "Gun.h"

class Gun_Deck : private Deck
{
public:
	Gun_Deck();
	~Gun_Deck();

	double calculateWeight();

private:

	std::vector<Gun> Guns;

	double gun_spacing_;
	int gun_number_;

};

