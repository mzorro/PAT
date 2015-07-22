#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

vector<int> child[100];
int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	while (M--) {
		int id, n, c;
		cin >> id >> n;
		while (n--) {
			cin >> c;
			child[id].push_back(c);
		}
	}
	vector<int> leaf_cnt(N, 0);
	queue<int> qn, qd;
	qn.push(1); qd.push(0);
	int n, d;
	while (!qn.empty()) {
		n = qn.front();
		d = qd.front();
		qn.pop(); qd.pop();
		if (child[n].empty()) leaf_cnt[d]++;
		vector<int>::iterator it = child[n].begin();
		for (; it != child[n].end(); it++) {
			qn.push(*it); qd.push(d+1);
		}
	}
	cout << leaf_cnt[0];
	for (int i = 1; i <= d; i++) {
		cout << ' ' << leaf_cnt[i];
	}
	cout << endl;
}