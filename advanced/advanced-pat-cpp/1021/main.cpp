#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
using namespace std;
#define MAXV 10001

int N;
vector<int> map[MAXV];
int deepth[MAXV];
int max_deepth = 0;

void bfs(int n) {
	queue<int> q;
	q.push(n);
	deepth[n] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(deepth[now] > max_deepth) {
			max_deepth = deepth[now];
		}
		vector<int>::iterator it = map[now].begin();
		for (; it!=map[now].end(); it++) {
			if(deepth[*it]==-1) {
				deepth[*it] = deepth[now] + 1;
				q.push(*it);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int n1, n2;
		cin >> n1;
		cin >> n2;
		map[n1].push_back(n2);
		map[n2].push_back(n1);
	}
	int count = 1;
	memset(deepth, -1, sizeof(deepth));
	bfs(1);
	for (int i = 1; i <= N; i++) {
		if(deepth[i]==-1) {
			count += 1;
			bfs(i);
		}
	}
	if(count != 1) {
		cout << "Error: " << count << " components" << endl;
	} else {
		set<int> deepest_roots;
		for (int i = 1; i <= N; i++) {
			if (deepth[i]==max_deepth) {
				deepest_roots.insert(i);
			}
		}
		memset(deepth, -1, sizeof(deepth));
		bfs(*deepest_roots.begin());
		for (int i = 1; i <= N; i++) {
			if (deepth[i]==max_deepth) {
				deepest_roots.insert(i);
			}
		}
		set<int>::iterator it = deepest_roots.begin();
		for(; it!=deepest_roots.end(); it++) {
			cout << *it << endl;
		}
	}
}