#include "stdafx.h"
#include "Propeller.h"

const long double PI = 3.141592653589793238L;

Propeller::Propeller(double diameter, double pitch, Ship::Wood_ wood_)
{
	this->diameter_ = diameter;
	this->pitch_ = pitch;
	
	calculateMass();
}


Propeller::~Propeller()
{
}

//This right here is maybe the simplest equation to calculate thrust from a propeller. 
//F = p((PI * (.0255 * d)^2)/4) * [((RPM * .0254 * pitch * 1/60)^2) - (RPM * .0254 * pitch * 1/60 * Vac)] * (d / (3.29546 * pitch)) ^ 1.5
//F is force in newtons
//p is air density in kg/m^3
//RPM is rpm
//d is propeller diameter in inches
//pitch is propeller pitch in inches.
//Vac is aircraft speed in m/s
//We are going to assume temperature is a nice 70 degrees fahrenheit at sea level, and drops 3.3 degrees fahrenheit per 1000 ft of elevation.
//https://www.electricrcaircraftguy.com/2014/04/propeller-static-dynamic-thrust-equation-background.html
double Propeller::calculateThrust(double rpm, double altitude, double aircraftSpeed) {
	//Fahrenheit to Kelvin 
	//Kelvin = (Tempf + 459.67) x (5/9)
	double temperature = ((70 - (3.3*(altitude / 1000.0)) + 459.67) * (5.0/9.0));

	//pressure of dry air = pressure / (Gas constant for air * Temperature)
	double air_density = (101325.0) / (287.05 * temperature);

	//going to break up this calculation into three parts.
	double force1 = air_density * ((PI * pow((.0255 * this->diameter_), 2)) / 4.0);
	double force2 = pow(rpm * .0254 * this->pitch_ * (1.0 / 60.0), 2) - (rpm * .0254 * this->pitch_ * (1.0 / 60.0) * aircraftSpeed);
	double force3 = pow(this->diameter_ / (3.29546 * this->pitch_), 1.5);

	double thrust = (force1 * force2 * force3);
	return thrust * 0.224;
}


//We are going to use a basic calc for moment of inertia
//Basically going to use the height (diameter / 2) and the width (pitch) as well as 1 inch for thickness in mass calc.
//in I = (1/12) * m * (4 * h^2 + w ^ 2);
void Propeller::calculateMomentOfInertia() {
	calculateMass();
	this->moment_of_intertia_ = (1.0 / 12.0) * this->mass_ * (4 * pow(this->diameter_ / 2.0, 2) + pow(this->pitch_, 2));
}

//Going to assume mass is diameter/2 * width * 1 inch thickness * lbs per inch * 3 propellers
//Propeller is going to be 3 bladed at the moment.
void Propeller::calculateMass() {
	double lbPerFoot = 51;
	switch (this->wood_) {

	    case(Ship::BIRCH):
			lbPerFoot = 46;

		case(Ship::HICKORY):
			lbPerFoot = 51;
			break;

		case(Ship::BLOODWOOD):
			lbPerFoot = 66;
			break;

		case(Ship::LIGNUM_VITAE):
			lbPerFoot = 79;
			break;
	}

	double lbPerInch = lbPerFoot / (12.0 * 12.0 * 12.0);

	this->mass_ = (this->diameter_ / 2.0) * (this->diameter_ / 4.0) * lbPerInch * 3.0 * 3.0;
}