#include<iostream>
#include <climits>
using namespace std;
void countSort(int arr[],int n,int k){
    int count[k+1];
     for(int i = 0; i <= k; i++) {
        count[i] = 0;
    }
    for(int i = 0;i < n; i++){
        count[arr[i]]++;
    }
    for(int i = 1;i <= k;i++){
        count[i] = count[i-1] + count[i];
    }
    int temp[n];
    for(int i = n-1;i>=0;i--){
        temp[--count[arr[i]]]= arr[i];
    }
    for(int i =0;i<n;i++){
        arr[i] = temp[i];
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    int k = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        k = max(k,arr[i]);
    }
    countSort(arr,n,k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

