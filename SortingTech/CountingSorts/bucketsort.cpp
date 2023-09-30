#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


void BucketSort(float arr[],int n){
    vector<float> b[n];
    for(int i=0;i<n;i++){
        int temp = n*arr[i];
        b[temp].push_back(arr[i]);        
    }
    int index = 0;
    for(int i=0;i<n;i++){
        sort(b[i].begin(),b[i].end());
        if(b[i].size()>=1){
            for(int j=0;j<b[i].size();j++){
                arr[index] = b[i][j];
                index++;
            }
        }
    }
}

int main(){
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    BucketSort(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}