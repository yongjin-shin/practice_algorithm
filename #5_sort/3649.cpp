//integer scope check

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
const int UNIT = 10000000;
int n; int t;
int d[1000001];

int main() {
	int i; int j; int k;
	int f; int s; int best;

	while (cin >> t) {
		cin >> n;
		t = t * UNIT;
		for (k = 1; k <= n; k++) {
			cin >> d[k];
		}

		sort(d + 1, d + n + 1);
		int l = 1; int r = n;
		while (l < r){
			
			if (d[l] + d[r] > t)
				r--;

			else if(d[l] + d[r] < t)
				l++;

			if (d[l] + d[r] == t && l != r)
			{
				cout << "yes " << d[l] << " " << d[r] << endl;
				break;
			}
		}
		if (l >= r)
			cout << "danger" << endl;
	}

	return 0;
}