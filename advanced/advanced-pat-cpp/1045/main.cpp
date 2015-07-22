#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int color_weight[201];
int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	memset(color_weight, 0, sizeof(color_weight));
	int N, color;
	cin >> N >> N;
	while (N--) {
		cin >> color;
		color_weight[color] = N + 1;
	}
	vector<int> stripe;
	cin >> N;
	while (N--) {
		cin >> color;
		if (color_weight[color] > 0) {
			stripe.push_back(color_weight[color]);
		}
	}
	N = stripe.size();
	vector<int> length(N, 1);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (stripe[i] <= stripe[j]) {
				length[i] = max(length[i], length[j] + 1);
			}
		}
	}
	int max_length = 0;
	for (int i = 0; i < N; i++) {
		max_length = max(max_length, length[i]);
	}
	cout << max_length << endl;
}