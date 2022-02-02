#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;
using namespace std; 

struct edge {
  int u;
  int v;
  double weight;
  
  edge(int a, int b, double c) {
    u = a;
    v = b;
    weight = c;
  }
};

bool cmp(edge a, edge b) {
  return a.weight < b.weight;
}

int parent(vector<int> &set, int i){
  if(set[i]==i)  return i;
  else return(parent(set, set[i]));
}

void join(vector<int> &set, int u, int v ){
  int i1=parent(set, u);
  int i2=parent(set, v);
  set[i1]=i2;
}

double clustering(vector<int> x, vector<int> y, int k) {
  double result = 0.0;
  int size=x.size();
  vector<int> set(size);
  vector <edge> edges;
  for(int i=0; i<size; i++){
    set[i]=i;
  }
  vector<vector<double> > dist(size, vector<double>());
  for(int i=0; i<size;i++){
    for(int j=i+1;j<size;j++){
      edges.push_back(edge(i,j,( sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2)))));
    }
  }
  sort(edges.begin(),edges.end(),cmp);
  int count=0;
  for( int i =0; i<edges.size();i++){
    
    edge current_edge = edges[i];
    int u = current_edge.u;
    int v = current_edge.v;
    //cout<<result<<' '<<'\n';
    if(parent(set,u)!=parent(set,v)){
      count++;
      //cout<<a.first<<' '<<a.second<<' '<<endl;
      join(set,u,v);
    }
    if(count>size-k){
      return current_edge.weight;
    }
  }

  return -1.;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(12) << clustering(x, y, k) << std::endl;
}
