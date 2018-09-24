#include <iostream>
#include <vector>
using namespace std;

vector<int> net[100];
vector<int> visit;
void dfs(int start);
bool exist(int);

int main(){
  int N = 0; int p = 0;
  cin >> N;
  cin >> p;

  for(int i = 0; i<p; i++){
    int c1, c2;
    cin >> c1 >> c2;
    net[c1-1].push_back(c2-1);
    net[c2-1].push_back(c1-1);
  }

  visit.push_back(0);
  dfs(0);
  cout << visit.size()-1;

  // cout << endl;
  // for(vector<int>::iterator it = visit.begin(); it !=visit.end(); ++it)
  //   cout << *it << " ";
  return 0;
}

void dfs(int start){
  vector<int> s = net[start];
  for(vector<int>::iterator it = s.begin(); it!=s.end(); ++it){
    int node = *it;
    if(!exist(node)){
      visit.push_back(node);
      dfs(node);
    }
  }
  return;
}

bool exist(const int node){
  for(vector<int>::iterator it = visit.begin(); it !=visit.end(); ++it)
    if(node == *it)
      return true;

  return false;
}
