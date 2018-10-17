#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n; int s; int e;
int cnt = 0;
pair<int, int> tb[100001];

int main(){
	cin >> n;

	for (int i = 1; i < n+1; i++) {
		cin >> s >> e;
		tb[i] = { e, s };
	}

	int ch = 0;
	sort(tb + 1, tb + n + 1);
	for (int i = 1; i < n+1; i++) {
		if (tb[i].second >= ch) {
			ch = tb[i].first;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
