#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

vector<int> resouce;
vector<vector<pair<int, int>> > matrix;
vector<bool> vst;
int N, M, C1, C2;

int cnt = 0, maxr = 0, mindis = MAX_INT;
void dfs(int cur, int dis, int res) {
	if (cur == C2 && dis <= mindis) {
		if (dis == mindis) {
			cnt++;
			maxr = max(maxr, res);
		} else {
			mindis = dis;
			cnt = 1;
			maxr = res;
		}
	}
	if (dis >= mindis) return;
	vector<pair<int, int>>::iterator it = matrix[cur].begin();
	for (; it != matrix[cur].end(); it++) {
		if (vst[it->first]) continue;
		vst[it->first] = true;
		dfs(it->first, dis + it->second, res + resouce[it->first]);
		vst[it->first] = false;
	}
}

int main() {
	// freopen("..\\input.txt", "r", stdin);
	cin >> N >> M >> C1 >> C2;
	resouce = vector<int>(N);
	matrix = vector<vector<pair<int, int> > >(N);
	for (int i = 0; i < N; i++) cin >> resouce[i];
	int c1, c2, d;
	while (M--) {
		cin >> c1 >> c2 >> d;
		matrix[c1].push_back(pair<int, int>(c2, d));
		matrix[c2].push_back(pair<int, int>(c1, d));
	}
	vst = vector<bool>(N, false);
	vst[C1] = true;
	dfs(C1, 0, resouce[C1]);
	cout << cnt << ' ' << maxr << endl;
}