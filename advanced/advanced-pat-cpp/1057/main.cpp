#include <iostream>
#include <stack>
#include <set>
#include <functional>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	stack<int> stk;
	multiset<int, greater<int> > lowers;
	multiset<int> uppers;
	char cmd[11];
	int n, mid = 0;
	while (N--) {
		scanf("%s", cmd);
		switch(cmd[1]) {
		case 'u': // push
			scanf("%d", &n);
			stk.push(n);
 			if (n > mid) {
				uppers.insert(n);
			} else {
				lowers.insert(n);
			}
			if (lowers.size() < uppers.size()) {
				lowers.insert(*uppers.begin());
				uppers.erase(uppers.begin());
			} else if (lowers.size() > uppers.size() + 1){
				uppers.insert(*lowers.begin());
				lowers.erase(lowers.begin());
			}
			mid = *lowers.begin();
			break;
		case 'o': // pop
			if (stk.empty()) {
				printf("Invalid\n");
			} else {
				n = stk.top();
				printf("%d\n", n);
				stk.pop();
				if (n > mid) {
					uppers.erase(uppers.find(n));
				} else {
					lowers.erase(lowers.find(n));
				}
				if (stk.empty()) {
					mid = 0;
				} else {
					if (lowers.size() < uppers.size()) {
						lowers.insert(*uppers.begin());
						uppers.erase(uppers.begin());
					} else if (lowers.size() > uppers.size() + 1) {
						uppers.insert(*lowers.begin());
						lowers.erase(lowers.begin());
					}
					mid = *lowers.begin();
				};
			}
			break;
		case 'e': // peekMedian
			if (stk.empty()) {
				printf("Invalid\n");
			} else {
				printf("%d\n", mid);
			}
			break;
		}
	}
}