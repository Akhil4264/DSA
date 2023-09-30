#include<iostream>
using namespace std;

int getMax(int arr[],int n){
    int maxi = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}

void countSort(int arr[],int n,int exp){
    int out[n] = {0};
    int pos[10] = {0};
    for(int i=0;i<n;i++){
        int temp = arr[i]/exp;
        pos[temp%10]++;
    }
    int sum = n;
    for(int i=9;i>=0;i--){
        pos[i] = sum - pos[i];
        sum = pos[i];
    }
    for(int i=0;i<n;i++){
        int temp = arr[i]/exp;
        out[pos[temp%10]] = arr[i];
        pos[temp%10]++;
    }
    for(int i=0;i<n;i++){
        arr[i] = out[i];
    }
}

void radixsort(int arr[],int n){
    int m = getMax(arr,n);
    for(int exp = 1;m/exp>=1;exp*=10){
        countSort(arr,n,exp);
    }  
}

int main(){
    int arr[] = {4,1,3,2,3,15};
    radixsort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}