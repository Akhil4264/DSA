#include<iostream>
using namespace std;

void countingsort(int arr[],int n,int k){
    int out[n];
    int pos[k] = {0};
    int sum = n;
    for(int i=0;i<n;i++){
        pos[arr[i]]++;
    }
    for(int i=k-1;i>=0;i--){
        pos[i] = sum - pos[i];
        sum = pos[i];
    }
    
    for(int i=0;i<n;i++){
        out[pos[arr[i]]] = arr[i];
        pos[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        arr[i] = out[i];
    }
    
}


int main(){
    int arr[] = {4,1,3,2,3};
    countingsort(arr,5,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}