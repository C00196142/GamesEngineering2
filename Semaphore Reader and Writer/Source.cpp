#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

struct Semaphore
{
public:
	Semaphore() {};
	Semaphore(int x)
	{
		count = x;
	}

	void P()
	{
		std::unique_lock<decltype(mutex)> lock(mutex);
		while (count <= 0)
		{
			cVar.wait(lock);
		}
		count--;
	}

	void V()
	{
		std::unique_lock<decltype(mutex)> lock(mutex);
		count++;
		cVar.notify_one();
	}

private:
	int count = 0;
	std::mutex mutex;
	std::condition_variable cVar;

};

struct Database
{
public:


private:



};

int nr = 0;

void Reader()
{
	bool running = true;
	while (running)
	{
		nr++;
		if (nr == 1)
		{

		}

		nr--;
		if (nr == 0)
		{

		}
	}
}

void Writer()
{
	bool running = true;
	while (running)
	{

	}
}

int main()
{
	std::thread Reader(Reader);
	std::thread Writer(Writer);

	system("PAUSE");
}