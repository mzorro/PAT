#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

inline void swap(int &a, int &b) {
	a ^= b ^= a ^= b;
}

int N;
#define FORN(b, i) for (int i = b; i < N; i++)

bool eq(vector<int> &v1, vector<int> &v2) {
	FORN(0, i) if (v1[i] != v2[i]) return false;
	return true;
}

void print(const char *msg, vector<int> &v) {
	cout << msg << endl;
	cout << v[0];
	FORN(1, i) cout << " " << v[i];
	cout << endl;
}

bool found = false;

void insertionSortStep(vector<int> &tmp, int i) {
	int j = i, t = tmp[i];
	while (--j >= 0 && tmp[j] > t) {
		tmp[j+1] = tmp[j];
	}
	tmp[j+1] = t;
}

void insertionSort(vector<int> &src, vector<int> &dst) {
	vector<int> tmp(src);
	FORN(1, i) {
		insertionSortStep(tmp, i);
		if (eq(tmp, dst)) {
			found = true;
		} else if (found) {
			print("Insertion Sort", tmp);
			return;
		}
	}
}

#define LEFT(i)     (2*i+1)
#define RIGHT(i)    (LEFT(i)+1)
void heapify(vector<int> &tmp, int len, int i) {
	int l = LEFT(i), r = RIGHT(i), m = i;
	if (l < len && tmp[l] > tmp[m]) m = l;
	if (r < len && tmp[r] > tmp[m]) m = r;
	if (m == i) return;
	swap(tmp[i], tmp[m]);
	heapify(tmp, len, m);
}

void buildHeap(vector<int> &tmp, int len) {
	for (int i = len/2 - 1; i >= 0; i--)
		heapify(tmp, len, i);
}

void heapSort(vector<int> &src, vector<int> &dst) {
	vector<int> tmp(src);
	int headsize = N;
	buildHeap(tmp, headsize);
	while (headsize > 0) {
		swap(tmp[0], tmp[--headsize]);
		heapify(tmp, headsize, 0);
		if (eq(tmp, dst)) {
			found = true;
		} else if (found) {
			print("Heap Sort", tmp);
			return;
		}
	}
}

int main() {
	//freopen("..\\input.txt", "r", stdin);
	cin >> N;
	vector<int> src(N), dst(N);
	FORN(0, i) cin >> src[i];
	FORN(0, i) cin >> dst[i];
	insertionSort(src, dst);
	if (!found) heapSort(src, dst);
}
