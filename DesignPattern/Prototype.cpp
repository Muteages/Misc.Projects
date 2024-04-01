#include <iostream>
#include <string>
#include <vector>

class Prototype
{
public:
	virtual Prototype* clone() const = 0;
	virtual void printInfo() const = 0;
	virtual ~Prototype() {}
};

class RectangleProtoType : public Prototype
{
public:
	RectangleProtoType() = delete;
	RectangleProtoType(const std::string& c, int w, int h)
		: colour(c), width(w), height(h)
	{}
	Prototype* clone() const override
	{
		return new RectangleProtoType(colour, width, height);
	}

	void printInfo() const override
	{
		std::cout << "Color: " << colour << ", Width: " << width << ", Height: " << height << std::endl;
	}

private:
	std::string colour;
	int width;
	int height;
};