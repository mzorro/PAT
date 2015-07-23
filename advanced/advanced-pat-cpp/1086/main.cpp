#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
#pragma warning(disable:4996)

struct BTree {
	int value;
	BTree *lchild, *rchild;
	BTree(int value, BTree *lchild, BTree *rchild)
		: value(value)
		, lchild(lchild)
		, rchild(rchild) {}

	void postOrder(vector<int> &res) {
		if (lchild) lchild->postOrder(res);
		if (rchild) rchild->postOrder(res);
		res.push_back(value);
	}
};

vector<int> preOrder, inOrder;
BTree* build(int preBeg, int preEnd, int inBeg, int inEnd) {
	if (preBeg > preEnd) return NULL;
	int inMid = inBeg;
	while (preOrder[preBeg] != inOrder[inMid]) inMid++;
	int preMid = preBeg + inMid - inBeg;
	return new BTree(preOrder[preBeg],
		build(preBeg+1, preMid, inBeg, inMid-1),
		build(preMid+1, preEnd, inMid+1, inEnd));
}

int main() {
	//freopen("..\\input.txt", "r", stdin);
	int N; cin >> N;
	stack<int> st;
	int popCount = 0;
	while (popCount < N) {
		string cmd;
		cin >> cmd;
		if (cmd == "Push") {
			int n; cin >> n;
			preOrder.push_back(n);
			st.push(n);
		} else {
			popCount++;
			inOrder.push_back(st.top());
			st.pop();
		}
	}

	BTree *bt = build(0, N-1, 0, N-1);
	vector<int> res;
	bt->postOrder(res);
	vector<int>::iterator it = res.begin();
	cout << *it;
	for (it++; it != res.end(); it++) {
		cout << ' ' << *it;
	}
	cout << endl;
}