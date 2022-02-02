#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>
#include <limits>

using std::vector;
using namespace std;

const double inf = numeric_limits<double>::max();
typedef pair<int, int> iPair;

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

double minimum_distance(vector<int> x, vector<int> y) {
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
  for( int i =0; i<edges.size();i++){
    
    edge current_edge = edges[i];
    int u = current_edge.u;
    int v = current_edge.v;
    //cout<<result<<' '<<'\n';
    if(parent(set,u)!=parent(set,v)){
      result+=current_edge.weight;

      //cout<<a.first<<' '<<a.second<<' '<<endl;
      join(set,u,v);
    }

  }

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
/*
5
0 0
0 2
1 1
3 0
3 2
*/