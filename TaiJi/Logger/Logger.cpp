#include "Logger.h"

namespace Taiji
{
	namespace utility
	{
		Logger* Logger::m_ptrInstance = nullptr;
		const char* Logger::s_level[LEVEL_COUNT] = { "DEBUG","INFO","WRAN","ERROR","FATAL" };
		//����ģʽ��
		Logger * Logger::Instance()
		{
			if (!m_ptrInstance)
			{
				m_ptrInstance = new Logger();

			}
			return m_ptrInstance;
		}
		Logger::Logger()
		{
		}


		Logger::~Logger()
		{
		}
	}
}
