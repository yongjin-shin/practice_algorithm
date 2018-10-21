#include "pch.h"
#include <iostream>
#include <utility>
using namespace std;
int row; int col;
int mp[10][10];
int ch[10][10];
int c[8][3];
int cc = 0; int wall = 0; int tot = 0; int best = 100000;
int mode[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //mode: 0-right, 1-down, 2-left, 3-up

void calc() {
	tot = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (ch[i][j] < 0)
				tot++;
		}
	}
}

void move(int r_row, int r_col, int md, int plus) {
	int old_ch;
	while (1) {
		r_row = r_row + mode[md][0];
		r_col = r_col + mode[md][1];
		if (mp[r_row][r_col] == 6)
			break;
		old_ch = ch[r_row][r_col];
		ch[r_row][r_col] += plus;
		if (old_ch * ch[r_row][r_col] == 0) {
			if (plus < 0)
				tot--;
			else
				tot++;

		}
		if (tot == 0)
			break;
	}
}

void check(int root, int md, int clean) {
	if (c[root][2] == 1) {
		move(c[root][0], c[root][1], md, clean);
	}
	else if (c[root][2] == 2) {
		move(c[root][0], c[root][1], md, clean);
		move(c[root][0], c[root][1], (md+2)%4, clean);
	}
	else if (c[root][2] == 3) {
		move(c[root][0], c[root][1], md, clean);
		move(c[root][0], c[root][1], (md+1)%4, clean);
	}
	else if (c[root][2] == 4) {
		move(c[root][0], c[root][1], md, clean);
		move(c[root][0], c[root][1], (md+1)%4, clean);
		move(c[root][0], c[root][1], (md+2)%4, clean);

	}
	else if (c[root][2] == 5) {
		move(c[root][0], c[root][1], 0, clean);
		move(c[root][0], c[root][1], 1, clean);
		move(c[root][0], c[root][1], 2, clean);
		move(c[root][0], c[root][1], 3, clean);
	}
}

void search(int root) {
	if (root == cc) {
		if (best >= tot)
			best = tot;
		return;
	}

	for (int i = root; i < cc; i++) {
		for (int j = 0; j < 5; j++) {
			check(i, j, -1);
			if (tot == 0)
				return;
			search(i + 1);
			check(i, j, 1);//clean
			if (tot == 0)
				return;
		}
	}
}

int main() {
	cin >> row >> col;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mp[i][j] = 6;
			ch[i][j] = 0;
		}
	}

	int in;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> in;
			mp[i][j] = in;

			if (5 >= in && in >= 1) {
				c[cc][0] = i; c[cc][1] = j; c[cc][2] = in;
				cc++;
				tot++;
			}
			else if (in == 6)
				wall++;
			else
				tot++;
		}
	}
	search(0);

	best = tot;
	cout << best;


	return 0;
}