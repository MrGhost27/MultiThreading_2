// Performance Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::cout;
using std::to_string;

class TIMER
{
	LARGE_INTEGER t_;

	__int64 current_time_;

public:
	TIMER()	// Default constructor. Initialises this timer with the current value of the hi-res CPU timer.
	{
		QueryPerformanceCounter(&t_);
		current_time_ = t_.QuadPart;
	}

	TIMER(const TIMER &ct)	// Copy constructor.
	{
		current_time_ = ct.current_time_;
	}

	TIMER& operator=(const TIMER &ct)	// Copy assignment.
	{
		current_time_ = ct.current_time_;
		return *this;
	}

	TIMER& operator=(const __int64 &n)	// Overloaded copy assignment.
	{
		current_time_ = n;
		return *this;
	}

	~TIMER() {}		// Destructor.

	static __int64 get_frequency()
	{
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		return frequency.QuadPart;
	}

	__int64 get_time() const
	{
		return current_time_;
	}

	void get_current_time()
	{
		QueryPerformanceCounter(&t_);
		current_time_ = t_.QuadPart;
	}

	inline bool operator==(const TIMER &ct) const
	{
		return current_time_ == ct.current_time_;
	}

	inline bool operator!=(const TIMER &ct) const
	{
		return current_time_ != ct.current_time_;
	}

	__int64 operator-(const TIMER &ct) const		// Subtract a TIMER from this one - return the result.
	{
		return current_time_ - ct.current_time_;
	}

	inline bool operator>(const TIMER &ct) const
	{
		return current_time_ > ct.current_time_;
	}

	inline bool operator<(const TIMER &ct) const
	{
		return current_time_ < ct.current_time_;
	}

	inline bool operator<=(const TIMER &ct) const
	{
		return current_time_ <= ct.current_time_;
	}

	inline bool operator>=(const TIMER &ct) const
	{
		return current_time_ >= ct.current_time_;
	}
};

struct NVPair {
	string name;
	string value;

	string PairString() {
		return "\"" + name + "\" : \"" + value + "\"";
	}
};

struct IP {
	int tri1;
	int tri2;
	int tri3;
	int tri4;

	IP() {};
	IP(int a, int b, int c, int d) {
		tri1 = a;
		tri2 = b;
		tri3 = c;
		tri4 = d;
	}

	bool operator==(const IP& compareAgainst)
	{
		if (compareAgainst.tri1 - tri1 != 0)
			return false;
		else if (compareAgainst.tri2 - tri2 != 0)
			return false;
		else if (compareAgainst.tri3 - tri3 != 0)
			return false;
		else if (compareAgainst.tri4 - tri4 != 0)
			return false;
		return true;
	}

	string IPString() {
		string answer = "" + to_string(tri1);
		answer += ".";
		answer += to_string(tri2);
		answer += ".";
		answer += to_string(tri3);
		answer += ".";
		answer += to_string(tri4);
		
		return answer;
	}
};

int main()
{
	// Application starts here...

	// Time the application's execution time.
	TIMER start;	// DO NOT CHANGE THIS LINE. Timing will start here.

					//--------------------------------------------------------------------------------------
					// Insert your code from here...

	NVPair IPAddressNVP;
	IP fakeIP;
	fakeIP.tri1 = 12;
	fakeIP.tri2 = 123;
	fakeIP.tri3 = 1;
	fakeIP.tri4 = 16;

	IP fakeIP2(123, 21, 42, 156);
	IP fakeIP3(123, 21, 42, 156);

	if (fakeIP2 == fakeIP)
		cout << "Same IP\n";
	else cout << "Different IP\n";

	IPAddressNVP.name = "ip";
	IPAddressNVP.value = fakeIP.IPString();

	cout << IPAddressNVP.PairString() << "\n";

					//-------------------------------------------------------------------------------------------------------
					// How long did it take?...   DO NOT CHANGE FROM HERE...

	TIMER end;

	TIMER elapsed;

	elapsed = end - start;

	__int64 ticks_per_second = start.get_frequency();

	// Display the resulting time...

	double elapsed_seconds = (double)elapsed.get_time() / (double)ticks_per_second;

	std::cout.precision(17);
	std::cout << "Elapsed time (seconds): " << std::fixed << elapsed_seconds;
	std::cout << std::endl;
	std::cout << "Press a key to continue" << std::endl;

	char c;
	std::cin >> c;

    return 0;
}

