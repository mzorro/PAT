#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	long long N, p;
	cin >> N >> p;
	vector<long long> seq = vector<long long>(N);
	for (long long i = 0; i < N; i++) {
		cin >> seq[i];
	}
	sort(seq.begin(), seq.end());

	long long m = 0, M = 0;
	while (M < N && seq[M] <= seq[m] * p) M++;
	long long maxn = M - m;
	while (M < N) {
		m++;
		while (M < N && seq[M] <= seq[m] * p) M++;
		if (maxn < M - m) maxn = M - m;
	}
	cout << maxn << endl;
}