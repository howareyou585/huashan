#pragma once
namespace ThreadPool
{
	class NoneCopy
	{
	public:
		NoneCopy();
		virtual ~NoneCopy();
	public:
		NoneCopy(const NoneCopy&) = delete;
		NoneCopy& operator =(const NoneCopy&) = delete;
	};
}

