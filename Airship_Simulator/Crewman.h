#pragma once
class Crewman
{
public:
	Crewman();
	~Crewman();

	enum Experience_ {
		UNTRAINED,
		BASIC,
		TRAINED,
		EXPERIENCE,
		EXPERT
	};

private:

	int dexterity_;
	int strength_;
	int charisma_;
	int wisdom_;
	int intelligence_;
	int constitution_;

	//Proficiency, 0 none, 1 proficient, 2 expertise
	int gunmanship_;
	int helmsmanship_;
	int repair_;
	int engineering_;

	//Maybe
	int leadership_;
};

