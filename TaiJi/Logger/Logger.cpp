#include "Logger.h"

namespace Taiji
{
	namespace utility
	{
		Logger* Logger::m_ptrInstance = nullptr;
		const char* Logger::s_level[LEVEL_COUNT] = { "DEBUG","INFO","WRAN","ERROR","FATAL" };
		//µ¥ÀýÄ£Ê½¡£
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
