#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::pair;
using namespace std;

//map<int, bool> visited;

int explore(vector<vector<int> > &adj,map<int, bool> visited, int x){
  visited[x]=true;

  for(int i=0;i<adj[x].size();i++){


    if(!visited[adj[x][i]]){
      if(explore(adj, visited, adj[x][i])==0){
        return 0;
      }
    }
    else{
      return 0;
    }
  }
  return 1;
}

int acyclic(vector<vector<int> > &adj) {
  for(int i=0;i<adj.size();i++){
    map<int, bool> visited;
    if(explore(adj,visited,i)==0) return 1;
    
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
  }
  std::cout << acyclic(adj);
}
