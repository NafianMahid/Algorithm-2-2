#include<iostream>
#include<vector>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){

  int n;
  cin >> n;
  vector<long long>v1;
  vector<long long>v2;
  for (int i = 0; i < n; i++)
  {
    long long x;
    cin >> x;
    v1.push_back(x);
  }
  for (int i = 0; i < n; i++)
  {
    long long y;
    cin >> y;
    v2.push_back(y);
  }
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  long long sum = 0;
  for(int i = 0; i<n; i++){
    sum+=v1[i]*v2[n-i-1];
  }
  cout << sum << endl;
  }
} 