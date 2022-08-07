#include <iostream>
#include <thread>
#include "logger.h"
using namespace std;

ThreadSafeLogger* filelog = FileLogger::m_pInstance();
ThreadSafeLogger* consolelog = ConsoleLogger::m_pInstance();

void fun()
{
	for (int i = 0;i < 100;i++)
	{
		filelog->Log("This is fun()");
		consolelog->Log("This is fun()");
	}
}

int main()
{
	filelog->Log("Brajesh Kumar Singh");

	std::thread th(fun);

	for (int i = 0;i < 100;i++)
	{
		filelog->Log("This is main()");
		consolelog->Log("This is main()");
	}

	th.join();

	FileLogger::m_pInstance()->Log("I'm in main");
}