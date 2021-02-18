#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <chrono>

class Timer
{
public:
	using clock_t = std::chrono::steady_clock;
	using time_point_t = clock_t::time_point;
	Timer() : m_begin(clock_t::now()), duration(0) {}
	~Timer() {
		this->pause();
		std::cout << duration << " milliseconds" << std::endl;
	}

	void pause() {
		auto end = clock_t::now();
		duration += std::chrono::duration_cast <std::chrono::milliseconds> (end - m_begin).count();
	}

	void goon() {
		m_begin = clock_t::now();
	}
private:
	time_point_t m_begin;
	int duration;
};


int main() {
	
		{
			std::deque <int> d;// deque - 120 msec
			for (auto i = 1; i < 10000; ++i)
			{
				d.push_back(10000 - i);
			}
			Timer t;
			std::sort(d.begin(), d.end());
			t.pause();
		}
{
		std::vector <int> v;// vector - 38 msec
		for (auto i = 1; i < 10000; ++i)
		{
			v.push_back(10000- i);
		}
		Timer t;
		std::sort(v.begin(), v.end());
		t.pause();
	}
	{
		std::array <int, 10000> a;// array - 28 msec
		for (auto i = 1; i < 10000; ++i)
		{
			a[i] = 10000 - i;
		}
		Timer t;
		std::sort(a.begin(), a.end());
		t.pause();
	}
	{
		std::list <int> l;// list - 18 msec
		for (auto i = 1; i < 10000; ++i)
		{
			l.push_back(10000 - i);
		}
		Timer t;
		l.sort();
		t.pause();
	}
	{
		std::forward_list <int> fl;//forward-list 16 msec
		for (auto i = 1; i < 10000; ++i)
		{
			fl.push_front(10000 - i);
		}
		Timer t;
		fl.sort();
		t.pause();
	}
	return 0;
}

