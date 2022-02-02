#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::numeric_limits;

using namespace std;

const int inf = numeric_limits<int>::max();
typedef pair<int, int> iPair;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  priority_queue< iPair, vector <iPair> , greater<iPair> > q;
  map<int,int> dist;
  for(int i=0; i<adj.size();i++){
    dist[i]=inf;
  }
  dist[s]=0;
  q.push(make_pair(dist[s],s));
  while(!q.empty()){
    int v=q.top().second;
    q.pop();
    for(int i=0; i<adj[v].size(); i++){
      int u= adj[v][i]; 
      if(dist[u]>dist[v]+cost[v][i]){
        q.push(make_pair(dist[v]+cost[v][i],u));
        dist[u]=dist[v]+cost[v][i];
      }
    }
  }
  if(dist[t]==inf)
    return -1;
  return(dist[t]);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
