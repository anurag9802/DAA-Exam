#include <bits/stdc++.h>
using namespace std;

class Graph {

    int graph[100][100],n;
    public:
    void input() {
        FILE *fp;
        fp=fopen("fw.txt","r");
        fscanf(fp,"%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                fscanf(fp,"%d",&graph[i][j]);
    }
    void makeArray() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                if(graph[i][j]==0)
                    graph[i][j]=INT_MAX;
            }
        }
    }

    void flyofWarshal() {

        for(int k=0;k<n;k++) {
            
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX && graph[i][j]>graph[k][j]+graph[i][k])
                        graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
        printSol();
        
    }

    void printSol() {
        cout<<"All Pair shortest Path is : \n";
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(i==j)
                cout<<"0\t";
                else if(graph[i][j]==INT_MAX)
                cout<<"INF\t";
                else
                cout<<graph[i][j]<<"\t";
            }
            cout<<endl;
        }
    }

};

int main() {

    
    Graph ob;
    ob.input();
    ob.makeArray();
    ob.flyofWarshal();
    return 0;
}