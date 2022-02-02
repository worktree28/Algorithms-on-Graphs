#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  map<int,int> dist;
  for(int i=0;i<adj.size();i++){
    dist[i]=100;
  }
  dist[s]=0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int v=q.front();
    q.pop();
    for(int i=0; i<adj[v].size(); i++){
      int u= adj[v][i]; //0 1 2 3
      if(dist[u]==100){
        q.push(u);
        dist[u]=dist[v]+1;
      }
    }
  }
  if(dist[t]!=100){
    return dist[t];
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
