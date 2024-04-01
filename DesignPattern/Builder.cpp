#include <iostream>
#include <string>


class Bike
{
public:
	Bike()
		: frame(""), tires("")
	{}

	inline void setFrame(const std::string& f)
	{
		frame = f;
	}
	inline void setTires(const std::string& t)
	{
		tires = t;
	}
	inline void getInfo()
	{
		std::cout << frame << " " << tires << std::endl;
	}
private:
	std::string frame;
	std::string tires;
};

class Builder
{
public:
	virtual void assembleFrame() = 0;
	virtual void assembleTires() = 0;
	virtual Bike getBike() = 0;
};

class MountainBikeBuilder : public Builder
{
public:
	void assembleFrame() override
	{
		bike.setFrame("Aluminum Frame");
	}

	void assembleTires() override
	{
		bike.setTires("Knobby Tires");
	}

	Bike getBike() override
	{
		return bike;
	}
private:
	Bike bike;
};


class RoadBikeBuilder : public Builder
{
public:
	void assembleFrame() override
	{
		bike.setFrame("Carbon Frame");
	}

	void assembleTires() override
	{
		bike.setTires("Slim Tires");
	}

	Bike getBike() override
	{
		return bike;
	}
private:
	Bike bike;
};

class Director
{
public:

	void process(Builder* builder)
	{
		builder->assembleFrame();
		builder->assembleTires();
	}

	Bike getBike(Builder* builder)
	{
		return builder->getBike();
	}
};