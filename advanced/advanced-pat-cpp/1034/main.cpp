#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int N, K;
map<string, map<string, int> > mmap;
typedef map<string, map<string, int> >::iterator mmapit;
typedef map<string, int>::iterator mapit;
void insert_to_map(string &a, string &b, int &m) {
	for(int i=0; i<2; a.swap(b), i++) {
		mmapit ait = mmap.find(a);
		if (ait != mmap.end()) {
			mapit it = ait->second.find(b);
			if (it != ait->second.end()) {
				it->second += m;
			} else {
				ait->second[b] = m;
			}
		} else {
			mmap[a] = map<string, int>();
			mmap[a][b] = m;
		}
	}
}

void dfs(set<string> &gang, string start) {
	gang.insert(start);
	mapit it = mmap[start].begin();
	while (it!=mmap[start].end()) {
		if (gang.find(it->first)==gang.end()) {
			dfs(gang, it->first);
		}
		++it;
	}
}

string check_gang(set<string> &gang) {
	int total_sum = 0;
	int max_sum = -1;
	string head;
	set<string>::iterator it;
	for (it = gang.begin(); it!=gang.end(); ++it)  {
		int sum = 0;
		mapit mit = mmap[*it].begin();
		while (mit!=mmap[*it].end()) {
			sum += (mit++)->second;
		}
		if (max_sum == -1 || sum > max_sum) {
			max_sum = sum;
			head = *it;
		}
		total_sum += sum;
	}
	if (total_sum / 2 > K) {
		return head;
	} else {
		return "";
	}
}

struct Gang {
	string head;
	int count;
	Gang(string head, int count)
		: head(head), count(count) {}

	bool operator<(const Gang &g) const {
		return head < g.head;
	}
};

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string a, b; int m;
		cin >> a >> b >> m;
		insert_to_map(a, b, m);
	}
	set<string> vsted;
	set<Gang> gangs;
	mmapit it;
	for (it = mmap.begin(); it!=mmap.end(); ++it) {
		if (vsted.find(it->first)!=vsted.end()) continue;
		set<string> gang;
		dfs(gang, it->first);
		set<string>::iterator git = gang.begin();
		while (git!=gang.end()) {
			vsted.insert(*(git++));
		}
		if (gang.size() < 3) continue;
		string head = check_gang(gang);
		if (!head.empty()) {
			gangs.insert(Gang(head,gang.size()));
		}
	}
	cout << gangs.size() << endl;
	set<Gang>::iterator git;
	for (git = gangs.begin(); git!=gangs.end(); ++git) {
		cout << git->head << ' ' << git->count << endl;
	}
}