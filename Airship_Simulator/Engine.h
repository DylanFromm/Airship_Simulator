#pragma once
#include <cmath>

#include "Propeller.h"

class Engine
{

public:
	enum Position_ {
		LEFT,
		CENTER,
		RIGHT
	};

	enum Make_ {
		BASIC,
		COMMON,
		GOOD,
		FINE,
		MASTERCRAFTED
	};

	Engine(Propeller propeller, double bore = 10, double stroke = 10, double cutoff = 25, int pistons = 2, double efficency = 5, double gear_ratio = .25, Position_ position = CENTER, Make_ make = BASIC);
	~Engine();

	void updateStats(double delta_t, double pressure, double altitude, double aircraftSpeed);
	void calculateHorsePower(double pressure);
	void calculateTorque(double pressure);
	void calculateRpm(double force);
	void calculateThrust(double altitude, double aircraftSpeed);
	void calculateSteamNeededPerSec();

	void setBore(double bore);
	void setStroke(double stroke);
	void setCutoff(double cutoff);
	void setThrottle(double throttle);
	void setPistons(int pistons);
	void setEfficency(double efficency);
	void setGearRatio(double gear_ratio);
	void setOn(bool on);
	void setPosition(Position_ position_);
	void setMake(Make_ make_);
	void setPropeller(Propeller propeller);

	double getBore();
	double getStroke();
	double getCutoff();
	int getPistons();
	double getEfficency();
	double getGearRatio();
	bool getOn();
	Position_ getPosition();
	Make_ getMake();

	double getMaxRpm();
	double getHorsePower();
	double getRpms();
	double getThrottle();
	double getSteamNeededPerSec();
	double getThrustProduced();
	double getTorque();

private:


	//Parameters that will be set by the user
	//in inches
	double bore_;
	double stroke_;

	//in percentage
	double cutoff_;
	double throttle_;
	double efficency_;

	int pistons_;

	//Engine turns to propeller turns
	double gear_ratio_;

	bool on_;
	Position_ position_;
	Make_ make_;
	Propeller propeller_;

	//Set by GM?
	double max_rpm_;
	double safe_rpm_;

	//Calculated Values
	double horse_power_;
	double rpm_;
	double steam_needed_per_sec_;
	double thrust_produced_;
	double torque_;

};

