#include <bits/stdc++.h>
using namespace std;


void sort_descending(int profit[],int deadline[],char id[],int n) {
    
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(profit[j]<profit[j+1]){
                swap(id[j],id[j+1]);
                swap(deadline[j],deadline[j+1]);
                swap(profit[j],profit[j+1]);
                      
            }
        }
    }

}

int main() {
    int n;
    cout<<"enter no of jobs"<<endl;
    cin>>n;
    int deadline[n],profit[n];
    cout<<"Enter Profit"<<endl;
    for(int i=0;i<n;i++)
        cin>>profit[i];
    cout<<"Enter deadline"<<endl;
    for(int i=0;i<n;i++)
        cin>>deadline[i];

    char id[n];
    for(int i=0;i<n;i++) 
        id[i]=(char)(97+i);

    sort_descending(profit,deadline,id,n);

    char ans[n];

    for(int i=0;i<n;i++) 
         ans[i]='0';
    
    int maxProfit=0;
    for(int i=0;i<n;i++) {

        for(int j=min(n,deadline[i])-1;j>=0;j--) {
            if(ans[j]=='0'){
                ans[j]=id[i];
                maxProfit+=profit[i];
                break;
            }
        }
    }
    cout<<"Order of Jobs is : \n";
    for(int i=0;i<n;i++) 
        if(ans[i]!='0')
        cout<<ans[i]<<" ";
    cout<<"\nProfit = "<<maxProfit;
    return 0;
}