#include <iostream>
#include <string>
#include <unordered_map>


class Shape
{
public:
	virtual void onDraw(int x, int y) = 0;
	virtual ~Shape() {}
};

class ConcreteShape : public Shape
{
public:
	ConcreteShape(const std::string& st)
		: shapeType(st), hasBeenCreated(true), x(0), y(0)
	{}

	void onDraw(int x, int y) override
	{
		this->x = x;
		this->y = y;
		std::cout << shapeType << " " << (hasBeenCreated ? "drawn at (" : "shared at (") << this->x << ", " << this->y << ")" << std::endl;
		setFirstStatus(false);
	}

	void setFirstStatus(bool flag)
	{
		hasBeenCreated = flag;
	}

private:
	std::string shapeType;
	bool hasBeenCreated;
	int x;
	int y;

};

class ShapeFactory
{
public:
	Shape* createShape(const std::string& shapeType)
	{
		if (!shapes.count(shapeType))
		{
			shapes[shapeType] = new ConcreteShape(shapeType);
		}
		return shapes[shapeType];
	}

	~ShapeFactory()
	{
		for (auto& shape : shapes)
		{
			delete shape.second;
		}
	}
private:
	std::unordered_map<std::string, Shape*> shapes;
};