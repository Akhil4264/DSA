#include <iostream>
using namespace std;

void merge(int arr[],int first,int mid,int last){
    int le = mid-first;
    int ri = last-mid;
    int left[le];
    int right[ri];
    for(int i=first;i<mid;i++){
        left[i-first] = arr[i];
    }
    for(int i=mid;i<last;i++){
        right[i-mid] = arr[i];
    }
    int i=0;
    int j=0;
    int k=first;
    while(i<le and j<ri){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }else{
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while(i<le){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<ri){
        arr[k] = right[j];
        k++;
        j++;
    }
}


void mergesort(int arr[],int n,int first){
    int last = n;
    int mid = (last+first)/2;
    if(first == mid){
        return ;  
    }
    mergesort(arr,mid,0);
    mergesort(arr,last,mid);
    merge(arr,first,mid,last);
}



int main(){
    int arr[] = {1,6,3,4,1};
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,arr_len,0);
    for(int p=0;p<arr_len;p++){
        cout<<arr[p]<<endl;
    }
    return 0;
}
