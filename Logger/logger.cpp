#include "logger.h"
#include <mutex>
#include <string>
using namespace std;

const string Filelogger::m_sFilelogger = "FileLog.txt";

Filelogger::Filelogger()
{
	m_Logfile.open(m_sFilelogger, std::ios_base::app);
}

Filelogger* Filelogger::m_pInstance()
{
	static Filelogger* loggerInst = new Filelogger();
	return loggerInst;
}

void Filelogger::Log(const std::string& log)
{
	std::unique_lock<mutex> lock(m_Mutex);
	m_Logfile << log << endl;
}

Filelogger::~Filelogger()
{
	m_Logfile.close();
}
