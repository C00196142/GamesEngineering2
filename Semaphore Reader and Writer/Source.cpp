#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

struct Semaphore
{
public:
	Semaphore() {};
	~Semaphore() {};

	int rw = 1;
	int mutexR = 1;

	void P(int &mR)
	{
		mR--;
	}

	void V(int &mR)
	{
		mR++;
	}

};


int nr = 0;
Semaphore m_semaphore;

void Reader()
{
	bool running = true;
	while (running)
	{
		cout <<  " idREADER: " << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::seconds(1));
		m_semaphore.P(m_semaphore.mutexR);
		nr++;
		if (nr == 1)
		{
			m_semaphore.P(m_semaphore.rw);
		}
		
		//LOCK//
		m_semaphore.V(m_semaphore.mutexR);
		
		cout << " READING DATABASE... " << endl;
		m_semaphore.P(m_semaphore.mutexR);
		nr--;
		if (nr == 0)
		{
			m_semaphore.V(m_semaphore.rw);
		}

		m_semaphore.V(m_semaphore.mutexR);
		//LOCK//
	}
}

void Writer()
{
	bool running = true;
	while (running)
	{
		cout << " idWRITER: " << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::seconds(1));

		m_semaphore.P(m_semaphore.rw);
		cout << " WRITING TO DATABASE... " << endl;
		m_semaphore.V(m_semaphore.rw);
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