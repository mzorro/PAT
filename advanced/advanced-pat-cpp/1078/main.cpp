#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int l = (int) sqrt(n);
	for (int i = 3; i <= l; i+=2)
		if (n % i == 0) return false;
	return true;
}

int getMinPrimeGT(int n) {
	while (!isPrime(n)) n++;
	return n;
}

void print(int n) {
	if (n == -1) cout << '-';
	else cout << n;
}

int main() {
	// freopen("..\\input.txt", "r", stdin);
	int MSize, N;
	cin >> MSize >> N;
	MSize = getMinPrimeGT(MSize);
	vector<bool> table = vector<bool>(MSize, false);
	vector<int> res = vector<int>();
	while (N--) {
		int n; cin >> n;
		n = n % MSize;
		int pos = -1;
		for (int i = 0; i < MSize; i++)
		{
			int tmp = (n + i * i) % MSize;
			if (!table[tmp]) {
				table[tmp] = true;
				pos = tmp;
				break;
			}
		}
		res.push_back(pos);
	}

	auto it = res.begin();
	print(*it);
	for (it++; it != res.end(); it++) {
		cout << ' ';
		print(*it);
	}
	cout << endl;
}