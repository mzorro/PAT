#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

bool isPrime(long num) {
	if (num == 1) {
		return false;
	} else if (num == 2) {
		return true;
	} else {
		for (long i = 3; i <= long(sqrt(num)); i++) {
			if (num % i == 0) {
				return false;
			}
		}
	}
	return true;
}

long getNextPrime(long num) {
	for (long i = num + 1;;i++) {
		if (isPrime(i)) {
			return i;
		}
	}
	return 0;
}

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	long N, n;
	cin >> N;
	n = N;
	vector<pair<int, int> > factors;
	int i = 2, cnt;
	while (N > 1) {
		cnt = 0;
		while (N % i==0) {
			cnt++;
			N /= i;
		}
		if (cnt > 0) {
			factors.push_back(pair<int, int>(i, cnt));
		}
		i = getNextPrime(i);
	}
	cout << n << '=';
	if (factors.empty()) {
		cout << n << endl;
		return 0;
	};
	auto it = factors.begin();
	cout << it->first;
	if (it->second > 1) {
		cout << '^' << it->second;
	}
	while (++it != factors.end()) {
		cout << '*' << it->first;
		if (it->second > 1) {
			cout << '^' << it->second;
		}
	}
	cout << endl;
}