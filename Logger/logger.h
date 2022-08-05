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

class Filelogger :public ThreadSafeLogger
{
	std::ofstream m_Logfile;
	static const std::string m_sFilelogger;
	Filelogger();
public:
	static Filelogger* m_pInstance();
	void Log(const std::string& log);
	~Filelogger();
};

#endif //LOGGER_H
