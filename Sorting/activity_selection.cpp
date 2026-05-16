#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
  return a.second < b.second;
}
int main(){
  int n;
  cin >> n;
  vector<int>v1(n);
  vector<int>v2(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v1[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> v2[i];
  }
  vector<pair<int,int>>v;
  for (int i = 0; i < n; i++)
  {
    v.push_back({v1[i],v2[i]});
  }
  sort(v.begin(),v.end(),compare);
  int count = 1;
  int lastEnd = v[0].second;
  for (int i = 1; i < v.size(); i++)
  {
    if(v[i].first >lastEnd){
      count++;
      lastEnd = v[i].second;
    }
  }
  cout << count << endl;
}

