#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{
}


Ship::~Ship()
{
}

int Ship::addDeck(Deck *deck) {
	int ret = 0;

	if (deck != NULL) {
		this->decks_.push_back(*deck);
		ret = 1;
	}

	return ret;
}

int Ship::addEngine(Engine *engine) {
	int ret = 0;

	if (engine != NULL) {
		this->engines_.push_back(*engine);
		ret = 1;
	}

	return ret;
}

int Ship::addCrew(Crewman *crewman) {
	int ret = 0;

	if (crewman != NULL) {
		this->crew_on_ship_.push_back(*crewman);
		ret = 1;
	}

	return ret;
}

int Ship::addFCS(FlightControlSurface *fcs) {
	int ret = 0;

	if (fcs == NULL) {
		this->fcs_.push_back(*fcs);
		ret = 1;
	}

	return ret;
}

double Ship::calculateWeight() {


}

double Ship::calculateSpeed() {


}

double Ship::calculateHeading(double turnPercent) {


}

double Ship::calculateTurnRate() {


}
