#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning(disable:4996)

void toUpper(string &s) {
	for (int i = 0; i < s.length(); i++)
		s[i] = toupper(s[i]);
}

int main() {
	//freopen("..\\input.txt", "r", stdin);
	string s1, s2;
	cin >> s1 >> s2;
	toUpper(s1);
	toUpper(s2);
	int i1 = 0, i2 = 0;
	string missing = "";
	while (i1 < s1.length() && i2 < s2.length()) {
		if (s1[i1] != s2[i2]) {
			if (missing.find(s1[i1]) == string::npos)
				missing += s1[i1];
			i1++;
		} else {
			i1++, i2++;
		}
	}
	while (i1 < s1.length()) {
		if (missing.find(s1[i1]) == string::npos)
			missing += s1[i1];
		i1++;
	}
	cout << missing << endl;
}