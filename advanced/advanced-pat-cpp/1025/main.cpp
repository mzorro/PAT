#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Entry {
	string id;
	int score;
	int location;

	Entry(int location)
		: location(location) {
		cin >> id >> score;
	}

	bool operator<(const Entry &entry) const {
		if (this->score == entry.score)
			return this->id < entry.id;
		else
			return this->score > entry.score;
	}
};

int main() {
	int N;
	cin >> N;
	set<Entry> ranklist;
	for (int loc = 1; loc <= N; loc++)	 {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			ranklist.insert(Entry(loc));
		}
	}
	cout << ranklist.size() << endl;
	vector<int> ranks = vector<int>(N+1);
	vector<int> eqcnt = vector<int>(N+1);
	vector<int> lasts = vector<int>(N+1, -1);
	set<Entry>::iterator it;
	for (it=ranklist.begin(); it!=ranklist.end(); it++) {
		if (it->score == lasts[0]) {
			eqcnt[0]++;
		} else {
			ranks[0] += 1 + eqcnt[0];
			eqcnt[0] = 0;
			lasts[0] = it->score;
		}
		int loc = it->location;
		if (it->score == lasts[loc]) {
			eqcnt[loc]++;
		} else {
			ranks[loc] += 1 + eqcnt[loc];
			eqcnt[loc] = 0;
			lasts[loc] = it->score;
		}
		cout << it->id << ' ' << ranks[0] << ' '
			<< loc << ' ' << ranks[loc] << endl;
	}
}