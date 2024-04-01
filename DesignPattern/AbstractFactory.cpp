#include <iostream>
#include <string>
#include <vector>


class Chair
{
public:
	virtual void printInfo() = 0;
};

class ClassicalChair : public Chair
{
public:
	void printInfo() override
	{
		std::cout << "classical chair" << std::endl;
	}
};

class ModernChair : public Chair
{
public:
	void printInfo() override
	{
		std::cout << "modern chair" << std::endl;
	}
};

class Sofa
{
public:
	virtual void printInfo() = 0;
};

class ClassicalSofa : public Sofa
{
public:
	void printInfo()
	{
		std::cout << "classical sofa" << std::endl;
	}
};

class ModernSofa : public Sofa
{
public:
	void printInfo()
	{
		std::cout << "modern sofa" << std::endl;
	}
};

class AbstractFactory
{
public:
	virtual Chair* createChair() = 0;
	virtual Sofa* createSofa() = 0;
};

class ModernFactory : public AbstractFactory
{
public:
	Chair* createChair() override
	{
		return new ModernChair();
	}

	Sofa* createSofa() override
	{
		return new ModernSofa();
	}
};

class ClassicalFactory : public AbstractFactory
{
public:
	Chair* createChair() override
	{
		return new ClassicalChair();
	}

	Sofa* createSofa() override
	{
		return new ClassicalSofa();
	}
};