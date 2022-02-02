#include <bits/stdc++.h>

using std::vector;
using std::pair;
using namespace std;

const int maxn=100000;
int dfs(int src, vector<vector<int> > adj, vector<int> &visited)
{
    visited[src]=1;
    for(auto it : adj[src])
    {
        if(visited[it]==0)
        {
            dfs(it,adj,visited);
        }
    }
}
int main() {
    vector<int> A {1,1,1,3,3,2,2,7,6};

    int B=2;
    int C=8;
    int n=A.size();
    vector<vector<int> > adj(n+1, vector<int>());
    vector<int> visited(n);
  
    for(int i=0;i<n;i++)
    {
        adj[A[i]-1].push_back(i);
    }
  
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    dfs(C-1,adj,visited);
    int ans=visited[B-1];
    cout<<ans;
    return ans;
}