#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

int N, K;
vector<int> happiness;
map<string, int> lookup;
map<int, string> rlookup;
vector<vector<pair<int, int> > > matrix;

vector<int> dist, pre, maxhappy, averagehappy, pathcount;

int getAverageHappy(int city) {
	int count = 0;
	int happy = 0;
	while (city) {
		happy += happiness[city];
		city = pre[city];
		count++;
	}
	return happy / count;
}

void dijkstra(int src, int dst) {
	vector<bool> found = vector<bool>(N, false);
	dist[src] = 0;
	pathcount[src] = 1;
	int cur = src;
	while (!found[cur]) {
		found[cur] = true;
		vector<pair<int, int> >::iterator it = matrix[cur].begin();
		for (; it != matrix[cur].end(); it++) {
			if (dist[it->first] > dist[cur] + it->second) {
				pathcount[it->first] = pathcount[cur];
				dist[it->first] = dist[cur] + it->second;
				maxhappy[it->first] = maxhappy[cur] + happiness[it->first];
				pre[it->first] = cur;
				averagehappy[it->first] = getAverageHappy(it->first);
			} else if (dist[it->first] == dist[cur] + it->second) {
				pathcount[it->first] += pathcount[cur];
				if (maxhappy[it->first] < maxhappy[cur] + happiness[it->first]) {
					maxhappy[it->first] = maxhappy[cur] + happiness[it->first];
					pre[it->first] = cur;
					averagehappy[it->first] = getAverageHappy(it->first);
				} else if (maxhappy[it->first] == maxhappy[cur] + happiness[it->first]) {
					int old_pre = pre[it->first];
					pre[it->first] = cur;
					if (averagehappy[it->first] < getAverageHappy(it->first)) {
						averagehappy[it->first] = getAverageHappy(it->first);
					} else {
						pre[it->first] = old_pre;
					}
				}
			}
		}
		// choose cur
		int mind = MAX_INT;
		for (int j = 0; j < N; j++) {
			if (found[j]) continue;
			if (mind > dist[j]) {
				mind = dist[j];
				cur = j;
			}
		}
	}
}

void printPath(int dst) {
	stack<int> st;
	st.push(dst);
	while (dst) {
		dst = pre[dst];
		st.push(dst);
	}
	cout << rlookup[st.top()];
	st.pop();
	while (!st.empty()) {
		cout << "->" << rlookup[st.top()];
		st.pop();
	}
	cout << endl;
}

int main() {
	//freopen("..\\input.txt", "r", stdin);
	cin >> N >> K;
	happiness = vector<int>(N);
	matrix = vector<vector<pair<int, int> > >(N, vector<pair<int, int> >());
	string origin;
	cin >> origin;
	lookup[rlookup[0] = origin] = 0;
	for (int i = 1; i < N; i++) {
		string city; int h;
		cin >> city >> h;
		happiness[lookup[rlookup[i] = city] = i] = h;
	}
	while (K--) {
		string from, to;
		int cost;
		cin >> from >> to >> cost;
		matrix[lookup[from]].push_back(make_pair(lookup[to], cost));
		matrix[lookup[to]].push_back(make_pair(lookup[from], cost));
	}
	dist = vector<int>(N, MAX_INT);
	pre = vector<int>(N, 0);
	maxhappy = vector<int>(N, 0);
	averagehappy = vector<int>(N, 0);
	pathcount = vector<int>(N, 0);
	int rom = lookup["ROM"];
	dijkstra(0, rom);
	cout << pathcount[rom] << ' ';
	cout << dist[rom] << ' ';
	cout << maxhappy[rom] << ' ';
	cout << averagehappy[rom] << endl;
	printPath(rom);
}