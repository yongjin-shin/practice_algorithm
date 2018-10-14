#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct Pair{
  int x;
  int y;
};

const int MAX = 1001;
const int MIN = 1;
const Pair turn = {-1, -1};

int R = 0; int C = 0; int cnt = 0; int tot = 0;
int mp[MAX][MAX];
queue<Pair> q;

void print(){
  for(int i=MIN; i<=R; i++){
    for(int j=MIN; j<=C; j++)
      cout << mp[i][j];
    cout << endl;
  }
  cout << endl;
}


int main(){
  cin >> C >> R;
  int tmp = 0;

  for(int i = MIN; i<=R; i++){
    for(int j = MIN; j<=C; j++){
      Pair p = {i, j};
      cin >> tmp;
      mp[i][j] = tmp;
      if(1 == tmp){
        q.push(p);
      }else if(0 == tmp){
        tot += 1;
      }
    }
  }

  if(0 == tot){
    cout << 0;
    return 0;
  }

  q.push(turn);
  Pair there = {0, 0};

  while(1){
    // print();
    const Pair here = q.front();
    q.pop();

    if(here.x < 0){
      if(q.empty())
        break;

      cnt += 1;
      q.push(turn);
      continue;
    }

    //right
    if(here.y+1 <= C && mp[here.x][here.y+1] == 0){
      there.x = here.x; there.y = here.y+1;
      q.push(there);
      mp[here.x][here.y+1] = 1;
      tot -= 1;
    }

    //down
    if(here.x+1 <= R && mp[here.x+1][here.y] == 0){
      there.x = here.x+1; there.y = here.y;
      q.push(there);
      mp[here.x+1][here.y] = 1;
      tot -= 1;
    }

    //left
    if(MIN <= here.y-1 && mp[here.x][here.y-1] == 0){
      there.x = here.x; there.y = here.y-1;
      q.push(there);
      mp[here.x][here.y-1] = 1;
      tot -= 1;
    }

    //up
    if(MIN <= here.x-1 && mp[here.x-1][here.y] == 0){
      there.x = here.x-1; there.y = here.y;
      q.push(there);
      mp[here.x-1][here.y] = 1;
      tot -= 1;
    }
  }

  if(0 == tot){
    cout << cnt;
    return 0;
  }else{
    cout << -1;
    return 0;
  }

}
