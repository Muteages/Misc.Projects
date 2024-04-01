#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Cart
{
public:
	static Cart& getInstance();
	void buyGood(const std::string& name, int number)
	{
		if (!goods.count(name))
		{
			lists.emplace_back(name);
		}
		goods[name] += number;
	}
	void printInfo()
	{
		for (const auto& good : lists)
		{
			std::cout << good << " " << goods[good] << '\n';
		}
	}

	Cart(const Cart& c) = delete;
	Cart& operator=(const Cart& c) = delete;
private:
	Cart() = default;
	std::unordered_map<std::string, int> goods;
	std::vector<std::string> lists;
};


Cart& Cart::getInstance()
{
	static Cart instance;
	return instance;
}
