// 2D array를 만들어서 neighbourhood matrix를 구성하자
// 방문했던 곳들도 array로 index 검색해서 바로바로 찾을 수 있게
// DFS는 root를, BFS는 queue를 사용할 것.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N = 0;
int p = 0;
int box[1001][1001] = {};
vector<int> visited;
int check[1001] = {};

void DFS(int root){
  for(int i = 1; i<N+1; i++){
    if(box[root][i] && check[i] == 0){
      check[i] = 1;
      visited.push_back(i);
      DFS(i);
    }
  }
}

void print(){
  for(vector<int>::iterator it = visited.begin(); it != visited.end(); it++){
    cout << *it << " ";
  }
}

int main(){
  int start =0;
  cin >> N >> p >> start;

  for(int i = 0; i < p; i++){
    int in1 = 0; int in2 = 0;
    cin >> in1 >> in2;
    box[in1][in2] = 1;
    box[in2][in1] = 1;
  }

  check[start] = 1;
  visited.push_back(start);
  DFS(start);
  print();

  cout << endl;
  visited.clear();

  queue<int> q;
  q.push(start);
  check[start] = 10;
  while(!q.empty()){
    int root = q.front();
    q.pop();
    visited.push_back(root);
    for(int i = 1; i<N+1; i++){
      if(box[root][i] && 10 > check[i]){
        check[i] = 10;
        q.push(i);
      }
    }
  }
  print();



  return 0;
}
