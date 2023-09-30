#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int getMedian(int arr[],int start,int end){  //median of the elements of indexes b/w start , end (both included)
    int mid = (end-start+1)/2;
    sort(arr+start,arr+end+1);
    return arr[start+mid];
}

int MedofMeds(int arr[],int first,int n){     //first -- starting index , n -- length upto which we should operate starting from "first"
    int temp = (n/5)+1;                        
    int meds[temp];
    int end = first+n;
    for(int i=first;i<end;i+=5){
        int ind = (i-first)/5;
        if(i+4<end){
            meds[ind] = getMedian(arr,i,i+4);
        }
        else{
            meds[ind] = getMedian(arr,i,end-1);
        }
    }
    if(temp == 1){
        return meds[0];
    }
    return MedofMeds(meds,0,temp);
}

int Select(int arr[],int first,int last,int rank){  //first,last -- index range(both included) , rank -- no.of elements should be before the element.
    int pivot = MedofMeds(arr,first,(last-first+1));
    int i = first;
    int j = first;
    int piv_ind;
    
    while(i<=last){
        if(arr[i]>pivot){
            i++;
        }
        else if(arr[i] == pivot){
            piv_ind = i;
            i++;
        }
        else{
            swap(arr,i,j);
            if(j == piv_ind){
                piv_ind = i;
            }
            i++;
            j++;
        }

    }
    swap(arr,j,piv_ind);
    if(j==rank){
        return arr[j];
    }
    else if(j>rank){
        Select(arr,first,j-1,rank);
    }
    else{
        Select(arr,j+1,last,rank);
    }

}

int main(){
    int pos[] = {3,7,2,9,1,11,8,4,10,13,5,6};
    int n = sizeof(pos)/sizeof(pos[0]);
    cout<<Select(pos,0,n-1,n-1);
    return 0;
}