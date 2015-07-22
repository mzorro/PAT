#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#pragma warning(disable:4996)

struct BinTree {
	static const int MAXN = 100001;
	vector<int> a;

	BinTree() {
		a = vector<int>(MAXN, 0);
	}

	void add(int pos, int value) {
		while (pos < MAXN) {
			a[pos] += value;
			pos += pos&(-pos);
		}
	}

	int at(int pos) {
		int sum = 0;
		while (pos > 0) {
			sum += a[pos];
			pos -= pos&(-pos);
		}
		return sum;
	}

	int find(int value, int l = 0, int h = MAXN-1) {
		if (l==h) return l;
		int mid = (l + h) / 2;
		if (at(mid) < value) {
			return find(value, mid+1, h);
		} else {
			return find(value, l, mid);
		}
	}
} tree;

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	stack<int> stk;
	char cmd[11];
	int n, mid = 0;
	while (N--) {
		scanf("%s", cmd);
		switch(cmd[1]) {
		case 'u': // push
			scanf("%d", &n);
			stk.push(n);
			tree.add(n, 1);
			break;
		case 'o': // pop
			if (stk.empty()) {
				printf("Invalid\n");
			} else {
				n = stk.top();
				printf("%d\n", n);
				stk.pop();
				tree.add(n, -1);
			}
			break;
		case 'e': // peekMedian
			if (stk.empty()) {
				printf("Invalid\n");
			} else {
				printf("%d\n", tree.find((stk.size()+1)/2));
			}
			break;
		}
	}
}