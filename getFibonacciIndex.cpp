//给一个数，问是第几个Fibonacci, 不是Fibonacci 就是的话就是前一个index

#include <iostream>

using namespace std;

int getFibIndex (int target) {
	if (target == 0)
		return 0;
	else if (target == 1)
		return 1;
	int prev = 1, prevPrev = 0, idx = 2;
	while (true) {
		int cur = prev + prevPrev;
		if (cur == target) {
			return idx;
		}
		else if (cur > target) {
			return idx - 1;
		}
		idx++;
		prevPrev = prev;
		prev = cur;
	}
	return 0; // should never be reached.
}

int main () {
	cout << getFibIndex (0) << endl;
	cout << getFibIndex (1) << endl;
	cout << getFibIndex (3) << endl;
	cout << getFibIndex (4) << endl;
	cout << getFibIndex (5) << endl;
	cout << getFibIndex (8) << endl;
	return 0;
}
