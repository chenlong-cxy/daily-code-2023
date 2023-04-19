#include <iostream>
#include <vector>
using namespace std;
int findMax(vector<int>& sequence) {
	int left = 0, right = sequence.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (mid + 1 <= right && sequence[mid + 1] > sequence[mid]) {
			left = mid + 1;
		}
		else if (mid - 1 >= left && sequence[mid - 1] > sequence[mid]) {
			right = mid - 1;
		}
		else {
			return sequence[mid];
		}
	}
	return -1;
}
int main() {
	vector<int> v = { 2, 3, 5, 6, 4, 3, 2,1 };
	cout << findMax(v) << endl;
	return 0;
}
