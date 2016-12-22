#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_INT 0x7fffffff

int main() {
    //freopen("..\\input.txt", "r", stdin);
    int N; cin >> N;
    vector<int> a(N), lmax(N);
    int m = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        lmax[i] = m;
        m = m > a[i] ? m : a[i];
    }
    m = MAX_INT;
    vector<int> res;
    for (int i = N-1; i >= 0; i--) {
        if (lmax[i] < a[i] && m > a[i])
            res.push_back(a[i]);
        m = m < a[i] ? m : a[i];
    }
    cout << res.size() << endl;
    if (!res.empty()) {
        vector<int>::reverse_iterator rit = res.rbegin();
        cout << *rit;
        for (rit++; rit != res.rend(); rit++) {
            cout << " " << *rit;
        }
    }
    cout << endl;
}
