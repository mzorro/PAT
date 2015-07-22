#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, L;
	cin >> N >> L;
	vector<vector<int> > followers = vector<vector<int> >(N+1);
	for (int i = 1; i <= N; i++) {
		int M; cin >> M;
		int tmp;
		while (M--) {
			cin >> tmp;
			followers[tmp].push_back(i);
		}
	}
	int T; cin >> T;
	while (T--) {
		int user; cin >> user;
		vector<bool> vst(N+1, false);
		int cnt = 0;
		vst[user] = true;
		queue<int> qu, qd;
		qu.push(user);
		qd.push(0);
		while (!qu.empty()) {
			int u = qu.front();
			int d = qd.front();
			qu.pop(); qd.pop();
			if (d == L) break;
			vector<int>::iterator it = followers[u].begin();
			for (; it != followers[u].end(); it++) {
				if (vst[*it]) continue;
				vst[*it] = true;
				cnt++;
				qu.push(*it);
				qd.push(d+1);
			}
		}
		cout << cnt << endl;
	}
}