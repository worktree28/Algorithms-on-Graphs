#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::pair;
using namespace std;

map<int, bool> visited;


int reach(vector<vector<int> > &adj, int x, int y) {
  visited[x]=true;

  for(int i=0;i<adj[x].size();++i){
    if(visited[adj[x][i]]==true) continue;
    else{
      //cout<<x<<" "<<y<<"\n";
      if(adj[x][i]==y)  return 1;
      if(reach(adj,adj[x][i],y)) return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}



