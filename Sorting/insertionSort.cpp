 #include<iostream>
 using namespace std;
 
 void insertionSort(int arr[],int n){
   for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]%2==0 && arr[j-1]%2==0){
                  if(arr[j]<arr[j-1]){
                  swap(arr[j],arr[j-1]);
            }
            }
        }
       
      }
      for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]%2!=0 && arr[j-1]%2!=0){
                  if(arr[j]<arr[j-1]){
                  swap(arr[j],arr[j-1]);
            }
            }
        }
       
      }
 }

 void deseorder(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]>arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
 }
 void absasc(int arr[],int n){
     for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(abs(arr[j])>abs(arr[j-1])){
                swap(arr[j],arr[j-1]);
            }
        }
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
    insertionSort(arr,n);
    // deseorder(arr,n);
    // absasc(arr,n);
    for (int i = 0; i < n; i++)
    {
       cout << arr[i] << " ";
    }
    cout << endl;
 }

 