#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

int calc_sum(vector<int> &seq, int beg, int end) {
	int sum = 0;
	while (beg <= end) sum += seq[beg++];
	return sum;
}

int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N; cin >> N;
	vector<int> seq(N);
	for (int i = 0; i < N; i++) cin >> seq[i];
	int beg = 0, end = 0;
	int maxsum = -1, maxbeg, maxend;
	while (end < N) {
		int sum = calc_sum(seq, beg, end);
		if (sum > maxsum) {
			maxbeg = beg;
			maxend = end;
			maxsum = sum;
		} else if (sum < 0) {
			beg = end + 1;
			end = beg - 1;
		}
		end++;
	}
	if (maxsum >= 0) cout << maxsum << ' ' << seq[maxbeg] << ' ' << seq[maxend] << endl;
	else cout << 0 << ' ' << seq[0] << ' ' << seq[N-1] << endl;
}