#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
int t; int n;
pair<int, int> d[100001];
int cnt;
int pr;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> d[j].second >> d[j].first;
		}

		cnt = 0;
		pr = n+1;
		sort(d + 1, d + n + 1);
		for (int j = 1; j <= n; j++) {
			if (pr > d[j].second) {
				cnt++;
				pr = d[j].second;
			}
			if (d[j].second == 1)
				break;
		}

		cout << cnt << endl;
	}


	return 0;
}
