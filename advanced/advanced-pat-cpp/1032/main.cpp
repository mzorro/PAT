#include <iostream>
#include <cstring>
#define MAXN 100000
using namespace std;

int nodes[MAXN];
int flags[MAXN];
int main() {
	memset(nodes, 0, sizeof(nodes));
	memset(flags, 0, sizeof(flags));
	int node1, node2, N;
	cin >> node1 >> node2 >> N;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		char c;
		cin >> n1 >> c >> n2;
		nodes[n1] = n2;
	}
	while (node1 != -1) {
		flags[node1]++;
		node1 = nodes[node1];
	}
	while (!flags[node2] && node2!=-1) {
		node2 = nodes[node2];
	}
	if (node2!=-1) {
		cout.width(5);
		cout.fill('0');
	}
	cout << node2 << endl;
}