#include "Logger.h"
#include <iostream>
#include <time.h>
using namespace std;
namespace Taiji
{
	namespace utility
	{
		Logger* Logger::m_ptrInstance = nullptr;
		const char* Logger::s_level[LEVEL_COUNT] = { "DEBUG","INFO","WRAN","ERROR","FATAL" };
		//等级 文件 行号 内容 

		void Logger::Log(Level level, const char * file, int line, const char *format, ...)
		{
			if (m_fout.fail())
			{
				throw logic_error("open file fail:" + m_filename);
			}
			time_t ticks = time(NULL);
			auto tm = localtime(&ticks);
			char buffer[32];
			memset(buffer, 0, sizeof(buffer));
			strftime(buffer, sizeof(buffer), "%Y-%M-%d %H:%M:%S", tm);
			
			m_fout.write(buffer, sizeof(buffer));
			m_fout.flush();
		}
		//单例模式。
		Logger * Logger::Instance()
		{
			if (!m_ptrInstance)
			{
				m_ptrInstance = new Logger();

			}
			return m_ptrInstance;
		}
		void Logger::Open(const string & filename)
		{
			m_fout.open(filename, ios::app);
			if (m_fout.fail())
			{
				throw logic_error("open file error:" + filename);
			}
			
		}
		void Logger::Close()
		{
			m_fout.close();
			if (m_fout.fail())
			{
				throw logic_error("close file error:" + m_filename);
			}
		}
		Logger::Logger()
		{
		}


		Logger::~Logger()
		{
		}
	}
}
