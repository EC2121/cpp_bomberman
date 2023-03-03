#pragma once
#include<memory>
namespace Core {
	class Time{

	public:
		~Time() = default;
		Time(const Time&) = default;
		Time& operator=(const Time&) = delete;
	protected:
		Time();

	public:
		static Time& GetInstance();
		static float GetDeltatime() { return deltatime; }
		void Update();
	private:
		static float now;
		static float last;
		static float deltatime;
		static std::unique_ptr<Time> instance;

	};
}