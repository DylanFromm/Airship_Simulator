#pragma once
#include <vector>

#include "Crewman.h"
#include "Gun.h"

class Deck
{
public:
    
	enum Deck_Type_ {
		GUN_DECK,
		HOLD,
		MAIN_DECK
	};


	Deck();
	~Deck();

	double calculateWeight();

	//Crew operations.
	int addCrew(Crewman crew);
	int removeCrew(Crewman crew);
	int updateCrewStatus(Crewman crew);

	//Gun operations
	int addGun(Gun gun);
	int removeGun(Gun gun);
	int updateGun(Gun gun);


	//Getters and Setters
	inline void setBoilerRoom(bool boilerRoom) { this->boiler_room_ = boilerRoom; }
	inline void setBoilerRoomLength(double boiler_room_length) { this->boiler_room_length_ = boiler_room_length; }
	inline void setCaptainsQuarters(bool captains_quarters) { this->captains_quarters_ = captains_quarters; }
	inline void setCaptainsQuartersLength(double captains_quarters_length) { this->captains_quarters_length_ = captains_quarters_length; }
	inline void setHeight(double height) { this->height_ = height; }
	inline void setLevel(double level) { this->level_ = level; }
	

private:

	//Set by user
	bool boiler_room_;
	double boiler_room_length_;
	bool captains_quarters_;
	double captains_quarters_length_;
	double height_;
	int level_;
	std::vector<Crewman> crew_on_deck_;

	//Main Deck
	double railing_height_;

	//Main and Gun Decks
	std::vector<Gun> guns_;
	double gun_spacing_;
	int gun_number_;

	//Hold
	double water_tank_width_;
	double coal_storage_width_;
	double steerage_;

};

