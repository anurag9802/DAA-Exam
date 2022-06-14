#include <bits/stdc++.h>
using namespace std;

class Pair {
    public:
    int min;
    int max;
};



Pair maxmin(int a[],int low,int high) {
    Pair minmax;
    if(low==high){
        minmax.max=a[low];
        minmax.min=a[low];
        return minmax;
    }
    else if(high-low==1) {
        minmax.min=min(a[low],a[high]);
        minmax.max=max(a[low],a[high]);
        return minmax;
    }
    int mid=(low+high)/2;
    Pair left=maxmin(a,low,mid);
    Pair right=maxmin(a,mid+1,high);

    minmax.max=max(left.max,right.max);
    minmax.min=min(left.min,right.min);
    return minmax;
}


int main() {
    cout<<"Enter size of array : ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter numbers : ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    Pair ans=maxmin(a,0,n-1);

    printf("Largest Element : %d\n Smallest Element : %d",ans.max,ans.min); 


    return 0;
}