#include <bits/stdc++.h>
using namespace std;


void merge(int a[],int l,int m,int r) {

    int n1=m-l+1,n2=r-m;
    int left[n1];
    int right[n2];
    
    for(int i=0;i<n1;i++)
        left[i]=a[l+i];
    for(int i=0;i<n2;i++)
        right[i]=a[m+1+i];
    
    int k=l,p1=0,p2=0;

    while(p1<n1 && p2<n2) {
        if(left[p1]<=right[p2])
            a[k++]=left[p1++];
        else
            a[k++]=right[p2++];
    }
    
        while(p1<n1)
            a[k++]=left[p1++];
    
    
        while(k<n2)
            a[k++]=right[p2++];
    
}

void mergeSort(int a[],int low,int high) {
    if(high>low) {
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);

        merge(a,low,mid,high);
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

    mergeSort(a,0,n-1);

    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    
    

    return 0;
}