#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int graph[100][100],n,coloring[100];   

public:
    int count=0;
    Graph(int m)
    {
        n = m;  
        for(int i=0;i<n;i++)
            coloring[i]=-1; 
        count=0;    
    }
    void input()
    {
        cout << "Enter graph in adjacency matrix form :\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
    }
    void printSol() {
        count++;
        for(int i=0;i<n;i++)
            cout<<coloring[i]<<" ";
        cout<<endl;
    }
    
    bool isSafe() {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && graph[i][j]!=0 && coloring[i]==coloring[j])
                    return false;
            }
        }
        return true;
    }
    void mcoloring(int k,int m) {
        if(k==n) {
            if(isSafe())
                printSol();
            return;
        }
        for(int i=1;i<=m;i++) {
            coloring[k]=i;
            mcoloring(k+1,m);
            coloring[k]=-1;
        }
        
    }   
};

int main()
{

    cout << "Enter Number of Vertices : ";
    int n,m;
    cin >> n;
    Graph ob(n);
    cout<<"Enter no of colors : ";
    cin>>m;
    
    ob.input();
    cout<<"Colorings of the graph :  \n";
    ob.mcoloring(0,m);
    if(ob.count==0)
        cout<<"NO SOLUTION EXISTS";
    

    return 0;
}