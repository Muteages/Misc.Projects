#include <list>

template<typename T>
class ObjectPool
{
public:
	ObjectPool(size_t sz)
		: objSize(sz)
	{
		for (int i = 0; i < objSize; ++i)
		{
			objects.emplace_back(new T());
		}
	}
	~ObjectPool()
	{
		for (auto& object : objects)
		{
			delete object;
			object = nullptr;
		}
		objSize = 0;
	}

	T* getObject()
	{
		T* object = nullptr;
		if (0 == objSize)
		{
			object = new T();
			std::cout << "new obj" << std::endl;
		}
		else
		{
			object = objects.front();
			objects.pop_front();
			objSize--;
			std::cout << "from pool" << std::endl;
		}
		return object;
	}

	void returnObject(T* object)
	{
		objects.emplace_back(object);
		objSize++;
	}
private:
	std::list<T*> objects;
	size_t objSize;
};
