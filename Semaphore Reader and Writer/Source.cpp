//Thomas Butler
//C00196142

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

struct Semaphore
{
public:
	Semaphore(int sem = 1) :count(sem) {};
	~Semaphore() {};

	int count;
	mutex m;

	condition_variable cVar;

	void P()
	{
		unique_lock<decltype(m)> lock(m);

		while (count <= 0)
		{
			cVar.wait(lock);
		}
		count--;
	}

	void V()
	{
		unique_lock<decltype(m)> lock(m);

		count++;
		cVar.notify_one();
	}

};


int nr = 0;
Semaphore mutexR;
Semaphore rW;

void Reader()
{
	bool running = true;
	while (running)
	{
		//cout <<  " idREADER:" << this_thread::get_id() << endl;
		mutexR.P();
		nr++;
		if (nr == 1)
		{
			rW.P();
			cout << " READING FILE... " << endl;
		}
		
		mutexR.V();
		
		mutexR.P();
		nr--;
		if (nr == 0)
		{
			rW.V();
			cout << " READER RELEASING FILE " << endl;
		}

		mutexR.V();
		this_thread::sleep_for(chrono::seconds(1));
	}
}

void Writer()
{
	bool running = true;
	while (running)
	{
		//cout << " idWRITER:" << this_thread::get_id() << endl;

		rW.P();
		cout << " WRITING TO FILE... " << endl;

		//WRITE TO DATABASE

		cout << " WRITER RELEASING FILE" << endl;
		rW.V();
		this_thread::sleep_for(chrono::seconds(1));
	}
}

int main()
{
	std::thread Reader1(Reader);
	std::thread Reader2(Reader);

	std::thread Writer1(Writer);
	std::thread Writer2(Writer);

	Reader1.join();
	Reader2.join();

	Writer1.join();
	Writer2.join();

	system("PAUSE");
}