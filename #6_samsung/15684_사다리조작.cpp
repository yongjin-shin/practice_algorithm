#include <iostream>
#include <utility>
using namespace std;
int c; int r; int m; int mp[31][11];
pair<int, int> e[400]; int e_cnt=0; pair<int, int> tmp;
int t1, t2; int best = 10000;

bool find() {
	for (int i = 1; i <= c; i++) {
		int col = i;
		for (int j = 1; j <= r; j++) {
			if (mp[j][col - 1] == 1)
				col = col - 1;
			else if (mp[j][col] == 1)
				col = col + 1;
		}
		if (col != i)
			return false;
	}

	return true;
}

void search(int root, int cnt) {
	if (cnt >= 3) {
		if (find()) {
			best = cnt;
			return;
		}
		else
			return;
	}else {
		if (find()) {
			if (best >= cnt) {
				best = cnt;
				return;
			}
		}
	}

	for (int i = root; i < e_cnt; i++) {
		tmp = e[i];
		int rr = tmp.first; int cc = tmp.second;
		if (mp[rr][cc] == 0 && mp[rr][cc-1] != 1 && mp[rr][cc+1] != 1) {
			mp[rr][cc] = 1;
			search(root + 1, cnt+1);
 			mp[rr][cc] = 0;
		}
	}

	return;
}

int main() {
	cin >> c >> m >> r;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 11; j++) {
			mp[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		mp[t1][t2] = 1;
		mp[t1][t2 - 1] = -1;
		mp[t1][t2 + 1] = -1;
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j < c; j++) {
			if (mp[i][j] == 0) {
				e[e_cnt].first = i;
				e[e_cnt].second = j;
				e_cnt++;
			}
		}
	}

	search(0, 0);
	if (best > 3)
		cout << -1;
	else
		cout << best;

	return 0;
}
