#pragma once
class Balloon
{
public:
	Balloon();
	~Balloon();

private:

	//Provided by User
	double length_;
	double width_;

	//Calculated
	double lift_generated_;

};

