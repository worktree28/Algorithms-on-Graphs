#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::pair;
using namespace std;

map<int, bool> visited;
void explore(vector<vector<int> > &adj,int x){
  visited[x]=true;
  for(int i=0;i<adj[x].size();i++){
    if(!visited[adj[x][i]])
      explore(adj,adj[x][i]);
  }
}
int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  for(int i=0;i<adj.size();i++){
    if(!visited[i]){
      explore(adj,i);
      res++;
    }
    
    
    
  }
  return res;
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
  std::cout << number_of_components(adj);
}
