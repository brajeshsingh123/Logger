#include <iostream>
#include <mutex>
#include <string>
#include "logger.h"
using namespace std;

const string FileLogger::m_sFileLogger = "FileLog.txt";

FileLogger::FileLogger()
{
	m_LogFile.open(m_sFileLogger, std::ios_base::app);
}

FileLogger* FileLogger::m_pInstance()
{
	static FileLogger* loggerInst = new FileLogger();
	return loggerInst;
}

void FileLogger::Log(const std::string& log)
{
	std::unique_lock<mutex> lock(m_Mutex);
	m_LogFile << log << endl;
}

FileLogger::~FileLogger()
{
	m_LogFile.close();
}

ConsoleLogger* ConsoleLogger::m_pInstance()
{
	static ConsoleLogger* loggerInst = new ConsoleLogger();
	return loggerInst;
}

void ConsoleLogger::Log(const std::string& log)
{
	std::unique_lock<mutex> lock(m_Mutex);
	std::cout << log << endl;
}
