#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)

struct Node {
	int value;
	int pre, next;
} link[100005];

void print(int addr, int value, int next) {
	if (next != -1) {
		printf("%05d %d %05d\n", addr, value, next);
	} else {
		printf("%05d %d %d\n", addr, value, next);
	}
}

int main() {
	// freopen("..\\input.txt", "r", stdin);
	int head, N, K;
	cin >> head >> N >> K;
	int addr, value, next;
	while (N--) {
		cin >> addr >> value >> next;
		link[addr].value = value;
		link[addr].next = next;
	}
	int pre(-1), beg(head), cur(head), k(0);
	bool first(true);
	while (cur != -1) {
		link[cur].pre = pre;
		if (++k == K) {
			k = 0;
			if (first) {
				first = false;
				head = cur;
			}
			int pr = link[beg].pre;
			if (pr != -1) link[pr].next = cur;
			int nt = link[cur].next;
			int p = cur;
			while (p != beg) {
				link[p].next = link[p].pre;
				link[link[p].pre].next = p;
				p = link[p].pre;
			}
			link[beg].next = nt;
			cur = beg;
			beg = link[beg].next;
		}
		pre = cur;
		cur = link[cur].next;
	}
	while (head != -1) {
		print(head, link[head].value, link[head].next);
		head = link[head].next;
	}
}