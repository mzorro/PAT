#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff
int N, M, K, Ds;

int toNumber(string s) {
	int tmp, res = 0;
	if (s[0] == 'G') { res += N; s.erase(s.begin()); }
	istringstream sin(s);
	sin >> tmp;
	res += tmp;
	return res;
}

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	cin >> N >> M >> K >> Ds;
	vector<pair<int,int>> *matrix = new vector<pair<int,int>>[N+M+1];
	string p1, p2;
	int i1, i2, dist;
	while (K--) {
		cin >> p1 >> p2 >> dist;
		i1 = toNumber(p1);
		i2 = toNumber(p2);
		matrix[i1].push_back(pair<int, int>(i2, dist));
		matrix[i2].push_back(pair<int, int>(i1, dist));
	}
	
	int chosed = -1, mind, maxd, sumd;
	for (int i = 1; i <= M; i++) {
		int cur = N + i;
		vector<int> mindist(N+M+1, MAX_INT);
		vector<bool> visit(N+M+1, false);
		mindist[cur] = 0;
		for (int j = 1; j <= N+M; j++) {
			visit[cur] = true;
			vector<pair<int,int>>::iterator it = matrix[cur].begin();
			for (; it != matrix[cur].end(); it++) {
				if (!visit[it->first] &&
					mindist[it->first] > mindist[cur] + it->second)
					mindist[it->first] = mindist[cur] + it->second;
			}
			cur = -1;
			for (int k = 1; k <= N+M; k++) {
				if (visit[k]) continue;
				if (cur < 0 || mindist[k] < mindist[cur]) cur = k;
			}
		}
		int tmp_mind = MAX_INT, tmp_maxd = 0, tmp_sumd = 0;
		for (int k = 1; k <= N; k++) {
			if (tmp_mind > mindist[k]) tmp_mind = mindist[k];
			if (tmp_maxd < mindist[k]) tmp_maxd = mindist[k];
			tmp_sumd += mindist[k];
		}
		if (tmp_maxd <= Ds &&
			(chosed < 0 || tmp_mind > mind ||
			(tmp_mind == mind && tmp_sumd < sumd))) {
			chosed = i;
			mind = tmp_mind;
			maxd = tmp_maxd;
			sumd = tmp_sumd;
		}
	}
	delete[] matrix;
	if (chosed < 0) cout << "No Solution" << endl;
	else {
		cout << 'G' << chosed << endl;
		cout.precision(1);
		cout << fixed << (float)mind << ' ' << ((float)sumd) / N << endl;
	}
}