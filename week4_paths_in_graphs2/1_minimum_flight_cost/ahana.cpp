#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include<climits>
using namespace std;
 
int steps(vector<int> v1, int key){
    int ans1=0;
    int expected1 = key*v1.size();
    //int expected2 = key*v2.size();
    for(int i=0;i<v1.size();i++){
        ans1 = ans1 + v1[i];
    }
    int extra = max(expected1, ans1) - min(expected1, ans1);
 
    return extra;
}
 
int helpFunc(vector<int> v){
    int key =0;
    for(int i=0;i<v.size();i++){
        key = key+v[i];
    }
    int n = v.size();
    if(key%n!=0)
        return -1;
 
    
    key = key/v.size();
    int max_steps = INT_MIN;
    for(int i=1;i<v.size();i++){
        vector<int> v1(v.begin(),v.begin()+i);
 
        max_steps = max(steps(v1, key), max_steps);
    }
 
    return max_steps;
}
 
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    
    cout<<helpFunc(v);
}