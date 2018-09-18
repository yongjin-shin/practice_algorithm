#include <iostream>
using namespace std;

int reset(bool flag){
  if(flag){
    return 0;
  }
  exit(0);
}

int main(){
  int N = 0;
  int num_row = 0;
  int num_col = 0;

  string tmp;
  cin >> N;
  char box[N][N];

  for(int i=0; i<N; i++){
    cin >> tmp;
    int empty = 0;

    for(int j=0; j<N; j++){
        box[i][j] = tmp[j];
        if('X' == tmp[j]){
          if(empty >= 2){
            num_row += 1;
          }
          empty = reset(true);
        }
        if('.' == tmp[j]) empty += 1;
    }
    if(empty >= 2){
      num_row += 1;
    }
  }

  for(int i = 0; i<N; i++){
    int empty = 0;
    for(int j=0; j<N; j++){
      if('X' == box[j][i]){
        if(empty >= 2){
          num_col += 1;
        }
        empty = reset(true);
      }
      if('.' == box[j][i]) empty += 1;
    }
    if(empty >= 2){
      num_col += 1;
    }
  }


  cout << num_row << " " << num_col << endl;
  return 0;
}
