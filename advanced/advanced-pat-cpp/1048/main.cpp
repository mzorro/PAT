#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	vector<int> coins(N);
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}
	sort(coins.begin(), coins.end());
	bool found = false;
	vector<int>::iterator it;
	for (it = coins.begin(); it != coins.end(); it++) {
		if (*it * 2 > M) break;
		if (found = binary_search(it+1, coins.end(), M-*it)) {
			cout << *it << ' ' << M-*it << endl;
			break;
		}
	}
	if (!found) {
		cout << "No Solution" << endl;
	}
}