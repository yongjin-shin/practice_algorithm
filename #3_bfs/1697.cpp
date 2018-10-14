// 한번 갔던 길을 다시 돌아가면 loop 무한 반복하게 됨.
// BFS에서는 메모리 초과!

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
int N = 0; int T = 0;
int mp[MAX+1] = {};
int tt = 0;

int main(){
  cin >> N >> T;

  queue<int> q;
  q.push(N);
  mp[N] = 1;
  q.push(-1);
  while(!q.empty()){
    int n = q.front();
    q.pop();
    if(n < 0){
      tt += 1;
      q.push(-1);
      continue;
    }

    if(n == T){
      cout << tt;
      return 0;
    }

    if(0<=n-1 and mp[n-1] != 1){
      q.push(n-1);
      mp[n-1] = 1;
    }

    if(n+1<=MAX and mp[n+1] != 1){
      q.push(n+1);
      mp[n+1] = 1;
    }

    if(2*n<=MAX and mp[2*n] != 1){
      q.push(2*n);
      mp[2*n] = 1;
    }
  }

}
