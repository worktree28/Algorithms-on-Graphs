#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, int &result, int x) {
  for(int i=0;i<adj[x].size();i++){
    if(used[adj[x][i]]==0){
      used[adj[x][i]]=1;
      dfs(adj, used, result, adj[x][i]);
    }
    else{
      result++;
      return;
    }
  }
}     

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
