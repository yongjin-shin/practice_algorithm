#include <iostream>
#include <string>
using namespace std;

int to_num(char color){
  switch (color) {
    case 'R':
      return 0;

    case 'B':
      return 1;

    case 'Y':
      return 2;

    case 'G':
      return 3;

    default:
      exit(-1);
  }
}

int get_max(int row[]){
  cout << "get_max is called" << endl;
  for(int i=9; i>=0;i--){
    if(row[i] == 1) return i;
  }
  exit(-1);
}

int is_seq(int row[]){
  cout << "is_seq called" << endl;
  int num = 0;
  int button = 0;
  int i = 0;
  for(i = 0; i<9; i++){
    if(row[i] >= 1){
      num += 1;
      button = 1;
    }

    if(5==num)
      return i;

    if(row[i] == 0 && button){
      return 0;
    }
  }
  return button;
}

int test(int t[][10]){
  // case 1 or 5
  cout << "case 1 or 5" << endl;
  int seq = is_seq(t[4]);
  cout << "seq: " << seq << endl;
  if(seq){
    for(int i =0; i<4; i++){
      if(t[i][9] == 5)
        return seq + 1 + 900;
    }
    return seq + 1 + 500;
  }

  // case 4
  cout << "case 4" << endl;
  for(int i =0; i<4; i++){
    if(t[i][9] == 5){
      return get_max(t[4]) + 1 + 600;
    }
  }

  cout << "case 2,3,6,7,8" << endl;
  for(int i = 0; i<9; i++){
    // case 2
    if(t[4][i] == 4)
      return i + 1 + 800;

    // case 3 or 6
    if(t[4][i] == 3){
      for(int j=i+1; j<9; j++){
        if(t[4][j] == 2)
          return (i+1)*10 + (j+1) + 700;
      }
      return i + 1 + 400;
    }

    // case 3 & 7 & 8
    if(t[4][i] == 2){
      for(int j=i+1; j<9; j++){
        if(t[4][j] == 3)
          return (j+1)*10 + i+1 + 700;

        if(t[4][j] == 2)
          return (j+1)*10 + i+1 + 300;
      }
      return (i+1)+200;
    }
  }

  // None
  return get_max(t[4])+1 + 100;
}

int main(){
  int score = 0;
  char col; int num;
  int tble[5][10] = { };
  string input;

  for(int i = 0; i<5; i++){
    cin >> col >> num;
    int row = to_num(col);
    tble[row][num-1] = 1;
    tble[row][9] += 1;
    tble[4][num-1] += 1;
  }

  for(int i = 0; i<5; i++){
    for(int j = 0; j<10; j++){
      cout << tble[i][j] << " ";
    }
    cout << endl;
  }

  score = test(tble);

  cout << score << endl;
  return 0;
}
