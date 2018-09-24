#include <iostream>
#include <vector>
using namespace std;

/**
what I struggled
1. Deepest First! Breadth First!
2. passing address made it harder..
3. Should consider to use "Constant"...
**/

struct Point{
  int row;
  int col;
};

void make_map(int map[][50], int bae){
  for(int j=0; j<bae; j++){
    int row = 0; int col = 0;
    cin >> col >> row;
    map[row][col] = 1;
  }
}

void draw_map(int map[][50], int col, int row){
  for(int i = 0; i<row; i++){
    for(int j = 0; j<col; j++){
      cout << map[i][j] << " ";
    }
    cout << endl;
  }
}

bool check_grid(int i, int j, int col, int row){
  if(i<0 || j<0 || i>=row || j>=col)
    return false;
  return true;
}

void dfs(int map[][50], int i , int j, int col, int row){
  vector<Point> v;
  Point tmp = {i, j};
  v.push_back(tmp);

  while(v.size() > 0){
    tmp = v.back();
    map[tmp.row][tmp.col] = 0;
    // draw_map(map, col, row);
    // cout << "ROW: " << tmp.row << endl;
    // cout << "COL: " << tmp.col << endl;
    // draw_map(map, col, row);
    v.pop_back();

    //east
    if(check_grid(tmp.row, tmp.col+1, col, row) && map[tmp.row][tmp.col+1] == 1){
      Point copy = tmp;
      copy.col += 1;
      map[copy.row][copy.col] = 0;
      v.push_back(copy);
    }

    //south
    if(check_grid(tmp.row+1, tmp.col, col, row) && map[tmp.row+1][tmp.col] == 1){
      Point copy = tmp;
      copy.row += 1;
      map[copy.row][copy.col] = 0;
      v.push_back(copy);
    }

    //north
    if(check_grid(tmp.row-1, tmp.col, col, row) && map[tmp.row-1][tmp.col] == 1){
      Point copy = tmp;
      copy.row -= 1;
      map[copy.row][copy.col] = 0;
      v.push_back(copy);
    }

    //west
    if(check_grid(tmp.row, tmp.col-1, col, row) && map[tmp.row][tmp.col-1] == 1){
      Point copy = tmp;
      copy.col -= 1;
      map[copy.row][copy.col] = 0;
      v.push_back(copy);
    }
  }

  return;
}

int count_map(int map[][50], int col, int row){
  int cnt = 0;

  for(int i = 0; i<row; i++){
    for(int j = 0; j<col; j++){
      if(map[i][j] == 1){
        dfs(map, i, j, col, row);
        cnt++;
        // cout << "Cnt is " << cnt << endl;
        // draw_map(map, col, row);
      }
    }
  }

  return cnt;
}

int main(){
  int N = 0;
  cin >> N;
  vector<int> result;

  int col = 0; int row = 0; int bae = 0;
  for(int i = 0; i<N; i++){
    col = 0; row = 0; bae = 0; int cnt = 0;
    int map[50][50] = {};

    cin >> col >> row >> bae;
    make_map(map, bae);
    // draw_map(map, col, row);
    // cout << endl << endl;
    cnt = count_map(map, col, row);
    // draw_map(map, col, row);
    result.push_back(cnt);
  }

  for(vector<int>::iterator it = result.begin() ; it != result.end(); ++it)
    cout << *it << endl;

  return 0;
}
