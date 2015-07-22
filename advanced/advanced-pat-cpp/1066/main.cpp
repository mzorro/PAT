#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class AVLTree {
	struct TNode {
		int value, height;
		TNode *left, *right, *pnt;
		TNode(int value)
			: value(value)
			, height(1)
			, left(NULL)
			, right(NULL)
			, pnt(NULL) {}
	};
public:
	TNode *root;
	AVLTree() : root(NULL) {}
	
	void insert(int value) {
		TNode *p = new TNode(value);
		if (root == NULL) { root = p; return; }
		TNode *q = NULL, *r = root;
		while (r != NULL) {
			q = r;
			if (p->value > r->value) r = r->right;
			else r = r->left;
		}
		if (p->value > q->value) {
			q->right = p;
		} else {
			q->left = p;
		}
		p->pnt = q;
		correct(q);
	}

	void calc_height(TNode* p) {
		p->height = max(get_height(p->left), get_height(p->right)) + 1;
	}

	int get_height(TNode* p) {
		if (p == NULL) return 0;
		else return p->height;
	}

	int factor(TNode* p) {
		return get_height(p->right) - get_height(p->left);
	}

	void correct(TNode *p) {
		if (p == NULL) return;
		calc_height(p);
		if (factor(p) > 1) {
			if (factor(p->right) < 0) rotate_LL(p->right);
			rotate_RR(p);
		} else if (factor(p) < -1) {
			if (factor(p->left) > 0) rotate_RR(p->left);
			rotate_LL(p);
		}
		correct(p->pnt);
	}

	void rotate_LL(TNode *p) {
		TNode *pnt = p->pnt;
		if (pnt == NULL) {
			root = p->left;
			p->left->pnt = NULL;
		} else if (p == pnt->left) {
			pnt->left = p->left;
			p->left->pnt = pnt;
		} else {
			pnt->right = p->left;
			p->left->pnt = pnt;
		}
		TNode *tmp = p->left->right;
		p->left->right = p;
		p->pnt = p->left;
		p->left = tmp;
		if (tmp) tmp->pnt = p;
		calc_height(p);
		calc_height(p->pnt);
	}

	void rotate_RR(TNode *p) {
		TNode *pnt = p->pnt;
		if (pnt == NULL) {
			root = p->right;
			p->right->pnt = NULL;
		} else if (p == pnt->right) {
			pnt->right = p->right;
			p->right->pnt = pnt;
		} else {
			pnt->left = p->right;
			p->right->pnt = pnt;
		}
		TNode *tmp = p->right->left;
		p->right->left = p;
		p->pnt = p->right;
		p->right = tmp;
		if (tmp) tmp->pnt = p;
		calc_height(p);
		calc_height(p->pnt);
	}
};

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N;
	cin >> N;
	AVLTree tree;
	int tmp;
	while (N--) {
		cin >> tmp;
		tree.insert(tmp);
	}
	cout << tree.root->value << endl;
}