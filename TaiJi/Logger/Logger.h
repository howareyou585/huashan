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
			
			void Log(Level level, const string& file, int line, ...);// ��εĶ��巽ʽ��
		public:
			Logger* Instance();//����ģʽ
		private:
			Logger(); // ����ģʽ��������˽��
			~Logger();
		private:
			string m_filename;
			ofstream m_fout;//�ļ������
		private:

			static const char* s_level[LEVEL_COUNT]; //�ȼ����ַ�����ʾ��
			static Logger* m_ptrInstance;
		};
	}
}


