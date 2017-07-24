#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdio>
#include <vector>

#define getNow() \
std::chrono::system_clock::now()
//#define getProcessTime() \
//std::chrono::duration 
namespace data{
	int input = 1e9 + 7;
	bool answer = 1;
	std::chrono::system_clock::time_point startTime;

	typedef struct {
		bool result;
		char functionName[22];
		std::chrono::duration<double> elapsedTime;
	}NODE;

	std::vector<NODE> v;

	void proc(int (*pf)(int)) {

	}
	void display(){
		puts("+----------+---------------------+--------------------+");
		puts("|  RESULT  |    FUNCTION NAME    |  ELAPSED TIME(sec) |");
		puts("+----------+---------------------+--------------------+");
		for (NODE x : v) {
			printf("|%10s|%21s|%20lf|\n", x.result ? "PASSED" : "FAILED", x.functionName, x.elapsedTime.count());
		}
		puts("+----------+---------------------+--------------------+");
	}

}

namespace gose{
	bool isPrime(const int n) { // O( sqrt(N) )
		if (n < 2)return 0;
		if (n < 4)return 1;
		if (n % 2 == 0 || n % 3 == 0)return 0;
		for (int i = 5; i*i < n; i += 6) {
			if (n%i == 0 || n % (i + 2) == 0)return 0;
		}
		return 1;
	}
}

namespace basic {
	bool isPrime(const int n) { // O( N )
		if (n < 2)return 0;
		for (int i = 2; i < n; ++i)
			if (n%i == 0)return 0;
		return 1;
	}
}

int main()
{
	std::chrono::system_clock::time_point startTime;
	std::chrono::duration<double> elapsedTime;


}