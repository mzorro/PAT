#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int full[6];
struct User {
	int id, sum, perfect;
	vector<int> score;
	bool flag;
	User() : id(0), sum(0), perfect(0), score(vector<int>(6, -2)), flag(false) {}
	bool operator<(const User &r) const {
		if (flag && !r.flag) return true;
		if (!flag && r.flag) return false;
		if (sum > r.sum) return true;
		if (sum == r.sum) {
			if (perfect > r.perfect) return true;
			if (perfect == r.perfect && id < r.id) return true;
		}
		return false;
	}
};
int main() {
	// freopen("..\\input.txt", "r", stdin);
	int N, K, M;
	cin >> N >> K >> M;
	for (int i = 1; i <= K; i++) cin >> full[i];
	vector<User> users(N+1);
	int id, p, s;
	while (M--) {
		cin >> id >> p >> s;
		User &u = users[id];
		u.id = id;
		if (s > u.score[p]) {
			if (u.score[p] > 0) u.sum -= u.score[p];
			u.score[p] = s;
			if (s >= 0) {
				u.flag = true;
				u.sum += s;
				if (s == full[p]) u.perfect++;
			}
		}
	}
	users.erase(users.begin());
	vector<User>::iterator it;
	sort(users.begin(), users.end());
	int rank = 0, same = 1, last = 0;
	for (it = users.begin(); it != users.end(); it++) {
		if (!it->flag) break;
		if (it->sum != last) {
			rank += same;
			same = 1;
		} else {
			same++;
		}
		printf("%d %05d %d", rank, it->id, it->sum);
		for (int i = 1; i <= K; i++) {
			cout << ' ';
			if (it->score[i] == -2) cout << '-';
			else if (it->score[i] == -1) cout << '0';
			else cout << it->score[i];
		}
		cout << endl;
		last = it->sum;
	}
}