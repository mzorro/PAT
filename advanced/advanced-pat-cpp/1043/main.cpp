#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

vector<int> preOrder;
bool is_mirror = false;
struct Tree;
Tree *root;
struct Tree {
	int value;
	Tree *left, *right;

	Tree(int value, Tree *left, Tree *right)
		: value(value)
		, left(left)
		, right(right) {}

	void postOrderTraverse() {
		if (left) left->postOrderTraverse();
		if (right) right->postOrderTraverse();
		cout << value;
		if (this!=root) cout << ' ';
	}

	void midOrderTraverse(vector<int> &midOrder) {
		if (left) left->midOrderTraverse(midOrder);
		midOrder.push_back(value);
		if (right) right->midOrderTraverse(midOrder);
	}

	bool check() {
		vector<int> midOrder;
		midOrderTraverse(midOrder);
		vector<int>::iterator it = midOrder.begin();
		int tmp = *(it++);
		for (; it!=midOrder.end(); it++) {
			if ((is_mirror && *it > tmp) || 
				(!is_mirror && *it < tmp)) {
				return false;
			}
		}
		return true;
	}
};

Tree* build_tree(vector<int>::iterator beg,
				 vector<int>::iterator end) {
		if (beg==end) return NULL;
		int value = *(beg++);
		if (beg==end) return new Tree(value, NULL, NULL);
		vector<int>::iterator it, right(end);
		for (it=beg; it!=end; it++) {
			if ((!is_mirror && *it >= value) ||
				(is_mirror && *it < value)) {
				right = it;
				break;
			}
		}
		Tree *left_tree = build_tree(beg, right);
		Tree *right_tree = build_tree(right, end);
		return new Tree(value, left_tree, right_tree);
	}

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, n;
	cin >> N;
	while (N--) {
		cin >> n;
		preOrder.push_back(n);
	}
	if (preOrder.size() > 1) {
		is_mirror = preOrder[1] < preOrder[0] ? false : true;
	}
	root = build_tree(preOrder.begin(), preOrder.end());
	if (root->check()) {
		cout << "YES" << endl;
		root->postOrderTraverse();
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}