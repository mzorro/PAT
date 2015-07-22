#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

bool cmp(const vector<int> &v1, const vector<int> &v2) {
	vector<int>::const_reverse_iterator rit1, rit2;
	rit1 = v1.rbegin(), rit2 = v2.rbegin();
	while (rit1 != v1.rend() && rit2 != v2.rend()) {
		if (*rit1 > *rit2) {
			return true;
		} else if (*rit1 < *rit2) {
			return false;
		}
		rit1++, rit2++;
	}
	if (rit1 == v1.rend()) {
		return false;
	} else {
		return true;
	}
}

int pnt[200] = {-1};
int wet[200];
int non_leaf[200];
int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	memset(non_leaf, 0, sizeof(non_leaf));
	int N, M, S;
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &wet[i]);
	}
	while (M--) {
		int parent, cnt, node;
		scanf("%d%d", &parent, &cnt);
		non_leaf[parent] = 1;
		while (cnt--) {
			scanf("%d", &node);
			pnt[node] = parent;
		}
	}
	vector<vector<int> > paths;
	for (int i = 0; i < N; i++) {
		if (non_leaf[i]) continue;
		vector<int> path;
		path.push_back(wet[i]);
		int sum = wet[i];
		int parent = pnt[i];
		while (parent != -1) {
			path.push_back(wet[parent]);
			sum += wet[parent];
			if (sum > S) break;
			parent = pnt[parent];
		};
		if (sum == S) {
			paths.push_back(path);
		}
	}
	sort(paths.begin(), paths.end(), cmp);
	vector<vector<int> >::iterator it;
	for (it=paths.begin(); it!=paths.end(); it++) {
		vector<int>::reverse_iterator rit = it->rbegin();
		printf("%d", *rit);
		while (++rit != it->rend()) {
			printf(" %d", *rit);
		}
		printf("\n");
	}
}