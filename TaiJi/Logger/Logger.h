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
			
			void Log(Level level, const char * file, int line, const char format, ...);// ��εĶ��巽ʽ��
		public:
			static Logger* Instance();//����ģʽ
			void Open(const string& filename);
			void Close();
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


