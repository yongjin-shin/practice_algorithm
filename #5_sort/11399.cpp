//integer scope check

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int d[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	sort(d + 1, d + n + 1);

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cnt += d[j];
	}

	cout << cnt;


	return 0;
}