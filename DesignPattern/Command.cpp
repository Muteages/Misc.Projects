#include <iostream>
#include <string>
#include <vector>

class TeaMachine
{
public:
	void makeTea(const std::string& name)
	{
		std::cout << name << " is ready!" << std::endl;
	}
};

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};

class OrderCommand : public Command
{
public:
	OrderCommand(TeaMachine* tm, const std::string& name)
		: teaMachine(tm), teaName(name)
	{}

	void execute() override
	{
		teaMachine->makeTea(teaName);
	}

private:
	TeaMachine* teaMachine;
	std::string teaName;
};




class Order
{
public:
	void setOrder(Command* oc)
	{
		orderList.emplace_back(oc);
	}
	void executeOrder()
	{
		for (const auto order : orderList)
		{
			order->execute();
		}
	}

	~Order()
	{
		for (auto order : orderList)
		{
			delete order;
			order = nullptr;
		}
		orderList.clear();
	}

private:
	std::vector<Command*> orderList;
};