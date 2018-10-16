#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int target = 100;
int man[9];
vector<int> myman;

bool search(int root, int tot){
  myman.push_back(man[root]);
  int new_tot = man[root] + tot;

  if(new_tot > target || myman.size() > 7){
    myman.pop_back();
    return false;
  }else if(new_tot == target && myman.size() == 7){
    return true;
  }

  for(int i = root+1; i<9; i++){
    if(search(i, new_tot))
      return true;
  }

  myman.pop_back();
  return false;
};

int main(){
  for(int i = 0; i<9; i++){
    cin >> man[i];
  }

  sort(man, man+9);
  for(int i = 0; i<=2; i++){
    if(search(i, 0))
      break;
  }

  for(vector<int>::iterator it=myman.begin(); it != myman.end(); it++)
    cout << *it << endl;

  return 0;
}
