#pragma once
#include <cmath>
#include "Ship.h"

class Propeller
{
public:


	Propeller(double diameter = 24, double pitch = 10, Ship::Wood_ wood = BLOODWOOD);
	~Propeller();

	double calculateThrust(double rpm, double altitude, double aircraftSpeed);
	void calculateMomentOfInertia();
	void calculateMass();

	inline void setDiameter(double diameter) { this->diameter_ = diameter; }
	inline void setPitch(double pitch) { this->pitch_ = pitch; }

	inline double getDiameter() { return this->diameter_; }
	inline double getPitch() { return this->pitch_; }
	inline double getMomentOfInertia() { return this->moment_of_intertia_; }
	inline double getMass() { return this->mass_; }
	inline Ship::Wood_ getWoodType() { return this->wood_; }

private:

	//in inches
	double diameter_;
	double pitch_;

	//Moment of Inertia in
	double moment_of_intertia_;

	//Mass in lbs
	double mass_;

	//Type of wood propeller is made out of
	Ship::Wood_ wood_;

};

