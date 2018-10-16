// case 작은걸로 간단하게 작동 테스트 해볼 것!
// backtracking은 원래 내가 하는 방식대로 하면 덜 헷갈림;;

#include <iostream>
using namespace std;

int N;
int arr[8];
int ck[8];
int best = 0;

int cal(int a, int b) {
	int tmp = 0;
	tmp = a - b;
	if (tmp < 0)
		tmp = tmp * -1;

	return tmp;
};

void search(int depth, int prev, int root, int sum) {

	int new_sum = 0;
	ck[root] = 1;
	if (depth > 1) {
		new_sum = sum + cal(arr[prev], arr[root]);
	}

	if (depth == N) {
		if (new_sum >= best) {
			best = new_sum;
		}
		ck[root] = 0;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (ck[i] == 0)
			search(depth + 1, root, i, new_sum);
	}

	ck[root] = 0;
	return;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		ck[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		search(1, 0, i, 0);
	}

	cout << best;

	return 0;
}
