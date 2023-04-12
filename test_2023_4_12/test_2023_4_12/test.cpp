#include <iostream>
#include <cmath>
using namespace std;
//O(n)
void function1(long long n) {
	long long k = 0;
	for (long long i = 0; i < n; i++) {
		k++;
	}
}
//O(n^2)
void function2(long long n) {
	long long k = 0;
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			k++;
		}
	}
}
//O(nlogn)
void function3(long long n) {
	long long k = 0;
	for (long long i = 0; i < n; i++) {
		for (long long j = 1; j < n; j *= 2) {
			k++;
		}
	}
}
int main() {
	clock_t start = clock();
	//function1(100000000); //105
	//function2(10000); //103
	//function3(1000000); //49
	clock_t end = clock();
	cout << end - start << endl;

	start = clock();
	//function1(1000000000); //1028
	//function2(100000); //10266
	//function3(10000000); //670
	end = clock();
	cout << end - start << endl;

	start = clock();
	//function1(500000000); //513
	//function2(50000); //2572
	//function3(5000000); //280
	end = clock();
	cout << end - start << endl;
	return 0;
}
//10ÒÚ´Î/s