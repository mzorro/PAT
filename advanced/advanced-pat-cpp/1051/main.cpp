#include <iostream>
#include <stack>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int M, N, Q;
	cin >> M >> N >> Q;
	while (Q--) {
		stack<int> st;
		int x, next = 1;
		bool impossible = false;
		for (int i = 0; i < N; i++) {
			cin >> x;
			if (impossible) continue;
			while (st.size() < unsigned(M) && x >= next) {
				st.push(next++);
			}
			if (st.top() != x) {
				impossible = true;
				cout << "NO\n";
			} else {
				st.pop();
			}
		}
		if (!impossible) {
			cout << "YES\n";
		}
	}
}