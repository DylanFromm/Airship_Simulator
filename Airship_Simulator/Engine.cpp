
#include "stdafx.h"
#include "Engine.h"
#include "integral.h"

const long double PI = 3.141592653589793238L;

Engine::Engine(Propeller propeller, double bore, double stroke, double cutoff, int pistons, double efficency, double gear_ratio, Position_ position, Make_ make)
{
	this->bore_ = bore;
	this->stroke_ = stroke;
	this->cutoff_ = cutoff;
	this->pistons_ = pistons;
	this->efficency_ = efficency;
	this->gear_ratio_ = gear_ratio;
	this->position_ = position;
	this->make_ = make;

	this->max_rpm_ = 2000;
	this->horse_power_ = 0;
	this->rpm_ = 0;
	this->on_ = false;
	
	this->steam_needed_per_sec_ = 0.0;
	this->propeller_ = propeller;
}


Engine::~Engine()
{
}

void Engine::updateStats(double delta_t, double pressure, double altitude, double aircraftSpeed) {
	
	calculateHorsePower(pressure);
	calculateTorque(pressure);
	calculateThrust(altitude, aircraftSpeed);
	calculateSteamNeededPerSec();
}

//HP=PLAN/33000
//P = Mean Effective Pressure
//L = Length of stroke in feet (times 2 for double acting)
//A = areo of the piston in inches
//N = revolutions per minute
void Engine::calculateHorsePower(double pressure) {

	double pressureActual = pressure * (this->throttle_ / 100.0);

	//P
	//Mean effective pressure
	//Total volume of the cylinder, inches^3
	double cylinder_volume = PI * pow((this->bore_ / 2.0), 2) * this->stroke_;

	//Average pressure over the course of a stroke.
	//Pressure from start to cutoff point is the pressure given (times throttle percentage)
	//After cutoff pressure should drop as the volume of steam sent in expands to the full volume.
	//Can be calculated with P1V1 = P2V2. P2 = P1V1 / V2
	double v1 = cylinder_volume * (this->cutoff_ / 100.0);
	double p2 = (pressureActual * v1) / (cylinder_volume);
	double average_pressure_after_cutoff = (pressureActual + p2) / 2;
	double P = ((this->cutoff_ / 100.0) * pressureActual) + (((1 - (this->cutoff_ / 100.0)) * average_pressure_after_cutoff));

	//L
	double L = (2 * this->stroke_) / 12.0;

	//A
	double A = PI * pow((this->bore_) / 2.0, 2);

	calculateRpm(P * A);

	//N is rpm, but its more fun in the end to make a N variable.
	double N = this->rpm_;
	 
	this->horse_power_ = .9 * ((P * L * A *  N) / 33000.0) ;
}

//Torque = Force * distance, pressure is psi
void Engine::calculateTorque(double pressure) {

	//Force is in lbf, times 2 because dual acting piston
	this->torque_ = 5252 * (this->horse_power_/this->rpm_);


}

//Making this instantaneous as calculations for engine load is questionable. 
//
void Engine::calculateRpm(double force) {
	//If multiple pistons working together on each stroke divide the amount of mass each one has to turn .
	double mass = this->propeller_.getMass() / (floor(this->pistons_ / 2.0));

	//double action, so force * 2 per stroke
	double acceleration = (force * 2.0) / mass;

	//Lets get to some kinematics.
	//Calculate final velocity.
	double finalVelocity = sqrt(2 * acceleration * this->stroke_);

	//Calculate time for a total stroke.
	double time = (finalVelocity / acceleration) * 2;

	//Calculate RPM
	this->rpm_ = 3600.0 / time;
}

void Engine::calculateThrust(double altitude, double aircraftSpeed) {
	this->thrust_produced_ = this->propeller_.calculateThrust(this->rpm_, altitude, aircraftSpeed);
}

void Engine::calculateSteamNeededPerSec() {
	double cylinder_volume = PI * pow((this->bore_ / 2.0), 2) * this->stroke_;

	//steam needed should be cylinder volume * cutoff percentage * Rotations per second * 2 due to dual acting pistons.
	this->steam_needed_per_sec_ = (cylinder_volume * (this->cutoff_ / 100.0) * (this->throttle_ / 100.0)) * (this->rpm_ / 60.0) * 2.0;
}



//So many getters and setters

void Engine::setBore(double bore) {
	this->bore_ = bore;
}

void Engine::setStroke(double stroke) {
	this->stroke_ = stroke;
}

void Engine::setCutoff(double cutoff) {
	this->cutoff_ = cutoff;
}

void Engine::setThrottle(double throttle) {
	this->throttle_ = throttle;
}

void Engine::setPistons(int pistons) {
	this->pistons_ = pistons;
}

void Engine::setEfficency(double efficency) {
	this->efficency_ = efficency;
}

void Engine::setGearRatio(double gear_ratio) {
	this->gear_ratio_ = gear_ratio;
}

void Engine::setOn(bool on) {
	this->on_ = false;
}

void Engine::setPosition(Position_ position) {
	this->position_ = position;
}

void Engine::setPropeller(Propeller propeller) {
	this->propeller_ = propeller;
}

void Engine::setMake(Make_ make) {
	this->make_ = make;
}

double Engine::getBore() {
	return this->bore_;
}

double Engine::getStroke() {
	return this->stroke_;
}

double Engine::getCutoff() {
	return this->cutoff_;
}

int Engine::getPistons() {
	return this->pistons_;
}

double Engine::getEfficency() {
	return this->efficency_;
}

double Engine::getGearRatio() {
	return this->gear_ratio_;
}

bool Engine::getOn() {
	return this->on_;
}

Engine::Position_ Engine::getPosition() {
	return this->position_;
}

Engine::Make_ Engine::getMake() {
	return this->make_;
}

double Engine::getMaxRpm() {
	return this->max_rpm_;
}

double Engine::getHorsePower() {
	return this->horse_power_;
}

double Engine::getRpms() {
	return this->rpm_;
}

double Engine::getThrottle() {
	return this->throttle_;
}

double Engine::getSteamNeededPerSec() {
	return this->steam_needed_per_sec_;
}

double Engine::getThrustProduced() {
	return this->thrust_produced_;
}

double Engine::getTorque() {
	return this->torque_;
}