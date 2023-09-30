#include<iostream>
using namespace std;
void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void quicksort(int arr[],int first,int last){
    if(first>=last){
        return ;
    }
    int pivot;
    cout<<"Select your pivot in [ "<<first<<" , "<<last-1<<" ] : ";
    if(first == last-1){
        pivot = first;
        cout<<pivot<<endl;
    }
    else{
        cin>>pivot;
    }
    
    if(pivot<last and pivot>=first){
        int i=first;
        int j=first;
        int piv_index = pivot;
        while(i<last){
            if(arr[i] < arr[piv_index] and j!=piv_index){
                swap(arr,i,j);
                i++;
                j++;
            }
            else if(arr[i]>=arr[piv_index]){
                i++;
            }
            else if(arr[i] < arr[piv_index] and j==piv_index){
                swap(arr,i,j);
                piv_index = i;
                i++;
                j++;
            }
        }
        swap(arr,piv_index,j);
        quicksort(arr,0,j);
        quicksort(arr,j+1,last);
    }
    else{
        cout<<"Enter A valid Pivot"<<endl;
        quicksort(arr,first,last);
    }
    

}


int main(){
    int arr[] = {1,6,3,4,1};
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,arr_len);
    for(int p=0;p<arr_len;p++){
        cout<<arr[p]<<endl;
    }
    return 0;
}
