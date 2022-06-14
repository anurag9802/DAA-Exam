#include <bits/stdc++.h>
using namespace std;



void sort_descending(double ratio[],int val[],int wt[],int n) {
    
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(ratio[j]<ratio[j+1]){
                swap(val[j],val[j+1]);
                swap(wt[j],wt[j+1]);
                swap(ratio[j],ratio[j+1]);
                      
            }
        }
    }

}




int main() {
    int n;
    cout<<"Enter size of Knapsack"<<endl;
    cin>>n;
    int val[n],wt[n];
    cout<<"Enter value"<<endl;
    for(int i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter weight"<<endl;
    for(int i=0;i<n;i++)
        cin>>wt[i];

    double ratio[n];
    for(int i=0;i<n;i++) 
        ratio[i]=val[i]/wt[i];

    int capacity=0;
    cout<<"enter capacity"<<endl;
    cin>>capacity;

    sort_descending(ratio,val,wt,n);
    
    double ans=0.0;

    for(int i=0;i<n;i++) {
        if(capacity-wt[i]>=0) {
        capacity=capacity-wt[i];
        ans=ans+val[i];
        }
        else {
            ans=ans +  ((double)capacity/wt[i])*val[i] ;
            break;
        }
    }
    cout<<"Max possible value = "<<ans;
    





    return 0;
}