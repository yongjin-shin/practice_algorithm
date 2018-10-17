//생각을 하고 풀자…
//간단하게 풀 수 있는 방법…

#include <iostream>using namespace std;int n; int m; int p;int mp[51];int main(){	cin >> n >> m >> p;	for (int i = 1; i < n+1; i++) {		cin >> mp[i];	}	if (n == p && mp[n] >= m)		cout << -1;	else {		for (int i = 1; i < n + 1; i++) {			if (mp[i] <= m) {				cout << i;				return 0;			}		}		cout << n + 1;	}	return 0;}