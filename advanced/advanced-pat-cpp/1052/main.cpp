#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int keys[100000];
int nexts[100000];

bool cmp(int head1, int head2) {
	return keys[head1] < keys[head2];
}
int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, head;
	scanf("%d%d", &N, &head);
	int node, key, next;
	while (N--) {
		scanf("%d%d%d", &node, &key, &next);
		keys[node] = key;
		nexts[node] = next;
	}
	vector<int> list;
	while (head!=-1) {
		list.push_back(head);
		head = nexts[head];
	}
	sort(list.begin(), list.end(), cmp);
	if (list.empty()) {
		printf("0 -1\n");
	} else {
		printf("%d %05d\n", list.size(), list.front());
		vector<int>::iterator it = list.begin();
		printf("%05d %d", *it, keys[*it]);
		while (++it != list.end()) {
			printf(" %05d\n%05d %d", *it, *it, keys[*it]);
		}
		printf(" -1\n");
	}
}