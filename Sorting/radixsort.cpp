#include<iostream>
using namespace std;
void countSort(int arr[],int n,int pos){
     int count[10];
     for (int i = 0; i <10; i++)
     {
       count[i] = 0;
     }
     for (int i = 0; i < n; i++)
     {
        count[(arr[i]/pos)%10]++;
     }
     for(int i=1;i<10;i++){
      count[i] = count[i] + count[i-1];
     }
     int b[n];
     for (int i = n-1; i >=0; i--)
     {
        b[--count[(arr[i]/pos)%10]]  = arr[i];
     }
     for (int i = 0; i < n; i++)
     {
       arr[i] = b[i];
     }
}
void radixSort(int arr[],int n,int k){
  for(int pos = 1;k/pos > 0 ; pos = pos*10){
    countSort(arr,n,pos);
  }
}
int main(){
  int n;
  cin >> n;
  int arr[n];
  int k = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    /* code */
    cin >> arr[i];
    k = max(k,arr[i]);
  }
  radixSort(arr,n,k);
  for (int i = 0; i < n; i++)
  {
    /* code */
    cout << arr[i] << " ";
  }
  cout << endl;
}


