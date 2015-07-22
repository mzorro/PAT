#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N; cin >> N;
	auto lines = vector<string>(N);
	auto rbegs = vector<string::reverse_iterator>(N);
	auto rends = vector<string::reverse_iterator>(N);

	cin.get();
	while (N--) {
		getline(cin, lines[N]);
		rbegs[N] = lines[N].rbegin();
		rends[N] = lines[N].rend();
	}
	string suffix = "";
	bool flag = true;
	while (flag)
	{
		auto rbeg = rbegs.begin();
		auto rend = rends.begin();
		if (*rbeg == *rend) break;
		char tmp = *((*rbeg)++);

		for (rbeg++, rend++; rbeg != rbegs.end(); rbeg++, rend++) {
			if (*rbeg == *rend || tmp != *((*rbeg)++)) {
				flag = false;
				break;
			}
		}
		if (flag) suffix += tmp;
	}
	if (suffix == "") cout << "nai" << endl;
	else {
		for (auto rit = suffix.rbegin(); rit != suffix.rend(); rit++) {
			cout << *rit;
		}
		cout << endl;
	}
}