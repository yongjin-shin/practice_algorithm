#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int MAX = 1000000;
int n; int m;
pair<int, int> h[2500];
pair<int, int> c[13];
pair<int, int> ch[13];
int tmp;
int num_h=0;
int num_c=0;
int best = MAX;
int score = 0;
int ch_dist;
int tot_dist;

int dist(pair<int, int> a, pair<int, int> b) {
	int x = a.first - b.first;
	int y = a.second - b.second;

	if (x < 0)
		x = x * -1;
	if (y < 0)
		y = y * -1;

	return (x + y);
}

int calc() {
	tot_dist = 0;

	for (int i = 0; i < num_h; i++) {
		ch_dist = MAX;
		for (int j = 0; j < m; j++) {
			tmp = dist(ch[j], h[i]);
			if (ch_dist >= tmp)
				ch_dist = tmp;
		}
		tot_dist += ch_dist;
	}

	return tot_dist;
}

void search(int root, int depth) {
	if (depth == m) {
		score = calc();
		if (best >= score)
			best = score;
		return;
	}

	for (int i = root; i < num_c; i++) {
		ch[depth] = c[i];
		search(i+1, depth+1);
	}
};

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			if (0 == tmp)
				continue;
			else if (1 == tmp) {
				h[num_h] = { i, j };
				num_h++;
			}
			else {
				c[num_c] = { i, j };
				num_c++;
			}
		}
	}

	search(0, 0);
	cout << best;


	return 0;
}
