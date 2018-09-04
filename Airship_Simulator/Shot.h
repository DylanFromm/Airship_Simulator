#pragma once
class Shot
{
public:
	Shot();
	~Shot();

	enum Type_ {
		CANISTER,
		CHAIN_SHOT,
		DOUBLE_SHOT,
		ROUND_SHOT
	};

private:

	//Provided by User
	int pounds_;
	double range_;
	Type_ type_;

	//Calculated
	double accuracy_;
};

