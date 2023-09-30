#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int QuickSelect(int arr[],int first,int last,int rank){
    if(rank<=last){
        int piv_ind;
        cout<<"Enter a pivot from the range [ "<<first<<" , "<<last<<" ] : ";
        cin>>piv_ind;
        if(piv_ind>=first and piv_ind<=last){
            int i=first;
            int j=first;
            while(i<=last){
                if(arr[i]>=arr[piv_ind]){
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
            if(j == rank){
                return arr[j];
            }
            else if(j>rank){
                QuickSelect(arr,first,j-1,rank);
            }
            else if(j<rank){
                QuickSelect(arr,j+1,last,rank);
            }
        }
        else{
            QuickSelect(arr,first,last,rank);
        }
    }
}

int main(){
    int arr[] = {1,5,7,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int rank = 4;
    cout<<QuickSelect(arr,0,n-1,rank)<<endl;
    return 0;
}