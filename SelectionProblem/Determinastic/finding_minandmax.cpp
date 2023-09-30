#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getMin(int arr[],int n){
    int mini = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<mini){
            mini = arr[i];
        }
    }
    return mini;
}

int getMax(int arr[],int n){
    int maxi = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}

pair<int,int> minandmax(int arr[],int n){
    int mi,ma;
    
    if(n%2 == 0){
        int s[n/2];
        int l[n/2];
        for(int i=0;i<n;i+=2){
            if(arr[i]<=arr[i+1]){
                s[i/2] = arr[i];
                l[i/2] = arr[i+1];
            }
            else{
                s[i/2] = arr[i+1];
                l[i/2] = arr[i];
            }
        }
        mi = getMin(s,n/2);
        ma = getMax(l,n/2);
    }
    else{
        int s[(n-1)/2];
        int l[(n-1)/2];
        for(int i=0;i<n-1;i+=2){
            if(arr[i]<=arr[i+1]){
                s[i/2] = arr[i];
                l[i/2] = arr[i+1];
            }
            else{
                s[i/2] = arr[i+1];
                l[i/2] = arr[i];
            }
        }
        mi = min(getMin(s,(n-1)/2),arr[n-1]);
        ma = max(getMax(l,(n-1)/2),arr[n-1]);
    }
    pair<int,int>p = {mi,ma};
    return p;
}

int main(){
    int arr[] = {1,5,7,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    pair<int,int>p = minandmax(arr,n);
    cout<<"mini : "<<p.first<<endl;
    cout<<"maxi : "<<p.second<<endl;
    return 0;
}