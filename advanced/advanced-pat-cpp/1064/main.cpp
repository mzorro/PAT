#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

struct Node{
	int value;
	Node *left, *right;
	Node(vector<int> &a) {
		int len = a.size();
		int base = (int)(log(len)/log(2));
		int low = (int)pow(2, base) - 1;
		int high = (int)pow(2, base+1) - 1;
		int mid = (low + high) / 2;
		int pos;
		if (len <= mid) {
			pos = low / 2 + len - low;
		} else {
			pos = high / 2;
		}
		value = a[pos];
		vector<int> lefta(a.begin(), a.begin()+pos);
		if (lefta.empty()) left = nullptr;
		else left = new Node(lefta);
		vector<int> righta(a.begin()+pos+1, a.end());
		if (righta.empty()) right = nullptr;
		else right = new Node(righta);
	}

	void levelprint() {
		queue<Node*> q;
		q.push(this);
		vector<int> out;
		while (!q.empty()) {
			Node *p = q.front();
			q.pop();
			out.push_back(p->value);
			if (p->left) q.push(p->left);
			if (p->right) q.push(p->right);
		}
		auto it = out.begin();
		cout << *it;
		while (++it!=out.end()) {
			cout << ' ' << *it;
		}
		cout << endl;
	}
};
int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, value;
	cin >> N;
	vector<int> a;
	while (N--) {
		cin >> value;
		a.push_back(value);
	}
	sort(a.begin(), a.end());
	Node tree(a);
	tree.levelprint();
}