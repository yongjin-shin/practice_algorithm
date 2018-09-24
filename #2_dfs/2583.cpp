#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[100][100] = {};
int visit[100][100] = {};

void draw_map(int map[][100], int row, int col);
void creat_map(int map[][100], int K);
int dfs(int i, int j, int row, int col, int cnt);
bool waytosort(int i, int j){return i < j;};

int main(){
  int row = 0; int col = 0; int K = 0; int cnt = 0; vector<int> v;
  cin >> row >> col >> K;
  creat_map(map, K);
  // draw_map(map, row, col);

  for(int i = 0; i<row; i++){
    for(int j = 0; j<col; j++){
      if(map[i][j] != 1 && visit[i][j] != 1){
        cnt = dfs(i, j, row, col, 0);
        v.push_back(cnt);
        // draw_map(visit, row, col);
      }
    }
  }

  sort(v.begin(), v.end(), waytosort);
  cout << v.size() << endl;
  for(vector<int>::iterator it=v.begin(); it != v.end(); ++it)
    cout << *it << " ";
  return 0;
}

int dfs(int i, int j, int row, int col, int cnt){
  if(map[i][j] != 1 && visit[i][j] != 1){
    if(i<0 || j<0 || i>=row || j>=col){
      return cnt;
    }
    else{
      visit[i][j] = 1;
      cnt += 1;
      cnt = dfs(i, j+1, row, col, cnt);
      cnt = dfs(i+1, j, row, col, cnt);
      cnt = dfs(i-1, j, row, col, cnt);
      cnt = dfs(i, j-1, row, col, cnt);
      return cnt;
    }
  }
  return cnt;
};
void creat_map(int map[][100], int K){
  for(int k = 0; k<K; k++){
    int r1, c1, r2, c2;
    cin >> c1 >> r1 >> c2 >> r2;
    for(int i = r1; i<r2; i++){
      for(int j = c1; j<c2; j++){
        map[i][j] = 1;
      }
    }
  }
};
void draw_map(int map[][100], int row, int col){
  for(int i = 0; i<row; i++){
    for(int j=0; j<col; j++)
      cout << map[i][j] << " ";
    cout << endl;
  }
};
