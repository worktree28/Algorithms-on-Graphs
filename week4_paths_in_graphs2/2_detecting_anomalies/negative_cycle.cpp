#include <iostream>
#include <vector>
#include <map>
#include <limits>

using std::vector;
using namespace std;

const int inf=numeric_limits<int>::max();

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  map<long long,long long> dist;
  for(int i=0; i<adj.size();i++){
    dist[i]=inf;
  }
  dist[adj.size()-1]=0;
  int count=0;
  int size=adj.size();
  for(int x=0;x<size;x++){
    int flag=0;
    for(int i=adj.size()-1; i>=0;i--){
      int v=dist[i];
      if(v==inf){
        continue;
      }
      for(int j=0; j<adj[i].size();j++){
        if(dist[adj[i][j]]>cost[i][j]+v && (cost[i][j]+v) < inf){
          dist[adj[i][j]]=cost[i][j]+v;
          flag=1;
          if(x == adj.size() - 1) return 1;
        }
      }
    }
 
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n+1, vector<int>());
  vector<vector<int> > cost(n+1, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  for(int i=0; i<n+1;i++){
    adj[n].push_back(i);
    cost[n].push_back(1);
  }
  //cout<<n<<' '<<adj.size();
  std::cout << negative_cycle(adj, cost);
}
