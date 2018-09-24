#include <iostream>
#include <vector>
using namespace std;

vector<int> net[1000];
vector<int> visit;
void dfs(int);
bool exist(int);

int main(){
  int N, p; int cnt = 0;
  cin >> N >> p;

  for(int i = 0; i<p; i++){
    int n1, n2;
    cin >> n1 >> n2;
    net[n1-1].push_back(n2-1);
    net[n2-1].push_back(n1-1);
  }

  for(int i = 0; i<N; i++){
    if(!exist(i)){
      cnt++;
      visit.push_back(i);
      dfs(i);
    }
  }

  cout << cnt;

  return 0;
}

void dfs(int start){
  vector<int> s = net[start];
  for(vector<int>::iterator it=s.begin(); it!=s.end(); ++it){
    if(!exist(*it)){
      visit.push_back(*it);
      dfs(*it);
    }
  }
}

bool exist(const int node){
  for(vector<int>::iterator it=visit.begin(); it!=visit.end(); ++it)
    if(node == *it) return true;
  return false;
}
