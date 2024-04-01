#include <iostream>
#include <string>
#include <vector>


class Block
{
public:
	virtual void printInfo() = 0;
};

class Circle : public Block
{
	void printInfo() override;
};

void Circle::printInfo()
{
	std::cout << "Circle Block" << std::endl;
}

class Square : public Block
{
	void printInfo() override;
};

void Square::printInfo()
{
	std::cout << "Square Block" << std::endl;
}

class BlockFactory
{
public:
	virtual Block* create() = 0;
};

class CircleFactory : public BlockFactory
{
public:
	Block* create() override;
};

Block* CircleFactory::create()
{
	return new Circle();
}

class SquareFactory : public BlockFactory
{
public:
	Block* create() override;
};

Block* SquareFactory::create()
{
	return new Square();
}

class BlockFactorySystem
{
public:
	BlockFactorySystem() { blocks.clear(); }

	void createBlocks(BlockFactory* factory, int quality);

	~BlockFactorySystem() {
		for (Block* block : blocks)
		{
			if (block)
			{
				block == nullptr;
				delete block;
			}
		}
	}
private:
	std::vector<Block*> blocks;
};

void BlockFactorySystem::createBlocks(BlockFactory* factory, int quality)
{
	for (int i = 0; i < quality; i++)
	{
		Block* block = factory->create();
		block->printInfo();
		blocks.emplace_back(block);
	}
}