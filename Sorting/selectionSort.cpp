 #include<iostream>
 using namespace std;
 
 void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[idx] > arr[j]){
                idx = j;
            }
        }
        swap(arr[idx],arr[i]);
    }
 }
 void deseorder(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int maxi = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]> arr[maxi]){
                maxi = j;
            }
        }
        swap(arr[maxi],arr[i]);
    }
 }

 void absdesc(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int maxi = i;
        for(int j=i+1;j<n;j++){
            if(abs(arr[j])> abs(arr[maxi])){
                maxi = j;
            }
        }
        swap(arr[maxi],arr[i]);
    }
 }
 int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // selectionSort(arr,n);
    // deseorder(arr,n);
    absdesc(arr,n);
    for (int i = 0; i < n; i++)
    {
       cout << arr[i] << " ";
    }
    cout << endl;
 }