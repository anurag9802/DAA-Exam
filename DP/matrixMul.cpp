#include <bits/stdc++.h>
using namespace std;


int matrixMul(int p[],int n) {
    int m[n][n];
    int s[n][n];

    for(int i=0;i<n;i++) {
        m[i][i]=0;
        s[i][i]=0;
    }

    int min,j,q;

    for(int d=1;d<n-1;d++) {
        for(int i=1;i<n-d;i++) {
            j=i+d;
            min=INT_MAX;
            for(int k=i;k<j;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<min) {
                    min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }
    return m[1][n-1];
}

int main() {
    cout<<"Enter size of array : ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter numbers : ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    cout<<"Ans : "<<matrixMul(a,n);

    
    
    

    return 0;
}