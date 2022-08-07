#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <mutex>

class ThreadSafeLogger
{
public:
	std::mutex m_Mutex;
	virtual void Log(const std::string& log) = 0;
};

class FileLogger : public ThreadSafeLogger
{
	std::ofstream m_LogFile;
	static const std::string m_sFileLogger;
	FileLogger();
public:
	static FileLogger* m_pInstance();
	void Log(const std::string& log);
	~FileLogger();
};

class ConsoleLogger : public ThreadSafeLogger
{
	ConsoleLogger() {}
public:
	static ConsoleLogger* m_pInstance();
	void Log(const std::string& log);
	~ConsoleLogger(){}
};

// DBLogger can be implemented here
class DBLogger : public ThreadSafeLogger
{

};

// HTTPLogger can be implemented here
class HTTPLogger : public ThreadSafeLogger
{

};

#endif //LOGGER_H
