#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[],int n,int i){
    int left = 2*i+1;
    int right = 2*i+2;
    if(right<n){
        if(max(arr[left],arr[right]) == arr[left] and arr[left]>arr[i]){
            swap(arr,i,left);
        }
        else if(max(arr[left],arr[right]) == arr[right] and arr[right]>arr[i]){
            swap(arr,i,right);
        }
    }
    else if(right > n and left< n and arr[left]>arr[i]){
        swap(arr,i,left);
    }

}

void heapsort(int arr[],int n){
    if(n==1){
        return ;
    }
    for(int i=n/2 -1;i>=0;i--){
        heapify(arr,n,i);
    }
    swap(arr,0,n-1);
    heapsort(arr,n-1);
}

int main(){
    int arr[] = {4,1,6,7,3};
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,arr_len);
    for(int i=0;i<arr_len;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}