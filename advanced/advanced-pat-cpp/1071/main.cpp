#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	string str;
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for (unsigned i = 0; i < str.length(); i++) {
		if (!((str[i] >= '0' && str[i] <= '9') ||
			  (str[i] >= 'a' && str[i] <= 'z'))) {
			str[i] = ' ';
		}
	}
	unsigned beg = 0, count, maxcount = 0;
	string maxword;
	map<string, unsigned> mmap;
	unsigned i = 0;
	while (i < str.length()) {
		while (i < str.length() && str[i] == ' ') i++;
		if ((beg = i) >= str.length()) break;
		while (i < str.length() && str[i] != ' ') i++;
		string word(str.substr(beg, i-beg));
		if (mmap.find(word) == mmap.end()) {
			count = mmap[word] = 1;
		} else {
			count = ++mmap[word];
		}
		if (maxcount < count || 
			(maxcount == count && word < maxword)) {
				maxcount = count;
				maxword = word;
		}
	}
	cout << maxword << ' ' << maxcount << endl;
}