#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

struct TNode {
	double money;
	int pnt;
	vector<int> children;
	TNode() : money(0.0), pnt(-1), children(vector<int>()) {}
};
vector<TNode> tree;
int N;
double P, R;

double postOrder(int root) {
	if (tree[root].children.empty()) return tree[root].money;
	vector<int>::iterator it = tree[root].children.begin();
	for (; it != tree[root].children.end(); it++) {
		tree[root].money += postOrder(*it);
	}
	return tree[root].money *= R;
}

int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	scanf("%d%lf%lf", &N, &P, &R);
	R = 1 + R/100;
	tree = vector<TNode>(N);
	for (int i = 0; i < N; i++) {
		int n; scanf("%d", &n);
		if (n > 0) {
			while (n--) {
				int child; scanf("%d", &child);
				tree[i].children.push_back(child);
			}
		} else {
			int amount; scanf("%d", &amount);
			tree[i].money = amount * P;
		}
	}
	
	printf("%.1lf\n", postOrder(0));
}