#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

bool cmp(char a1, char a2) {
	return a1 > a2;
}

void int2char(int numi, char *numc) {
	int i = 4;
	numc[i--] = 0;
	while (numi) {
		numc[i--] = numi % 10 + '0';
		numi /= 10;
	}
	while (i>=0) numc[i--] = '0';
} 

int char2int(char *numc) {
	return numc[0] * 1000 + numc[1] * 100 + numc[2] * 10 + numc[3];
}

void output(int numi) {
	char numc[5];
	int2char(numi, numc);
	cout << numc << endl;
}

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int numi; cin >> numi;
	do {
		char numc1[5], numc2[5];
		int2char(numi, numc1);
		memcpy(numc2, numc1, 5);
		sort(numc1, numc1+4, cmp);
		sort(numc2, numc2+4);
		int numi1 = char2int(numc1);
		int numi2 = char2int(numc2);
		cout << numc1 << " - " << numc2 << " = ";
		numi = numi1 - numi2;
		output(numi);
	} while (numi!=0 && numi != 6174);
}