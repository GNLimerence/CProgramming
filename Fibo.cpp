#include <iostream>
#include <map>
#include <chrono>
using namespace std;

const int MAXN = 100;

map <int, int> mem;

int fib (int n) {
	if (n <= 2) return 1;
	return fib (n-1) + fib (n-2);
}

int fib_dp (int n) {
	if (n <= 2) return 1;
	if (mem.find(n) != mem.end()) return mem[n];
	int res = fib_dp(n-2) + fib_dp(n-1);
	mem[n] = res;
	return res;
}

int main () {
	int n;
	std::cin >> n;
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << fib_dp(n) << endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::microseconds>(end - start);
	std::cout << duration.count() << "ms" << endl;
	return 0;
}