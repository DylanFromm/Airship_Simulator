#pragma once
#include "Shot.h"
#include "Crewman.h"

class Gun
{
public:
	Gun();
	~Gun();

	enum Type_ {
		CARRONADE,
		DECK_GUN,
		LONG_GUN,
		MORTAR
	};

	//Crew operations
	int addCrew(Crewman crew);
	int removeCrew(Crewman crew);
	int updateCrew(Crewman crew);

	double calculateWeight();

	//Getters and setters
	inline void setPound(int pound) { this->pounds_ = pound; }
	inline void setLength(double length) { this->length_ = length; }
	inline void setBore(double bore) { this->bore_ = bore; }
	inline void setWeight(double weight) { this->weight_ = weight; }
	inline void setShot(Shot shot) { this->shot_ = shot; }
	inline void setType(Type_ type) { this->type_ = type; }

	inline int getPound() { return this->pounds_; }
	inline double getLength() { return this->length_; }
	inline double getBore() { return this->bore_; }
	inline double getWeight() { return this->weight_; }
	inline Shot getShot() { return this->shot_; }
	inline Type_ getType() { return this->type_; }
	inline double getRange() { return this->range_; }
	inline double getAccuracy() { return this->accuracy_; }

protected:

	//Provided by User
	int pounds_;
	double length_;
	double bore_;
	double weight_;
	Shot shot_;
	Type_ type_;
	Crewman crew_manning_;

	//Calculated
	double range_;
	double accuracy_;
};

