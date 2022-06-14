#include <bits/stdc++.h>
using namespace std;




void heapifyy(int a[],int n,int i) {
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && a[left]>a[largest])
        largest=left;
    if(right < n && a[right]>a[largest])
        largest=right;

    if(i!=largest){
        swap(a[i],a[largest]);
        heapifyy(a,n,largest);
    }
}

void heapSort(int a[],int n) {
    
    
    for(int i=0;i<n/2 - 1;i++)
        heapifyy(a,n,i);
    
    for(int i=n-1;i>0;i--){
        swap(a[i],a[0]);
        heapifyy(a,i,0);
    }
    
}

int main() {
    cout<<"Enter size of array : ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter numbers : ";
    for(int i=0;i<n;i++)
        cin>>a[i];

    heapSort(a,n);

    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    
    

    return 0;
}