#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

struct Stu {
	char name[5];
	int id;

	bool operator<(const Stu &stu) const {
		return strcmp(name, stu.name) < 0;
	}
};

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int NS, NC;
	//cin >> NS >> NC;
	scanf("%d%d", &NS, &NC);
	vector<Stu> stu(NS);
	vector<vector<int> > courses(NC);
	int N, c;
	for (int i = 0; i < NS; i++) {
		//cin >> stu[i].name >> N;
		scanf("%s%d", stu[i].name, &N);
		while (N--) {
			//cin >> c;
			scanf("%d", &c);
			courses[c-1].push_back(stu[i].id = i);
		}
	}
	sort(stu.begin(), stu.end());
	for (int i = 0; i < NC; i++) {
		//cout << i + 1 << ' ' << courses[i].size() << '\n';
		printf("%d %d\n", i+1, courses[i].size());
		vector<int>::iterator it;
		vector<bool> buf(NS, false);
		for (it=courses[i].begin(); it!=courses[i].end(); it++) {
			buf[*it] = true;
		}
		for (int i = 0; i < NS; i++) {
			if (buf[stu[i].id]) {
				//cout << stu[i].name << '\n';
				printf("%s\n", stu[i].name);
			}
		}
	}
}