#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

struct TNode {
	int left, right, val;
};

vector<TNode> nodes;
vector<int> val;

int inOrderPos = 0;
void inOrderTraversal(int node = 0) {
	if (nodes[node].left > 0) inOrderTraversal(nodes[node].left);
	nodes[node].val = val[inOrderPos++];
	if (nodes[node].right > 0) inOrderTraversal(nodes[node].right);
}

void levelOrderTraversal() {
	queue<int> q;
	q.push(0);
	int level = 0, count = 1;
	while (!q.empty()) {
		int n = q.front(); q.pop();
		cout << nodes[n].val;
		if (--count == 0) {
			level += 1;
			count = q.size();
		}
		if (nodes[n].left > 0) q.push(nodes[n].left);
		if (nodes[n].right > 0) q.push(nodes[n].right);
		if (!q.empty()) cout << " ";
	}
	cout << endl;
}

int main() {
	//freopen("..\\input.txt", "r", stdin);
	int N; cin >> N;
	nodes  = vector<TNode>(N);
	val = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> nodes[i].left >> nodes[i].right;
	}
	for (int i = 0; i < N; i++) {
		cin >> val[i];
	}
	sort(val.begin(), val.end());
	inOrderTraversal();
	levelOrderTraversal();
}
