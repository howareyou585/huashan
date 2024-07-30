#pragma once
#include <string>
#include <fstream>
using namespace std;
namespace Taiji
{
	namespace utility
	{
		class Logger
		{
		
		public:
			enum  Level
			{
				DEBUG =0,
				INFO,
				WARN,
				ERROR,
				FATAL,
				LEVEL_COUNT //
			};
		
		public:
			
			void Log(Level level, const char * file, int line, const char format, ...);// 变参的定义方式。
		public:
			static Logger* Instance();//单例模式
			void Open(const string& filename);
			void Close();
		private:
			Logger(); // 单例模式，构造器私有
			~Logger();
		private:
			string m_filename;
			ofstream m_fout;//文件输出流
		private:

			static const char* s_level[LEVEL_COUNT]; //等级的字符串表示。
			static Logger* m_ptrInstance;
		};
	}
}


