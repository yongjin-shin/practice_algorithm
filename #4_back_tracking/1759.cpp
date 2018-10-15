// sort algorithm 확인하기
// char 알파벳 확인하기
// pair 함수 확인하기

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int L=0; int C=0;
char mp[15];
int vow[15];
int cnt_vow = 0;
int cnt_cont = 0;
vector <char> v;

// void swap(pair<char, int>& a, pair<char, int>& b){
//
// }


void tracking(int root){
  if(L-v.size() > C-root)
    return;

  if(L == v.size()){
    if(cnt_vow >=1 && cnt_cont >=2){
      for(vector<char>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it;
      cout << endl;
    }
    return;
  }

  for(int i = root; i<C; i++){
    if(vow[i] == 0)
      cnt_cont++;
    else
      cnt_vow++;

    v.push_back(mp[i]);
    tracking(i+1);
    char t = v.back();
    v.pop_back();

    if(t == 'a' || t == 'e' || t == 'i' || t == 'o' ||  t == 'u')
      cnt_vow--;
    else
      cnt_cont--;
  }
  return;
}

int main(){
  cin >> L >> C;
  char tmp;
  for(int i = 0; i < C; i++){
    cin >> tmp;
    mp[i] = tmp;
  }

  sort(mp, mp+C);
  for(int i = 0; i<C; i++){
    if(mp[i] == 'a' || mp[i] == 'e' || mp[i] == 'i' || mp[i] == 'o' ||  mp[i] == 'u'){
      vow[i] = 1;
    }else{
      vow[i] = 0;
    }
  }

  tracking(0);

  return 0;
}
