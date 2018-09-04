#pragma once
class Boiler
{
public:
	Boiler();
	~Boiler();

	enum Make_ {
		BASIC,
		COMMON,
		GOOD,
		FINE,
		MASTERCRAFTED
	};

private:

	//Set by user
	bool superheater_;
	int waterCapacity_;
	double efficency_;
	double firebox_length_;
	double firebox_width_;
	int firetube_columns;
	int firetube_rows;
	double firetube_diameter;
	double boiler_length_;
	double boiler_width_;
	double boiler_height_;
	Make_ make_;

	//Set by GM?
	double max_pressure_;

	//Calculated
	double pressure_;

};

