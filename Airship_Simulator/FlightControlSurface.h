#pragma once
class FlightControlSurface
{
public:
	FlightControlSurface();
	~FlightControlSurface();

	enum Alignment {
		HORIZONTAL,
		VERTICAL
	};

	enum Position {
		LEFT,
		CENTER,
		RIGHT
	};

private:

	int length_;
	int width_;


};

