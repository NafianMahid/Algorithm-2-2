 #include<iostream>
 using namespace std;
 
 void bubbleSort(int arr[],int n){
   for(int i=n-1 ; i>=0;i--){
       int flag = 0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
      }
 }

 void deseorder(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=0;j<=n-i;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
 }

 void absdesc(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=0;j<=n-i;j++){
            if(abs(arr[j])<abs(arr[j+1])){
                swap(arr[j],arr[j+1]);
            }
            if(abs(arr[j])==abs(arr[j+1])){
                if(arr[j+1]>arr[j]){
                    swap(arr[j],arr[j+1]);
                }
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
    // bubbleSort(arr,n);
    // deseorder(arr,n);
    absdesc(arr,n);
    for (int i = 0; i < n; i++)
    {
       cout << arr[i] << " ";
    }
    cout << endl;
 }

 