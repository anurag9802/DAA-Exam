#include <bits/stdc++.h>
using namespace std;


int partitionRight(int arr[],int low,int high) {
    // int pivot=a[high];
    // int k=low-1;
    // for(int i=low;i<high;i++){
    //     if(a[i]<pivot){
    //         k++;
    //         swap(a[k],a[i]);
    //     }            
    // }
    // swap(a[high],a[k+1]);
    // return (k+1);

    int pivot=arr[low];
    int i=low,j=high+1;
    while(i<j) {
        do{
            i++;
        }while(i<=j && arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
   
    
}

void QuickSort(int a[],int low,int high) {

    if(high>low) {
        int pi=partitionRight(a,low,high);

        QuickSort(a,low,pi-1);
        QuickSort(a,pi+1,high);
    }
    
}


// 0 1 2 3 4 5 6 7

int main() {
    cout<<"Enter size of array : ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter numbers : ";
    for(int i=0;i<n;i++)
        cin>>a[i];

    QuickSort(a,0,n-1);

    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    
    

    return 0;
}