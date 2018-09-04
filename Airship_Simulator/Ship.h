#pragma once
#include <vector>
#include "Deck.h"
#include "Balloon.h"
#include "Crewman.h"
#include "FlightControlSurface.h"
#include "Engine.h"

class Ship
{
public:
	Ship();
	~Ship();

	enum Wood_ {
		BIRCH,
		HICKORY,
		BLOODWOOD,
		LIGNUM_VITAE
	};


	int addDeck(Deck *deck);
	int addEngine(Engine *engine);
	int addCrew(Crewman *crewman);
	int addFCS(FlightControlSurface *fcs);
	double calculateWeight();
	double calculateSpeed();
	double calculateHeading(double turnPercent);
	double calculateTurnRate();


	//My god the getters and setters.
	inline void setLength(double length) { this->length_ = length; }
	inline void setWidth(double width) { this->width_ = width; }
	inline void setPlatingThickness(double platingThickness) { this->plating_thickness_ = platingThickness; }
	inline void setPlankThickness(double plankThickness) { this->plank_thickness_ = plankThickness; }
	inline void setFrameThickness(double frameThickness) { this->frame_thickness_ = frameThickness; }
	inline void setFrameSpacing(double frameSpacing) { this->frame_spacing_ = frameSpacing; }
	inline void setStanchionWidth(double stanchionWidth) { this->getStanchionWidth = stanchionWidth; }
	inline void setStanchionSpacing(double stanchionSpacing) { this->getStanchionSpacing = setStanchionSpacing; }
	inline void setBeamThickness(double beamThickness) { this->beam_thickness_ = beamThickness; }
	inline void setBeamSpacing(double beamSpacing) { this->beam_spacing_ = beamSpacing; }
	inline void setWood(Wood_ wood) { this->wood_ = wood; }
	inline void setBalloon(Balloon balloon) { this->balloon_ = balloon; }
	inline void setDecks(std::vector<Deck> decks) { this->decks_ = decks; }
	inline void setCrew(std::vector<Crewman> crew) { this->crew_on_ship_ = crew; }
	inline void setFCS(std::vector<FlightControlSurface> fcs) { this->fcs_ = fcs; }

	inline double getLength() { return this->length_; }
	inline double getWidth() { return this->width_; }
	inline double getPlatingThickness() { return this->plank_thickness_; }
	inline double getPlankThickness() { return this->plank_thickness_; }
	inline double getFrameThickness() { return this->frame_thickness_; }
	inline double getFrameSpacing() { return this->frame_spacing_; }
	inline double getStanchionWidth() { return this->stanchion_width_; }
	inline double getStanchionSpacing() { return this->stanchion_spacing_; }
	inline double getBeamThickness() { return this->beam_thickness_; }
	inline double getBeamSpacing() { return this->beam_spacing_; }
	inline Wood_ getWood() { return this->wood_; }
	inline Balloon getBalloon() { return this->balloon_; }
	inline std::vector<Deck> getDecks() { return this->decks_; }
	inline std::vector<Crewman> getCrew() { return this->crew_on_ship_; }
	inline std::vector<FlightControlSurface> getFCS() { return this->fcs_; }
	inline double getHeight() { return this->heading_; }
	inline double getWeight() { return this->weight_; }
	inline double getHeading() { return this->heading_; }
	inline double getSpeed() { return this->speed_; }

private:

	//Provided by User
	double length_;
	double width_;
	double plating_thickness_;
	double plank_thickness_;
	double frame_thickness_;
	double frame_spacing_;
	double stanchion_width_;
	double stanchion_spacing_;
	double beam_thickness_;
	double beam_spacing_;
	Wood_ wood_;

	Balloon balloon_;
	std::vector<Deck> decks_;
	std::vector<Crewman> crew_on_ship_;
	std::vector<FlightControlSurface> fcs_;
	std::vector<Engine> engines_;

	//Calculated
	double height_;
	double weight_;
	double heading_;
	double speed_;
};

