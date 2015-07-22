#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;

struct subtree {
	int pbeg, pend; // post order
	int ibeg, iend; // in order

	subtree(int pb, int pe, int ib, int ie)
		: pbeg(pb), pend(pe)
		, ibeg(ib), iend(ie) {}

	bool isNotEmpty() {
		if (pend >= pbeg && iend >= ibeg)
			return true;
		else
			return false;
	}
};

int indexof(int n, int* array) {
	for (int i = 0; i < N; i++) {
		if (array[i]==n) return i;
	}
	return -1;
}

void print_vector(vector<int> &v) {
	vector<int>::iterator it = v.begin();
	cout << *it;
	for (it++; it!=v.end(); it++) {
		cout << ' ' << *it;
	}
}

int main() {
	cin >> N;
	int* post_order = new int[N];
	int* in_order = new int[N];
	for (int i = 0; i < N; i++)
		cin >> post_order[i];
	for (int i = 0; i < N; i++)
		cin >> in_order[i];
	queue<subtree> q;
	q.push(subtree(0, N-1, 0, N-1));
	vector<int> level_order;
	while(!q.empty()) {
		subtree st = q.front();
		q.pop();
		if(st.isNotEmpty()) {
			int root = post_order[st.pend];
			level_order.push_back(root);
			int ipos = indexof(root, in_order);
			int ppos = ipos - st.ibeg + st.pbeg;
			q.push(subtree(st.pbeg, ppos-1, st.ibeg, ipos-1));
			q.push(subtree(ppos, st.pend-1, ipos+1, st.iend));
		}
	}
	print_vector(level_order);
}